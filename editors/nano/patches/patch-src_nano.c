$NetBSD: patch-src_nano.c,v 1.1 2018/09/13 19:34:34 wiedi Exp $

When curses gives no code for Ctrl+Shift+Delete, do not fall back
to KEY_BACKSPACE, because then ^H and/or <Backspace> get bound to
'cutwordleft'.

This fixes https://savannah.gnu.org/bugs/?54642.
Upstream commit: 09ab2e3d0eeb33bc4d0702623404ba01b1f8fa9a

Version 3.1 will be released in one or two weeks and include this.

--- src/nano.c.orig	2018-09-09 09:39:27.000000000 +0000
+++ src/nano.c
@@ -2580,7 +2580,7 @@ int main(int argc, char **argv)
 	controlhome = get_keycode("kHOM5", CONTROL_HOME);
 	controlend = get_keycode("kEND5", CONTROL_END);
 	controldelete = get_keycode("kDC5", CONTROL_DELETE);
-	controlshiftdelete = get_keycode("kDC6", KEY_BACKSPACE);
+	controlshiftdelete = get_keycode("kDC6", CONTROL_SHIFT_DELETE);
 #ifndef NANO_TINY
 	/* Ask for the codes for Shift+Control+Left/Right/Up/Down. */
 	shiftcontrolleft = get_keycode("kLFT6", SHIFT_CONTROL_LEFT);
