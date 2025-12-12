$NetBSD: patch-t_op_for-many.t,v 1.1 2025/12/12 08:11:40 wiz Exp $

Fix a segfault when compiling a 2-var for loop over builtin::indexed.

This is upstream git commit 96673a4bb36, with the following commit
message:

 newFOROP: fix crash when optimizing 2-var for over builtin::indexed

 OP_ENTERSUB isn't necessarily a LISTOP, apparently, so we can't just
 grab its op_last. Instead, copy/paste logic from elsewhere in op.c to
 find the cvop.

 Also, avoid crashing on "fake" pad entries that represent lexical subs
 from outer scopes by climbing up the scope chain until we reach a real
 pad entry.

 Fixes #23405.

--- t/op/for-many.t.orig	2024-05-07 01:08:47.000000000 +0000
+++ t/op/for-many.t
@@ -498,4 +498,17 @@ is($continue, 'xx', 'continue reached tw
     is("@have", "Pointy end Up Flamey end Down", 'for my ($one, $two)');
 }
 
+# GH #23405 - segfaults when compiling 2-var for loops
+{
+    my $dummy = sub {};
+    for my ($x, $y) (main->$dummy) {}
+    pass '2-var for does not crash on method calls';
+
+    my sub dummy {}
+    sub {
+        for my ($x, $y) (dummy) {}
+    }->();
+    pass '2-var for does not crash on lexical sub calls';
+}
+
 done_testing();
