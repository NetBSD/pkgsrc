/***************************************************************************
 * CVSID: $Id: hal-file-monitor.c,v 1.1 2008/11/25 23:10:23 jmcneill Exp $
 *
 * hal-file-monitor.c: Kqueue-based file monitor
 *
 * Copyright (C) 2007 Joe Marcus Clarke <marcus@FreeBSD.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 **************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/stat.h>

#include <glib.h>
#include <glib/gi18n.h>
#include <glib/gstdio.h>
#include <glib-object.h>

#include "../hal-file-monitor.h"

#define HAL_FILE_MONITOR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), HAL_TYPE_FILE_MONITOR, HalFileMonitorPrivate))

#define VN_NOTE_CHANGED (NOTE_WRITE | NOTE_EXTEND | NOTE_ATTRIB | NOTE_LINK)
#define VN_NOTE_DELETED (NOTE_DELETE | NOTE_REVOKE)
#define VN_NOTE_ALL     (VN_NOTE_CHANGED | VN_NOTE_DELETED | NOTE_RENAME)

typedef struct
{
  char *path;
  int omask;
  gboolean isdir;
  HalFileMonitorNotifyFunc func;
  gpointer udata;
  GHashTable *dir_contents;
} FileKqueueData;

typedef struct
{
  char *path;
  time_t atime;
  gboolean owner;
  HalFileMonitorNotifyFunc func;
  gpointer udata;
} FileAccessData;

struct HalFileMonitorPrivate
{
  int kqueue_fd;
  guint io_watch;
  guint access_source;

  gboolean initialized_kqueue;

  GHashTable *fd_to_kdata;
  GHashTable *fd_to_adata;
};

G_DEFINE_TYPE (HalFileMonitor, hal_file_monitor, G_TYPE_OBJECT)

static gpointer monitor_object = NULL;

static void hal_file_monitor_finalize (GObject *object);
static GHashTable *get_dir_contents (const char *path);
static GHashTable *diff_dir_contents (FileKqueueData *data, GSList **added, GSList **removed);
static int hal_mask_to_kmask (int mask);
static void monitor_release_kdata (HalFileMonitor *monitor, int fd, FileKqueueData *data);
static void monitor_release_adata (HalFileMonitor *monitor, int fd, FileAccessData *data);
static gboolean remove_kdata_foreach (gpointer fd, FileKqueueData *data, HalFileMonitor *monitor);
static gboolean remove_adata_foreach (gpointer fd, FileAccessData *data, HalFileMonitor *monitor);
static void hal_file_monitor_remove_kdata (HalFileMonitor *monitor, guint id);
static void hal_file_monitor_remove_adata (HalFileMonitor *monitor, guint id);
static void setup_monitor (HalFileMonitor *monitor);
static void close_monitor (HalFileMonitor *monitor);
static gboolean hal_file_access_monitor (gpointer data);
/*static char *fflags_to_str (int fflags);*/
static void emit_monitor_event (HalFileMonitor *monitor, HalFileMonitorEvent event, const char *path, HalFileMonitorNotifyFunc func, gpointer udata);
static gboolean handle_kqueue_event (GIOChannel *source, GIOCondition condition, gpointer udata);

GQuark
hal_file_monitor_error_quark (void)
{
  static GQuark ret = 0;
  if (ret == 0)
    {
      ret = g_quark_from_static_string ("hal_file_monitor_error");
    }

  return ret;
}

static int
hal_mask_to_kmask (int mask)
{
  int kmask = 0;

  if (mask & HAL_FILE_MONITOR_EVENT_CREATE)
    {
      kmask |= NOTE_WRITE | NOTE_LINK;
    }

  if (mask & HAL_FILE_MONITOR_EVENT_DELETE)
    {
      kmask |= NOTE_WRITE | NOTE_LINK | VN_NOTE_DELETED;
    }

  if (mask & HAL_FILE_MONITOR_EVENT_CHANGE)
    {
      kmask |= VN_NOTE_CHANGED;
    }

  return kmask;
}

