$NetBSD: patch-iwyu__output.cc,v 1.2 2018/02/06 10:01:36 adam Exp $

Remove use of std::to_string, which is problematic in gcc48.

--- iwyu_output.cc.orig	2017-12-02 09:16:38.000000000 +0000
+++ iwyu_output.cc
@@ -60,7 +60,6 @@ using std::map;
 using std::multimap;
 using std::pair;
 using std::sort;
-using std::to_string;
 using std::vector;
 
 namespace internal {
@@ -546,7 +545,7 @@ void IwyuFileInfo::AddUsingDecl(const Us
   int end_linenum = GetLineNumber(GetInstantiationLoc(decl_lines.getEnd()));
   VERRS(6) << "Found using-decl: "
            << GetFilePath(file_) << ":" 
-           << to_string(start_linenum) << "-" << to_string(end_linenum) << ": " 
+           << start_linenum << "-" << end_linenum << ": " 
            << internal::PrintablePtr(using_decl)
            << internal::GetQualifiedNameAsString(using_decl) << "\n";
 }
