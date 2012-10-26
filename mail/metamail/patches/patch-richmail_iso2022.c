$NetBSD: patch-richmail_iso2022.c,v 1.1 2012/10/26 20:27:15 joerg Exp $

--- richmail/iso2022.c.orig	2012-10-25 19:46:36.000000000 +0000
+++ richmail/iso2022.c
@@ -73,7 +73,7 @@ static	int	OutAsciiMode;
 /*
  * Initialise the ISO-2022 character set processor.
  */
-iso2022_init (name)
+void iso2022_init (name)
 char	*name;
 {
     SwToAscii = 'B';
