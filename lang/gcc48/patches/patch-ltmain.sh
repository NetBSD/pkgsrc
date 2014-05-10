$NetBSD: patch-ltmain.sh,v 1.1 2014/05/10 14:14:59 richard Exp $

--- ltmain.sh.orig	2011-01-13 18:51:10.000000000 +0000
+++ ltmain.sh
@@ -976,7 +976,7 @@ func_enable_tag ()
 
 
   case $host in
-    *cygwin* | *mingw* | *pw32* | *cegcc*)
+    *cygwin* | *mingw* | *pw32* | *cegcc* | *solaris2* )
       # don't eliminate duplications in $postdeps and $predeps
       opt_duplicate_compiler_generated_deps=:
       ;;
