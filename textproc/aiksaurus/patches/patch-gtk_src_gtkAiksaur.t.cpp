$NetBSD: patch-gtk_src_gtkAiksaur.t.cpp,v 1.1 2014/12/06 19:04:14 dholland Exp $

Use standard headers.

--- gtk/src/gtkAiksaur.t.cpp~	2002-01-12 02:02:12.000000000 +0000
+++ gtk/src/gtkAiksaur.t.cpp
@@ -23,6 +23,7 @@
 #include <gtk/gtk.h>
 #include <iostream>
 #include <string>
+#include <cstdlib>
 using namespace std;
 
 int main(int argc, char** argv)
