$NetBSD: patch-frontends_xml_vcd__xml__common.c,v 1.2 2025/11/23 07:04:32 wiz Exp $

Fix build with libxml 2.14.
https://gitlab.archlinux.org/archlinux/packaging/packages/vcdimager/-/raw/88dc511b7f3dea8fb45e0c2bfa1345a75a088848/libxml214.diff

--- frontends/xml/vcd_xml_common.c.orig	2018-01-03 20:17:37.000000000 +0000
+++ frontends/xml/vcd_xml_common.c
@@ -242,17 +242,27 @@ _convert (const char in[], const char en
 
   temp = size - 1;
   if (from) {
-    if (NULL != handler->output)
-      ret = handler->output (out, &out_size, (const unsigned char *) in, &temp);
-    else
+    if (!(handler->flags & 2) && NULL != handler->output.func)
+      ret = handler->output.func (handler->outputCtxt, out, &out_size, (const unsigned char *) in, &temp, 1);
+    if ((handler->flags & 2) && NULL != handler->output.legacyFunc)
+      ret = handler->output.legacyFunc (out, &out_size, (const unsigned char *) in, &temp);
+    else {
+      xmlCharEncCloseFunc(handler);
       return strdup(in);
+    }
   } else {
-    if (NULL != handler->input)
-      ret = handler->input (out, &out_size, (const unsigned char *) in, &temp);
-    else
+    if (!(handler->flags & 2) && NULL != handler->input.func)
+      ret = handler->input.func (handler->inputCtxt, out, &out_size, (const unsigned char *) in, &temp, 1);
+    if ((handler->flags & 2) && NULL != handler->input.legacyFunc)
+      ret = handler->input.legacyFunc (out, &out_size, (const unsigned char *) in, &temp);
+    else {
+      xmlCharEncCloseFunc(handler);
       return strdup(in);
+    }
   }
 
+  xmlCharEncCloseFunc(handler);
+
   if (ret < 0 || (temp - size + 1))
     {
       free (out);
