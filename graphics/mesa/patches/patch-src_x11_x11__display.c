$NetBSD: patch-src_x11_x11__display.c,v 1.1 2026/11/28 09:09:02 wiz Exp $

On NetBSD, shmat(2) fails with EINVAL when attaching a segment that
has already been marked for deletion with shmctl(2) IPC_RMID.
Mesa's software rasterizer marks each SHM display target for deletion
immediately after creating it, but the XSHM probe in
x11_xcb_display_supports_xshm() omits that IPC_RMID, so it succeeds
even though the real present path cannot attach the segment.  Then
the XSHM based present path is selected, every attach fails in the
X server, frames are never presented, and windows stay black.

Mirror the real usage by marking the test segment for deletion before
the X server attaches it.  The attach test then fails and Mesa
falls back to the plain XPutImage based present path.

https://gitlab.freedesktop.org/mesa/mesa/-/work_items/17045

--- src/x11/x11_display.c.orig	2026-11-28 05:43:11.280001015 +0000
+++ src/x11/x11_display.c
@@ -107,6 +107,8 @@
       goto check_xshm_cleanup;
    }
 
+   shmctl(shmid, IPC_RMID, NULL);
+
    shm_seg = xcb_generate_id(con);
    error = xcb_request_check(con,
                              xcb_shm_attach_checked(con,