guint
hal_file_monitor_add_notify (HalFileMonitor *monitor,
                             const char *path,
                             int mask,
                             HalFileMonitorNotifyFunc notify_func,
                             gpointer data)
{
  struct kevent ev;
  struct stat sb;
  int fd;
  int id = 0;

  if (! monitor->priv->initialized_kqueue)
    {
      return id;
    }

  fd = open (path, O_RDONLY);
  if (fd < 0)
    {
      return id;
    }

  if (fstat (fd, &sb) == -1)
    {
      close (fd);
      return id;
    }

  if (mask & HAL_FILE_MONITOR_EVENT_ACCESS)
    {
      FileAccessData *adata;

      adata = g_new0 (FileAccessData, 1);
      adata->path = g_strdup (path);
      adata->atime = sb.st_atime;
      adata->func = notify_func;
      adata->udata = data;
      if (mask == HAL_FILE_MONITOR_EVENT_ACCESS)
        {
          /* We will close the file descriptor when we release the adata. */
          adata->owner = TRUE;
        }
      g_hash_table_insert (monitor->priv->fd_to_adata,
                           GINT_TO_POINTER (fd),
                           adata);
      id = fd;
    }

  if ((mask & HAL_FILE_MONITOR_EVENT_CREATE) ||
      (mask & HAL_FILE_MONITOR_EVENT_DELETE) ||
      (mask & HAL_FILE_MONITOR_EVENT_CHANGE))
    {
      FileKqueueData *kdata;
      int kmask;
      gboolean isdir;

      kmask = hal_mask_to_kmask (mask);

      isdir = (sb.st_mode & S_IFDIR) != 0;
      if (! isdir && mask == HAL_FILE_MONITOR_EVENT_CREATE)
        {
          /* We can't monitor creation on a file. */
          goto done;
        }

      kdata = g_new0 (FileKqueueData, 1);
      kdata->path = g_strdup (path);
      kdata->omask = mask;
      kdata->isdir = isdir;
      kdata->func = notify_func;
      kdata->udata = data;
      if (isdir)
        {
          kdata->dir_contents = get_dir_contents (path);
        }

      /*g_warning ("XXX: Adding event with mask %s", fflags_to_str (kmask));*/
      EV_SET (&ev, fd, EVFILT_VNODE, EV_ADD | EV_ENABLE | EV_CLEAR,
              kmask, 0, monitor);
      if (kevent (monitor->priv->kqueue_fd, &ev, 1, NULL, 0, NULL) < 0)
        {
          monitor_release_kdata (monitor, fd, kdata);
          goto done;
        }
      g_hash_table_insert (monitor->priv->fd_to_kdata,
                           GINT_TO_POINTER (fd),
                           kdata);
      id = fd;
    }

done:
  return id;
}

static void
hal_file_monitor_remove_kdata (HalFileMonitor *monitor,
                               guint id)
{
  FileKqueueData *kdata;

  kdata = (FileKqueueData *) g_hash_table_lookup (monitor->priv->fd_to_kdata, GINT_TO_POINTER (id));

  if (kdata)
    {
      g_hash_table_remove (monitor->priv->fd_to_kdata, GINT_TO_POINTER (id));
      monitor_release_kdata (monitor, id, kdata);
    }
}

static void
hal_file_monitor_remove_adata (HalFileMonitor *monitor,
                               guint id)
{
  FileAccessData *adata;

  adata = (FileAccessData *) g_hash_table_lookup (monitor->priv->fd_to_adata, GINT_TO_POINTER (id));

  if (adata)
    {
      g_hash_table_remove (monitor->priv->fd_to_adata, GINT_TO_POINTER (id));
      monitor_release_adata (monitor, id, adata);
    }
}

void
hal_file_monitor_remove_notify (HalFileMonitor *monitor,
                                guint id)
{
  if (! monitor->priv->initialized_kqueue)
    return;

  hal_file_monitor_remove_kdata (monitor, id);
  hal_file_monitor_remove_adata (monitor, id);

}

static void
monitor_release_kdata (HalFileMonitor *monitor,
                       int fd,
                       FileKqueueData *data)
{
  g_free (data->path);
  data->path = NULL;

  if (data->dir_contents)
    {
      g_hash_table_remove_all (data->dir_contents);
      g_hash_table_destroy (data->dir_contents);
    }
  data->dir_contents = NULL;

  close (fd);

  g_free (data);
}

static void
monitor_release_adata (HalFileMonitor *monitor,
                       int fd,
                       FileAccessData *data)
{
  g_free (data->path);
  data->path = NULL;

  if (data->owner)
    {
      close (fd);
    }

  g_free (data);
}

static gboolean
remove_kdata_foreach (gpointer fd,
                      FileKqueueData *data,
                      HalFileMonitor *monitor)
{
  monitor_release_kdata (monitor, GPOINTER_TO_INT (fd), data);
  return TRUE;
}

