$NetBSD: patch-lib_prefix.c,v 1.1 2025/09/16 20:25:18 gutteridge Exp $

Use ctype.h correctly.

--- lib/prefix.c.orig	2017-05-09 19:28:38.000000000 +0000
+++ lib/prefix.c
@@ -101,8 +101,8 @@ pseInsensitiveCompare(
     const void* const	entry1,
     const void* const	entry2)
 {
-    int	char1 = tolower(((const PrefixSearchEntry*)entry1)->character);
-    int	char2 = tolower(((const PrefixSearchEntry*)entry2)->character);
+    int	char1 = tolower((unsigned char)((const PrefixSearchEntry*)entry1)->character);
+    int	char2 = tolower((unsigned char)((const PrefixSearchEntry*)entry2)->character);
 
     return char1 < char2 ? -1 : char1 == char2 ? 0 : 1;
 }
