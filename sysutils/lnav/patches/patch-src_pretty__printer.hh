$NetBSD: patch-src_pretty__printer.hh,v 1.1 2015/09/05 22:12:04 wiz Exp $

Avoid name conflict with included header.

--- src/pretty_printer.hh.orig	2015-04-11 02:51:00.000000000 +0000
+++ src/pretty_printer.hh
@@ -171,10 +171,10 @@ private:
 
     void ascend() {
         if (this->pp_depth > 0) {
-            int lines = this->pp_body_lines.top();
+            int clines = this->pp_body_lines.top();
             this->pp_depth -= 1;
             this->pp_body_lines.pop();
-            this->pp_body_lines.top() += lines;
+            this->pp_body_lines.top() += clines;
         }
         else {
             this->pp_body_lines.top() = 0;