static gboolean
remove_adata_foreach (gpointer fd,
                      FileAccessData *data,
                      HalFileMonitor *monitor)
{
  monitor_release_adata (monitor, GPOINTER_TO_INT (fd), data);
  return TRUE;
}

static void
close_monitor (HalFileMonitor *monitor)
{
  if (! monitor->priv->initialized_kqueue)
    {
      return;
    }

  monitor->priv->initialized_kqueue = FALSE;

  g_hash_table_foreach_remove (monitor->priv->fd_to_kdata,
                               (GHRFunc) remove_kdata_foreach,
                               monitor);

  g_hash_table_foreach_remove (monitor->priv->fd_to_adata,
                               (GHRFunc) remove_adata_foreach,
                               monitor);

  if (monitor->priv->io_watch)
    {
      g_source_remove (monitor->priv->io_watch);
    }
  monitor->priv->io_watch = 0;

  if (monitor->priv->access_source)
    {
      g_source_remove (monitor->priv->access_source);
    }
  monitor->priv->access_source = 0;

  if (monitor->priv->kqueue_fd > -1)
    {
      close (monitor->priv->kqueue_fd);
    }
  monitor->priv->kqueue_fd = -1;
}

static gboolean
hal_file_access_monitor (gpointer data)
{
  HalFileMonitor *monitor;
  GList *keys, *l;

  g_return_val_if_fail (HAL_IS_FILE_MONITOR (data), FALSE);

  monitor = HAL_FILE_MONITOR (data);

  g_return_val_if_fail (monitor->priv != NULL, FALSE);

  keys = g_hash_table_get_keys (monitor->priv->fd_to_adata);

  for (l = keys; l != NULL; l = l->next)
    {
      FileAccessData *adata;
      struct stat sb;
      int fd;

      fd = GPOINTER_TO_INT (l->data);
      adata = g_hash_table_lookup (monitor->priv->fd_to_adata,
                                   l->data);

      if (! adata)
        {
          continue;
        }

      if (fstat (fd, &sb) == -1)
        {
          g_warning ("Failed to stat %s: %s", adata->path, g_strerror (errno));
          hal_file_monitor_remove_adata (monitor, fd);
          continue;
        }

      if (sb.st_atime != adata->atime)
        {
          adata->atime = sb.st_atime;
          emit_monitor_event (monitor, HAL_FILE_MONITOR_EVENT_ACCESS, adata->path, adata->func, adata->udata);
        }
    }

  return TRUE;
}

static void
setup_monitor (HalFileMonitor *monitor)
{
  GIOChannel *io_channel;
  int fd;

  if (monitor->priv->initialized_kqueue)
    {
      return;
    }

  if ((fd = kqueue ()) < 0)
    {
      g_warning ("Failed to initialize kqueue: %s",
                 g_strerror (errno));
      return;
    }

  monitor->priv->kqueue_fd = fd;

  monitor->priv->fd_to_kdata = g_hash_table_new (g_direct_hash,
                               g_direct_equal);
  monitor->priv->fd_to_adata = g_hash_table_new (g_direct_hash,
                               g_direct_equal);

  io_channel = g_io_channel_unix_new (fd);
  monitor->priv->io_watch = g_io_add_watch (io_channel,
                            G_IO_IN|G_IO_PRI,
                            (GIOFunc) handle_kqueue_event,
                            monitor);
  g_io_channel_unref (io_channel);

  monitor->priv->access_source = g_timeout_add (1000, (GSourceFunc) hal_file_access_monitor, monitor);

  monitor->priv->initialized_kqueue = TRUE;
}

static void
hal_file_monitor_init (HalFileMonitor *monitor)
{
  monitor->priv = HAL_FILE_MONITOR_GET_PRIVATE (monitor);

  setup_monitor (monitor);
}

static void
hal_file_monitor_class_init (HalFileMonitorClass *klass)
{
  GObjectClass   *object_class = G_OBJECT_CLASS (klass);

  object_class->finalize = hal_file_monitor_finalize;

  g_type_class_add_private (klass, sizeof (HalFileMonitorPrivate));
}

static void
hal_file_monitor_finalize (GObject *object)
{
  HalFileMonitor *monitor;

  g_return_if_fail (object != NULL);
  g_return_if_fail (HAL_IS_FILE_MONITOR (object));

  monitor = HAL_FILE_MONITOR (object);

  g_return_if_fail (monitor->priv != NULL);

  close_monitor (monitor);

  g_hash_table_destroy (monitor->priv->fd_to_kdata);
  g_hash_table_destroy (monitor->priv->fd_to_adata);

  G_OBJECT_CLASS (hal_file_monitor_parent_class)->finalize (object);
}

