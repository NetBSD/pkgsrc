$NetBSD: patch-command.c,v 1.1 2012/11/01 19:50:59 joerg Exp $

--- command.c.orig	2012-10-30 22:18:05.000000000 +0000
+++ command.c
@@ -89,7 +89,7 @@ calcsum(p, len)
   return(sum);
 }
 
-inline void
+void
 wbyte(c)
      u_char	c;
 {
@@ -104,7 +104,7 @@ wbyte(c)
   check_sum = check_sum + (int) c;
 }
 
-inline u_char
+u_char
 rbyte()
 {
   u_char	c;
@@ -133,7 +133,7 @@ int checksum(u_char u)
 	return(1);
 }
 
-inline void
+void
 wstr(p, len)
      u_char	*p;
      int	len;
@@ -149,7 +149,7 @@ wstr(p, len)
   check_sum = check_sum + calcsum(p, len);
 }
 
-inline void
+void
 rstr(p, len)
      u_char	*p;
      int	len;
