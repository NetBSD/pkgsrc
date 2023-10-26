$NetBSD: patch-Remoty_sample__codelite__remote__json.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Missing declaration of wxString

--- Remoty/sample_codelite_remote_json.cpp.orig	2023-01-11 21:18:07.000000000 +0000
+++ Remoty/sample_codelite_remote_json.cpp
@@ -1,6 +1,8 @@
 #ifndef SAMPLE_CODELITE_REMOTE_JSON_HPP
 #define SAMPLE_CODELITE_REMOTE_JSON_HPP
 
+#include <wx/string.h>
+
 const wxString DEFAULT_CODELITE_REMOTE_JSON = R"EOF(
 {
   "Language Server Plugin": {
