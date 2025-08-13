$NetBSD: patch-src_oiiotool_printinfo.cpp,v 1.2 2025/08/13 06:51:22 wiz Exp $

https://github.com/AcademySoftwareFoundation/OpenImageIO/pull/4857

--- src/oiiotool/printinfo.cpp.orig	2025-08-13 06:26:13.271475820 +0000
+++ src/oiiotool/printinfo.cpp
@@ -58,9 +58,9 @@ print_nums(std::ostream& out, int n, con
             if (i)
                 Strutil::print(out, "{}", sep);
             float v = float(val[i]);
-            if (isnan(v))
+            if (std::isnan(v))
                 Strutil::print(out, "nan");
-            else if (isinf(v))
+            else if (std::isinf(v))
                 Strutil::print(out, "inf");
             else
                 Strutil::print(out, "{:.9f}", v);
