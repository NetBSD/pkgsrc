$NetBSD: patch-cups_string.c,v 1.1.2.2 2023/06/08 19:02:48 spz Exp $

Fix denial-of-service using patch from Michael R Sweet.
https://www.openwall.com/lists/oss-security/2023/06/01/1

--- cups/string.c.orig	2022-05-26 06:17:21.000000000 +0000
+++ cups/string.c
@@ -729,6 +729,8 @@ _cups_strlcpy(char       *dst,		/* O - D
 {
   size_t	srclen;			/* Length of source string */
 
+  if (size == 0)                                                                                                                                                                                                                                                            
+    return (0);                                                                                                                                                                                                                                                             
 
  /*
   * Figure out how much room is needed...
