$NetBSD: patch-libs_std_sys.c,v 1.1 2020/03/24 13:23:46 nia Exp $

Workaround no uselocale on netbsd. (there's setlocale, though)

--- libs/std/sys.c.orig	2017-12-19 06:38:08.000000000 +0000
+++ libs/std/sys.c
@@ -133,7 +133,7 @@ static value sys_sleep( value f ) {
 	<doc>Set the locale for LC_TIME, returns true on success</doc>
 **/
 static value set_time_locale( value l ) {
-#ifdef NEKO_POSIX
+#if defined(NEKO_POSIX) && !defined(__NetBSD__)
 	locale_t lc, old;
 	val_check(l,string);
 	lc = newlocale(LC_TIME_MASK,val_string(l),NULL);
