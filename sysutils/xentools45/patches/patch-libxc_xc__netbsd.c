$NetBSD: patch-libxc_xc__netbsd.c,v 1.1 2015/01/20 16:42:13 bouyer Exp $

--- libxc/xc_netbsd.c.orig	2015-01-12 17:53:24.000000000 +0100
+++ libxc/xc_netbsd.c	2015-01-19 13:16:38.000000000 +0100
@@ -18,13 +18,19 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
  */
 
-#include "xc_private.h"
-
-#include <xen/sys/evtchn.h>
-#include <unistd.h>
+#include <sys/mman.h>
+#include <sys/types.h>
 #include <fcntl.h>
 #include <malloc.h>
-#include <sys/mman.h>
+#include <unistd.h>
+
+#include <xen/memory.h>
+#include <xen/sys/evtchn.h>
+#include <xen/sys/gntdev.h>
+/* #include <xen/sys/gntalloc.h> */
+#include "xc_private.h"
+#include "xenctrl.h"
+#include "xenctrlosdep.h"
 
 static xc_osdep_handle netbsd_privcmd_open(xc_interface *xch)
 {
@@ -390,6 +396,210 @@
     return valloc(size);
 }
 
+#if 0
+#define DEVXEN  "/dev/xen/"
+
+static xc_osdep_handle
+netbsd_gnttab_open(xc_gnttab *xcg)
+{
+    int fd;
+
+    fd = open(DEVXEN "gntdev", O_RDWR);
+    if (fd == -1)
+        return XC_OSDEP_OPEN_ERROR;
+
+    return (xc_osdep_handle)fd;
+}
+
+static int
+netbsd_gnttab_close(xc_gnttab *xcg, xc_osdep_handle h)
+{
+    int fd = (int)h;
+    return close(fd);
+}
+
+static int netbsd_gnttab_set_max_grants(xc_gnttab *xch, xc_osdep_handle h,
+                                       uint32_t count)
+{
+    int fd = (int)h, rc;
+    struct ioctl_gntdev_set_max_grants max_grants = { .count = count };
+
+    rc = ioctl(fd, IOCTL_GNTDEV_SET_MAX_GRANTS, &max_grants);
+    if (rc) {
+	/*
+	 * Newer (e.g. pv-ops) kernels don't implement this IOCTL,
+	 * so ignore the resulting specific failure.
+	 */
+	if (errno == ENOTTY)
+	    rc = 0;
+	else
+	    PERROR("netbsd_gnttab_set_max_grants: ioctl SET_MAX_GRANTS failed");
+    }
+    return rc;
+}
+
+static void *netbsd_gnttab_grant_map(xc_gnttab *xch, xc_osdep_handle h,
+                                    uint32_t count, int flags, int prot,
+                                    uint32_t *domids, uint32_t *refs,
+                                    uint32_t notify_offset,
+                                    evtchn_port_t notify_port)
+{
+    int fd = (int)h;
+    struct ioctl_gntdev_map_grant_ref *map;
+    unsigned int map_size = ROUNDUP((sizeof(*map) + (count - 1) *
+                                    sizeof(struct ioctl_gntdev_map_grant_ref)),
+                                    XC_PAGE_SHIFT);
+    void *addr = NULL;
+    int domids_stride = 1;
+    int i;
+
+    if (flags & XC_GRANT_MAP_SINGLE_DOMAIN)
+        domids_stride = 0;
+
+    if ( map_size <= XC_PAGE_SIZE )
+        map = alloca(sizeof(*map) +
+                     (count - 1) * sizeof(struct ioctl_gntdev_map_grant_ref));
+    else
+    {
+        map = mmap(NULL, map_size, PROT_READ | PROT_WRITE,
+                   MAP_PRIVATE | MAP_ANON | MAP_POPULATE, -1, 0);
+        if ( map == MAP_FAILED )
+        {
+            PERROR("netbsd_gnttab_grant_map: mmap of map failed");
+            return NULL;
+        }
+    }
+
+    for ( i = 0; i < count; i++ )
+    {
+        map->refs[i].domid = domids[i * domids_stride];
+        map->refs[i].ref = refs[i];
+    }
+
+    map->count = count;
+
+    if ( ioctl(fd, IOCTL_GNTDEV_MAP_GRANT_REF, map) ) {
+        PERROR("netbsd_gnttab_grant_map: ioctl MAP_GRANT_REF failed");
+        goto out;
+    }
+
+ retry:
+    addr = mmap(NULL, XC_PAGE_SIZE * count, prot, MAP_SHARED, fd,
+                map->index);
+
+    if (addr == MAP_FAILED && errno == EAGAIN)
+    {
+        /*
+         * The grant hypercall can return EAGAIN if the granted page is
+         * swapped out. Since the paging daemon may be in the same domain, the
+         * hypercall cannot block without causing a deadlock.
+         *
+         * Because there are no notificaitons when the page is swapped in, wait
+         * a bit before retrying, and hope that the page will arrive eventually.
+         */
+        usleep(1000);
+        goto retry;
+    }
+
+    if (addr != MAP_FAILED)
+    {
+        int rv = 0;
+        struct ioctl_gntdev_unmap_notify notify;
+        notify.index = map->index;
+        notify.action = 0;
+        if (notify_offset < XC_PAGE_SIZE * count) {
+            notify.index += notify_offset;
+            notify.action |= UNMAP_NOTIFY_CLEAR_BYTE;
+        }
+        if (notify_port != -1) {
+            notify.event_channel_port = notify_port;
+            notify.action |= UNMAP_NOTIFY_SEND_EVENT;
+        }
+        if (notify.action)
+            rv = ioctl(fd, IOCTL_GNTDEV_SET_UNMAP_NOTIFY, &notify);
+        if (rv) {
+            PERROR("netbsd_gnttab_grant_map: ioctl SET_UNMAP_NOTIFY failed");
+            munmap(addr, count * XC_PAGE_SIZE);
+            addr = MAP_FAILED;
+        }
+    }
+
+    if (addr == MAP_FAILED)
+    {
+        int saved_errno = errno;
+        struct ioctl_gntdev_unmap_grant_ref unmap_grant;
+
+        /* Unmap the driver slots used to store the grant information. */
+        PERROR("xc_gnttab_map_grant_refs: mmap failed");
+        unmap_grant.index = map->index;
+        unmap_grant.count = count;
+        ioctl(fd, IOCTL_GNTDEV_UNMAP_GRANT_REF, &unmap_grant);
+        errno = saved_errno;
+        addr = NULL;
+    }
+
+ out:
+    if ( map_size > XC_PAGE_SIZE )
+        munmap(map, map_size);
+
+    return addr;
+}
+
+static int
+netbsd_gnttab_munmap(xc_gnttab *xcg, xc_osdep_handle h,
+    void *start_address, uint32_t count)
+{
+	int fd = (int)h;
+	struct ioctl_gntdev_get_offset_for_vaddr get_offset;
+	struct ioctl_gntdev_unmap_grant_ref unmap_grant;
+	int rc;
+
+	if ( start_address == NULL )
+	{
+		errno = EINVAL;
+		return -1;
+	}
+
+	/* First, it is necessary to get the offset which was initially used to
+	 * mmap() the pages.
+	 */
+	get_offset.vaddr = (unsigned long)start_address;
+	rc = ioctl(fd, IOCTL_GNTDEV_GET_OFFSET_FOR_VADDR, &get_offset);
+	if ( rc )
+		return rc;
+
+	if ( get_offset.count != count )
+	{
+		errno = EINVAL;
+		return -1;
+	}
+
+	/* Next, unmap the memory. */
+	rc = munmap(start_address, count * getpagesize());
+	if ( rc )
+		return rc;
+
+	/* Finally, unmap the driver slots used to store the grant information. */
+	unmap_grant.index = get_offset.offset;
+	unmap_grant.count = count;
+	rc = ioctl(fd, IOCTL_GNTDEV_UNMAP_GRANT_REF, &unmap_grant);
+	if ( rc )
+		return rc;
+	return 0;
+}
+
+static struct xc_osdep_ops netbsd_gnttab_ops = {
+    .open = &netbsd_gnttab_open,
+    .close = &netbsd_gnttab_close,
+
+    .u.gnttab = {
+        .set_max_grants = netbsd_gnttab_set_max_grants,
+        .grant_map = &netbsd_gnttab_grant_map,
+        .munmap = &netbsd_gnttab_munmap,
+    },
+};
+#endif
+
 static struct xc_osdep_ops *netbsd_osdep_init(xc_interface *xch, enum xc_osdep_type type)
 {
     switch ( type )
@@ -398,6 +608,10 @@
         return &netbsd_privcmd_ops;
     case XC_OSDEP_EVTCHN:
         return &netbsd_evtchn_ops;
+#if 0
+    case XC_OSDEP_GNTTAB:
+        return &netbsd_gnttab_ops;
+#endif
     default:
         return NULL;
     }
