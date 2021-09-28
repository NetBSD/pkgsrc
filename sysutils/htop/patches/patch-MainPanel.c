$NetBSD: patch-MainPanel.c,v 1.1 2021/09/28 17:57:39 fox Exp $

Check for mouse events only if HAVE_GETMOUSE is defined.

NOTE: This has been fixed upstream and the patch will be removed in the next release.
https://github.com/htop-dev/htop/pull/820

--- MainPanel.c.orig	2021-09-28 02:18:18.760961460 +0000
+++ MainPanel.c
@@ -61,9 +61,15 @@ static HandlerResult MainPanel_eventHand
    if (ch == KEY_RESIZE)
       return IGNORED;
 
+   #ifdef HAVE_GETMOUSE
    /* reset on every normal key, except mouse events while mouse support is disabled */
    if (ch != ERR && (ch != KEY_MOUSE || this->state->settings->enableMouse))
       this->state->hideProcessSelection = false;
+   #else
+   /* reset on every normal key */
+   if (ch != ERR)
+      this->state->hideProcessSelection = false;
+   #endif
 
    if (EVENT_IS_HEADER_CLICK(ch)) {
       int x = EVENT_HEADER_CLICK_GET_X(ch);
