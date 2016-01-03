$NetBSD: patch-f.combine.cc,v 1.1 2016/01/03 04:33:49 ryoon Exp $

--- f.combine.cc.orig	2016-01-01 08:20:29.000000000 +0000
+++ f.combine.cc
@@ -47,6 +47,9 @@
 
 #define EX extern                                                                //  enable extern declarations
 #include "fotoxx.h"                                                              //  (variables in fotoxx.h are refs)
+#if !defined(__linux__)
+#include <limits.h>
+#endif
 
 /********************************************************************************/
 
@@ -6490,7 +6493,12 @@ void m_pano_PT(GtkWidget *, cchar *)    
    if (checkpend("all")) return;
    Fblock = 1;                                                                   //  15.11
 
+#if defined(__linux__)
    olddir = get_current_dir_name();                                              //  save curr. directory
+#else
+   char cwd[PATH_MAX];
+   olddir = getcwd(cwd, PATH_MAX);
+#endif
 
    err = chdir(tempdir);                                                         //  use /tmp/fotoxx-xxxxx
    if (err) {
