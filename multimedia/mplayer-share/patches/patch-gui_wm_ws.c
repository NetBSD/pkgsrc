$NetBSD: patch-gui_wm_ws.c,v 1.1 2015/11/21 09:47:23 leot Exp $

Correctly display the GUI avoiding the following errors:

 [ws] An X11 error has occurred!
 [ws]  Error code: 145 - BadShmSeg (invalid shared segment parameter)
 [ws]  Request code: 139 (minor code: 3)
 [ws]  MPlayer module: vo_check_events

Imported also upstream:

 http://lists.mplayerhq.hu/pipermail/mplayer-dev-eng/2015-November/073183.html

--- gui/wm/ws.c.orig	2015-08-01 07:44:07.000000000 +0000
+++ gui/wm/ws.c
@@ -1322,6 +1322,7 @@ void wsImageCreate(wsWindow *win, int w,
         win->xImage->data     = win->Shminfo.shmaddr;
         win->Shminfo.readOnly = False;
         XShmAttach(wsDisplay, &win->Shminfo);
+        XSync(wsDisplay, False);
         shmctl(win->Shminfo.shmid, IPC_RMID, 0);
     } else
 #endif
