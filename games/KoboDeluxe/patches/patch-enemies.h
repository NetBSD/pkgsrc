$NetBSD: patch-enemies.h,v 1.1 2011/09/25 19:46:21 joerg Exp $

--- enemies.h.orig	2011-09-24 20:34:52.000000000 +0000
+++ enemies.h
@@ -72,7 +72,7 @@ extern const enemy_kind bombdeto;
 extern const enemy_kind cannon;
 extern const enemy_kind pipe1;
 extern const enemy_kind core;
-extern const enemy_kind pipe2;
+extern const enemy_kind my_pipe2;
 extern const enemy_kind rock;
 extern const enemy_kind ring;
 extern const enemy_kind enemy_m1;
@@ -430,7 +430,7 @@ inline int _enemy::realize()
 
 inline int _enemy::is_pipe()
 {
-	return ((_state != notuse) && ((ek == &pipe1) || (ek == &pipe2)));
+	return ((_state != notuse) && ((ek == &pipe1) || (ek == &my_pipe2)));
 }
 
 
