/* Copyright (C) 2008 Juan Romero Pardines <xtraeme@gmail.com>

   This file is part of LibGTop 2.

   LibGTop is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License,
   or (at your option) any later version.

   LibGTop is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.

   You should have received a copy of the GNU General Public License
   along with LibGTop; see the file COPYING. If not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <config.h>
#include <glibtop/procaffinity.h>
#include <glibtop/error.h>

#include <sys/param.h>
#if __NetBSD_Version__ >= 499007200	/* 4.99.72 to play safe */
#include <sched.h>
#endif

void
_glibtop_init_proc_affinity_s(glibtop *server)
{
  server->sysdeps.proc_affinity =
    (1 << GLIBTOP_PROC_AFFINITY_NUMBER) |
    (1 << GLIBTOP_PROC_AFFINITY_ALL);

}


guint16 *
glibtop_get_proc_affinity_s(glibtop *server, glibtop_proc_affinity *buf, pid_t pid)
{
#if __NetBSD_Version__ >= 499007200
  cpuset_t *cpuset;
  size_t i;
  GArray* cpus;

  memset(buf, 0, sizeof *buf);

  /* create the cpuset(3) */
  cpuset = cpuset_create();
  if (cpuset == NULL) {
    glibtop_error_r(server, "cpuset_getaffinity (cpuset_create) failed");
    return NULL;
  }

  /* get the affinity for _this_ pid, I assume that we always want lid 0 */
  if ((_sched_getaffinity(pid, 0, cpuset_size(cpuset), cpuset)) != 0) {
    cpuset_destroy(cpuset);
    glibtop_error_r(server, "cpuset_getaffinity (_sched_getaffinity) failed");
    return NULL;
  }

  cpus = g_array_new(FALSE, FALSE, sizeof(guint16));

  for (i = 0; i < MIN(cpuset_size(cpuset), (size_t)(server->ncpu + 1)); i++) {
    if (cpuset_isset(i, cpuset)) {
      guint16 n = i;
      g_array_append_val(cpus, n);
    }
  }

  buf->number = cpus->len;
  buf->all = (cpus->len == (size_t)(server->ncpu + 1));
  buf->flags = (1 << GLIBTOP_PROC_AFFINITY_NUMBER)
    | (1 << GLIBTOP_PROC_AFFINITY_ALL);

  /* we are done */
  cpuset_destroy(cpuset);

  return (guint16*) g_array_free(cpus, FALSE);
#else
  memset(buf, 0, sizeof *buf);

  return NULL;
#endif
}
