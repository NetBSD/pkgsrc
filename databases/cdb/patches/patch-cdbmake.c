$NetBSD: patch-cdbmake.c,v 1.1 2015/08/30 08:18:15 dholland Exp $

fix build if the compiler decides not to inline.

--- cdbmake.c~	2000-02-19 20:42:05.000000000 +0000
+++ cdbmake.c
@@ -26,7 +26,7 @@ void die_readformat(void)
   strerr_die2x(111,FATAL,"unable to read input: bad format");
 }
 
-inline void get(char *ch)
+static inline void get(char *ch)
 {
   switch(buffer_GETC(buffer_0,ch)) {
     case 0: die_readformat();
