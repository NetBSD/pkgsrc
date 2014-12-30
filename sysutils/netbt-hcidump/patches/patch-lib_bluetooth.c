$NetBSD: patch-lib_bluetooth.c,v 1.1 2014/12/30 08:39:13 plunky Exp $

Not much of the original library is needed.

--- lib/bluetooth.c.orig	2014-12-26 17:54:42.000000000 +0000
+++ lib/bluetooth.c
@@ -48,6 +48,7 @@ void baswap(bdaddr_t *dst, const bdaddr_
 		d[i] = s[5-i];
 }
 
+#if 0
 char *batostr(const bdaddr_t *ba)
 {
 	char *str = bt_malloc(18);
@@ -73,6 +74,7 @@ bdaddr_t *strtoba(const char *str)
 
 	return ba;
 }
+#endif
 
 int ba2str(const bdaddr_t *ba, char *str)
 {
@@ -80,6 +82,7 @@ int ba2str(const bdaddr_t *ba, char *str
 		ba->b[5], ba->b[4], ba->b[3], ba->b[2], ba->b[1], ba->b[0]);
 }
 
+#if 0
 int str2ba(const char *str, bdaddr_t *ba)
 {
 	int i;
@@ -257,6 +260,7 @@ int bt_error(uint16_t code)
 		return ENOSYS;
 	}
 }
+#endif
 
 const char *bt_compidtostr(int compid)
 {
