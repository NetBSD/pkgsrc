$NetBSD: patch-CodeLite_MSYS2.hpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Missing declarations of wxArrayString, wxFilename and wxGetEnv

--- CodeLite/MSYS2.hpp.orig	2023-01-11 21:18:07.000000000 +0000
+++ CodeLite/MSYS2.hpp
@@ -3,6 +3,9 @@
 
 #include "PlatformCommon.hpp"
 #include "codelite_exports.h"
+#include <wx/arrstr.h>
+#include <wx/filename.h>
+#include <wx/utils.h>
 
 class WXDLLIMPEXP_CL MSYS2 : public PlatformCommon
 {
