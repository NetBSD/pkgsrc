$NetBSD: patch-src_YSM__Setup.c,v 1.1 2012/06/15 18:46:47 joerg Exp $

--- src/YSM_Setup.c.orig	2012-06-15 13:23:14.000000000 +0000
+++ src/YSM_Setup.c
@@ -743,7 +743,7 @@ int	tries = 0;
 #define YSMOPENCONFIG(rwx)	(fd = YSM_fopen(YSM_cfgfile,rwx))
 #define YSMCLOSECONFIG()	YSM_fclose(fd)
 
-__inline void
+void
 CFGWRITE(FILE *fd, const u_int8_t *foo, ...)
 {
 va_list	args;
