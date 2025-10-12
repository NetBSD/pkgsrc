$NetBSD: patch-richmail_usascii.c,v 1.1 2025/10/12 00:57:39 mrg Exp $

Port to GCC 14.

--- richmail/usascii.c.orig	1992-10-21 11:04:20.000000000 -0700
+++ richmail/usascii.c	2025-10-11 17:47:17.762815275 -0700
@@ -35,12 +35,14 @@
 
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 #include "richlex.h"
 #include "richset.h"
 
 /*
  * Initialise the US-ASCII character set processor.
  */
+int
 usascii_init (name)
 char	*name;
 {
@@ -98,6 +100,7 @@ RCHAR	ch;
 /*
  * Render the given US-ASCII character.
  */
+int
 usascii_render (ch,param)
 RCHAR	ch;
 void	*param;
@@ -108,6 +111,7 @@ void	*param;
 /*
  * Enter or leave the US-ASCII encoding.
  */
+int
 usascii_encoding (newenc)
 int	newenc;
 {
