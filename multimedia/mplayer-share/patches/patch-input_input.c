$NetBSD: patch-input_input.c,v 1.1 2025/11/15 12:43:18 ryoon Exp $

--- input/input.c.orig	2025-10-08 03:42:08.126293464 +0000
+++ input/input.c
@@ -1471,7 +1471,7 @@ mp_input_get_key_name(int key) {
       return key_names[i].name;
   }
 
-  if(0 <= key && key <= 255 && isprint(key)) {
+  if(0 <= key && key <= 255 && isprint((unsigned char)key)) {
     snprintf(key_str,12,"%c",(char)key);
     return key_str;
   }