HalFileMonitor *
hal_file_monitor_new (void)
{
  if (monitor_object != NULL)
    {
      g_object_ref (monitor_object);
    }
  else
    {
      monitor_object = g_object_new (HAL_TYPE_FILE_MONITOR, NULL);

      g_object_add_weak_pointer (monitor_object,
                                 (gpointer *) &monitor_object);
    }

  return HAL_FILE_MONITOR (monitor_object);
}

/*
static char *
fflags_to_str (int fflags)
{

  GString *out;

  out = g_string_new (NULL);

  if (fflags & NOTE_WRITE)
    {
      g_string_append (out, " WRITE ");
    }
  if (fflags & NOTE_EXTEND)
    {
      g_string_append (out, " EXTEND ");
    }
  if (fflags & NOTE_ATTRIB)
    {
      g_string_append (out, " ATTRIB ");
    }
  if (fflags & NOTE_LINK)
    {
      g_string_append (out, " LINK ");
    }
  if (fflags & NOTE_DELETE)
    {
      g_string_append (out, " DELETE ");
    }
  if (fflags & NOTE_REVOKE)
    {
      g_string_append (out, " REVOKE ");
    }
  if (fflags & NOTE_RENAME)
    {
      g_string_append (out, " RENAME ");
    }

  return g_string_free (out, FALSE);
}
*/

static void
emit_monitor_event (HalFileMonitor *monitor,
                    HalFileMonitorEvent event,
                    const char *path,
                    HalFileMonitorNotifyFunc func,
                    gpointer udata)
{
  if (func)
    {
      func (monitor, event, path, udata);
    }
}

static gboolean
handle_kqueue_event (GIOChannel *source,
                     GIOCondition   condition,
                     gpointer udata)
{
  struct kevent ev;
  struct timespec timeout = { 0, 0 };
  int nevents;
  HalFileMonitor *monitor;

  g_return_val_if_fail (HAL_IS_FILE_MONITOR (udata), FALSE);

  monitor = HAL_FILE_MONITOR (udata);

  g_return_val_if_fail (monitor->priv != NULL, FALSE);

  g_return_val_if_fail (monitor->priv->kqueue_fd > -1, FALSE);

  nevents = kevent (monitor->priv->kqueue_fd, NULL, 0, &ev, 1, &timeout);
  if (nevents == 1)
    {
      int fd;
      FileKqueueData *data;

      fd = ev.ident;
      data = g_hash_table_lookup (monitor->priv->fd_to_kdata,
                                  GINT_TO_POINTER (fd));
      if (! data)
        {
          /* The monitor may have been deleted. */
          return TRUE;
        }

      if ((data->omask & HAL_FILE_MONITOR_EVENT_DELETE) &&
          (ev.fflags & VN_NOTE_DELETED))
        {
          emit_monitor_event (monitor, HAL_FILE_MONITOR_EVENT_DELETE, data->path, data->func, data->udata);
          hal_file_monitor_remove_kdata (monitor, fd);
          return TRUE;
        }

      if ((data->omask & HAL_FILE_MONITOR_EVENT_CREATE) ||
          (data->omask & HAL_FILE_MONITOR_EVENT_DELETE))
        {
          if (data->isdir)
            {
              GSList *added = NULL;
              GSList *removed = NULL;
              GSList *l;
              GHashTable *table;
              gboolean found_change = FALSE;

              table = diff_dir_contents (data, &added, &removed);
              if (data->omask & HAL_FILE_MONITOR_EVENT_CREATE)
                {
                  for (l = added; l != NULL; l = l->next)
                    {
                      char *path;

                      path = g_build_filename (data->path, l->data, NULL);
                      emit_monitor_event (monitor, HAL_FILE_MONITOR_EVENT_CREATE, path, data->func, data->udata);
                      g_free (path);
                    }
                }

              if (data->omask & HAL_FILE_MONITOR_EVENT_DELETE)
                {
                  for (l = removed; l != NULL; l = l->next)
                    {
                      char *path;

                      path = g_build_filename (data->path, l->data, NULL);
                      emit_monitor_event (monitor, HAL_FILE_MONITOR_EVENT_DELETE, path, data->func, data->udata);
                      g_free (path);
                    }
                }

              if (added || removed)
                {
                  g_hash_table_remove_all (data->dir_contents);
                  g_hash_table_destroy (data->dir_contents);
                  data->dir_contents = table;
                  found_change = TRUE;
                }
              else if (table)
                {
                  g_hash_table_remove_all (table);
                  g_hash_table_destroy (table);
                }
              else
                {
                  hal_file_monitor_remove_kdata (monitor, fd);
                }

              if (added)
                {
                  g_slist_foreach (added, (GFunc) g_free, NULL);
                  g_slist_free (added);
                }
              if (removed)
                {
                  g_slist_foreach (removed, (GFunc) g_free, NULL);
                  g_slist_free (removed);
                }

              if (found_change)
                {
                  return TRUE;
                }
            }
        }

      if (data->omask & HAL_FILE_MONITOR_EVENT_CHANGE)
        {
          emit_monitor_event (monitor, HAL_FILE_MONITOR_EVENT_CHANGE, data->path, data->func, data->udata);
        }
    }
  else
    {
      g_warning ("Failed to read from kqueue: %s", g_strerror (errno));
      return FALSE;
    }

  return TRUE;
}

