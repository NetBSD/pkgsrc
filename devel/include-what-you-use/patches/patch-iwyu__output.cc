$NetBSD: patch-iwyu__output.cc,v 1.1 2015/12/30 16:16:13 bsiegert Exp $

Remove use of std::to_string, which is problematic in gcc48.

--- iwyu_output.cc.orig	2015-12-11 05:45:54.000000000 +0000
+++ iwyu_output.cc
@@ -61,7 +61,6 @@ using std::map;
 using std::multimap;
 using std::pair;
 using std::sort;
-using std::to_string;
 using std::vector;
 
 namespace internal {
@@ -555,7 +554,7 @@ void IwyuFileInfo::AddUsingDecl(const Us
   int end_linenum = GetLineNumber(GetInstantiationLoc(decl_lines.getEnd()));
   VERRS(6) << "Found using-decl: "
            << GetFilePath(file_) << ":" 
-           << to_string(start_linenum) << "-" << to_string(end_linenum) << ": " 
+           << start_linenum << "-" << end_linenum << ": " 
            << internal::PrintablePtr(using_decl)
            << internal::GetQualifiedNameAsString(using_decl) << "\n";
 }
