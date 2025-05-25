$NetBSD: patch-lib_html__text.tcl,v 1.1 2025/05/25 15:04:07 vins Exp $

Fix for nonexistent "state(tag)" variable runtime error.

--- lib/html_text.tcl.orig	2017-11-10 04:42:24.000000000 +0000
+++ lib/html_text.tcl
@@ -60,7 +60,7 @@ proc Text_TagAdd {win tag m1 {m2 {}}} {
     }
     set state(tag) $tag
     $win dump -tag -text -window -command \
-	    [list TextUndoTagAddProc state $win] $m1 $m2
+	    [list TextUndoTagAddProc state $win] $m1 $m2 tag
     TextUndoTagAdd state $win [$win index $m2]
     $win tag add $tag $m1 $m2
 }
@@ -179,7 +179,7 @@ proc TextUndoTagRemove {stateVar win end
 	unset state(ix)
     }
 }
-proc TextUndoTagAddProc {stateVar win key value ix} {
+proc TextUndoTagAddProc {stateVar win key value ix tag} {
     upvar $stateVar state
     switch -- $key {
 	tagon {
