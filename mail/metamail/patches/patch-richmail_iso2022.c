$NetBSD: patch-richmail_iso2022.c,v 1.2 2025/10/12 00:57:39 mrg Exp $

Port for GCC 14.

--- richmail/iso2022.c.orig	1992-12-22 09:50:21.000000000 -0800
+++ richmail/iso2022.c	2025-10-11 17:50:45.803936379 -0700
@@ -41,6 +41,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
+#include <string.h>
 #include "richlex.h"
 #include "richset.h"
 
@@ -70,10 +71,13 @@ static	int	OutAsciiMode;
 #define	ISO_CHARSET_PREFIX	"x-iso-charset-"
 #define	ISO_CHARSET_LEN		14
 
+extern int controloutput(); /* XXX */
+extern int controlputc(); /* XXX */
+
 /*
  * Initialise the ISO-2022 character set processor.
  */
-iso2022_init (name)
+int iso2022_init (name)
 char	*name;
 {
     SwToAscii = 'B';
@@ -84,7 +88,7 @@ char	*name;
     OutCharSet = OUT_ASCII;
     OutAsciiMode = RICH_ENC_US_ASCII;
     if (!name)
-	return;
+	return -1;
     if (!strncmp (name,"iso-2022-jp",11))
 	richtextencoding (RICH_ENC_JP_ASCII);
     else if (!strncmp (name,"iso-2022-kr",11)) {
@@ -92,6 +96,7 @@ char	*name;
 	controloutput("\033$)C",0);
     } else
 	richtextencoding (RICH_ENC_US_ASCII);
+    return 0;
 }
 
 /*
@@ -257,6 +262,7 @@ RCHAR	ch;
 /*
  * Render the given ISO-2022 character.
  */
+int
 iso2022_render (ch,param)
 RCHAR	ch;
 void	*param;
@@ -294,6 +300,7 @@ void	*param;
 /*
  * Enter or leave the ISO-2022 encoding.
  */
+int
 iso2022_encoding (newenc)
 int	newenc;
 {
