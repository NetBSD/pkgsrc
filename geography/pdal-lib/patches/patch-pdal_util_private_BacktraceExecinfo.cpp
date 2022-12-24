$NetBSD: patch-pdal_util_private_BacktraceExecinfo.cpp,v 1.1 2022/12/24 09:58:20 wiz Exp $

Do not cast away constness.
Fixes build on NetBSD.
https://github.com/PDAL/PDAL/pull/3916

--- pdal/util/private/BacktraceExecinfo.cpp.orig	2020-09-09 15:14:16.000000000 +0000
+++ pdal/util/private/BacktraceExecinfo.cpp
@@ -60,7 +60,7 @@ Utils::BacktraceEntries Utils::backtrace
             entry.symname = info.dli_sname;
             entry.libname = info.dli_fname;
             entry.offset = reinterpret_cast<char *>(entry.addr) -
-                reinterpret_cast<char *>(info.dli_saddr);
+                reinterpret_cast<const char *>(info.dli_saddr);
         }
         entries.push_back(entry);
     }