static GHashTable *
diff_dir_contents (FileKqueueData *data,
                   GSList **added,
                   GSList **removed)
{
  GDir *dir;
  GError *err = NULL;
  GHashTable *table = NULL;

  dir = g_dir_open (data->path, 0, &err);
  if (dir)
    {
      const char *fname;

      table = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, NULL);

      while ((fname = g_dir_read_name (dir)))
        {
          if (added)
            {
              if (! g_hash_table_lookup (data->dir_contents, fname))
                {
                  *added = g_slist_prepend (*added, g_strdup (fname));
                }
            }

          g_hash_table_insert (table, g_strdup (fname), GINT_TO_POINTER (TRUE));
        }

      g_dir_close (dir);

      if (removed)
        {
          GList *keys;
          GList *l;

          keys = g_hash_table_get_keys (data->dir_contents);

          for (l = keys; l != NULL; l = l->next)
            {
              if (! g_hash_table_lookup (table, l->data))
                {
                  *removed = g_slist_prepend (*removed, g_strdup (l->data));
                }
            }
        }

    }
  else
    {
      g_warning ("Failed to open directory: %s", err->message);
      g_error_free (err);
    }

  return table;
}

static GHashTable *
get_dir_contents (const char *path)
{
  GDir *dir;
  GError *err = NULL;
  GHashTable *table = NULL;

  dir = g_dir_open (path, 0, &err);
  if (dir)
    {
      const char *fname;

      table = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, NULL);

      while ((fname = g_dir_read_name (dir)))
        {
          g_hash_table_insert (table, g_strdup (fname), GINT_TO_POINTER (TRUE));
        }
      g_dir_close (dir);
    }
  else
    {
      g_warning ("Failed to open directory %s: %s\n", path, err->message);
      g_error_free (err);
    }

  return table;
}

/*
static void
print_event (HalFileMonitor *monitor,
             HalFileMonitorEvent event,
             const char *path,
             gpointer udata)
{
  GString *ename;

  ename = g_string_new (NULL);

  if (event & HAL_FILE_MONITOR_EVENT_ACCESS)
    {
      g_string_append (ename, "ACCESS ");
    }
  if (event & HAL_FILE_MONITOR_EVENT_CREATE)
    {
      g_string_append (ename, "CREATE ");
    }
  if (event & HAL_FILE_MONITOR_EVENT_DELETE)
    {
      g_string_append (ename, "DELETE ");
    }
  if (event & HAL_FILE_MONITOR_EVENT_CHANGE)
    {
      g_string_append (ename, "CHANGE ");
    }

  printf("Received event for %s: %s\n", path, g_string_free (ename, FALSE));
}

int
main(void)
{
  const char *path = "/tmp/kqueue.d";
  guint watch;
  GMainLoop *loop;
  HalFileMonitor *monitor;

  g_type_init ();

  monitor = hal_file_monitor_new ();
  hal_file_monitor_add_notify (monitor, path, HAL_FILE_MONITOR_EVENT_CREATE|HAL_FILE_MONITOR_EVENT_DELETE|HAL_FILE_MONITOR_EVENT_CHANGE,print_event, NULL);

  loop = g_main_loop_new (NULL, FALSE);

  g_main_loop_run (loop);

  return 0;
}
*/
