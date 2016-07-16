$NetBSD: patch-src_log_dlg.cpp,v 1.1 2016/07/16 03:32:32 markd Exp $

wxWidgets 3.0 unicode fix

--- src/log_dlg.cpp.orig	2012-06-28 06:39:35.000000000 +0000
+++ src/log_dlg.cpp
@@ -211,7 +211,7 @@ private:
 
     for (size_t idx = 0; idx < str.Length(); idx++)
     {
-      switch (str[idx])
+      switch (str[idx].GetValue())
       {
       case wxT('\r'):
       case wxT('\n'):
