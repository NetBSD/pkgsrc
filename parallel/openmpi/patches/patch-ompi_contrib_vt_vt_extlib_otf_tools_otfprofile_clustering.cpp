$NetBSD: patch-ompi_contrib_vt_vt_extlib_otf_tools_otfprofile_clustering.cpp,v 1.1 2012/06/12 23:36:31 asau Exp $

Define WEXITSTATUS.

--- ompi/contrib/vt/vt/extlib/otf/tools/otfprofile/clustering.cpp.orig	2011-12-14 01:44:13.000000000 +0000
+++ ompi/contrib/vt/vt/extlib/otf/tools/otfprofile/clustering.cpp
@@ -3,6 +3,7 @@
  Authors: Andreas Knuepfer, Robert Dietrich, Matthias Jurenz
 */
 
+#include <sys/wait.h>
 #include <fstream>
 #include <iostream>
 #include <sstream>
