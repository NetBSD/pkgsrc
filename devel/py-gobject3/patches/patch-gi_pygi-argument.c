$NetBSD: patch-gi_pygi-argument.c,v 1.1 2012/09/20 12:00:00 prlw1 Exp $

commit 4e4c87e3: Fix 64bit integer convertion from GValue
https://bugzilla.gnome.org/show_bug.cgi?id=683596

--- gi/pygi-argument.c.orig	2012-05-14 16:49:12.000000000 +0000
+++ gi/pygi-argument.c
@@ -1836,15 +1836,19 @@ _pygi_argument_from_g_value(const GValue
         case GI_TYPE_TAG_INT8:
         case GI_TYPE_TAG_INT16:
         case GI_TYPE_TAG_INT32:
-        case GI_TYPE_TAG_INT64:
             arg.v_int = g_value_get_int (value);
             break;
+        case GI_TYPE_TAG_INT64:
+            arg.v_int64 = g_value_get_int64 (value);
+            break;
         case GI_TYPE_TAG_UINT8:
         case GI_TYPE_TAG_UINT16:
         case GI_TYPE_TAG_UINT32:
-        case GI_TYPE_TAG_UINT64:
             arg.v_uint = g_value_get_uint (value);
             break;
+        case GI_TYPE_TAG_UINT64:
+            arg.v_uint64 = g_value_get_uint64 (value);
+            break;
         case GI_TYPE_TAG_UNICHAR:
             arg.v_uint32 = g_value_get_schar (value);
             break;
