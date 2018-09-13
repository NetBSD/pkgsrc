$NetBSD: patch-src_nano.h,v 1.1 2018/09/13 19:34:34 wiedi Exp $

When curses gives no code for Ctrl+Shift+Delete, do not fall back
to KEY_BACKSPACE, because then ^H and/or <Backspace> get bound to
'cutwordleft'.

This fixes https://savannah.gnu.org/bugs/?54642.
Upstream commit: 09ab2e3d0eeb33bc4d0702623404ba01b1f8fa9a

Version 3.1 will be released in one or two weeks and include this.

--- src/nano.h.orig	2018-08-29 17:37:02.000000000 +0000
+++ src/nano.h
@@ -588,6 +588,7 @@ enum
 #define SHIFT_CONTROL_DOWN 0x414
 #define SHIFT_CONTROL_HOME 0x415
 #define SHIFT_CONTROL_END 0x416
+#define CONTROL_SHIFT_DELETE 0x417
 #define ALT_LEFT 0x421
 #define ALT_RIGHT 0x422
 #define ALT_UP 0x423
