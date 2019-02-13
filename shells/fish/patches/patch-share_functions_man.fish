$NetBSD: patch-share_functions_man.fish,v 1.1 2019/02/13 22:03:53 maya Exp $

Avoid playing games with MANPATH.

If MANPATH is empty, this sets MANPATH to PREFIX/share/fish/man.
This means that you won't be able to find normal man pages.

--- share/functions/man.fish.orig	2018-12-28 13:01:03.000000000 +0000
+++ share/functions/man.fish
@@ -9,20 +9,20 @@ function man --description "Format and d
     # man pages priority, without having to put fish's bin directories first in $PATH.
 
     # Preserve the existing MANPATH, and default to the system path (the empty string).
-    set -l manpath
-    if set -q MANPATH
-        set manpath $MANPATH
-    else
-        set manpath ''
-    end
-    # Notice the shadowing local exported copy of the variable.
-    set -lx MANPATH $manpath
-
-    # Prepend fish's man directory if available.
-    set -l fish_manpath (dirname $__fish_data_dir)/fish/man
-    if test -d $fish_manpath
-        set MANPATH $fish_manpath $MANPATH
-    end
+#    set -l manpath
+#    if set -q MANPATH
+#        set manpath $MANPATH
+#    else
+#        set manpath ''
+#    end
+#    # Notice the shadowing local exported copy of the variable.
+#    set -lx MANPATH $manpath
+#
+#    # Prepend fish's man directory if available.
+#    set -l fish_manpath (dirname $__fish_data_dir)/fish/man
+#    if test -d $fish_manpath
+#        set MANPATH $fish_manpath $MANPATH
+#    END
 
     command man $argv
 end
