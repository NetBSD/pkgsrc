$NetBSD: patch-enemy.cpp,v 1.1 2011/09/25 19:46:21 joerg Exp $

--- enemy.cpp.orig	2011-09-24 20:34:55.000000000 +0000
+++ enemy.cpp
@@ -755,10 +755,10 @@ void _enemy::move_core()
 
 void _enemy::kill_core()
 {
-	enemies.make(&pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 3);
-	enemies.make(&pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 7);
-	enemies.make(&pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 1);
-	enemies.make(&pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 5);
+	enemies.make(&my_pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 3);
+	enemies.make(&my_pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 7);
+	enemies.make(&my_pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 1);
+	enemies.make(&my_pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 5);
 	enemies.make(&explosion4, CS2PIXEL(x), CS2PIXEL(y));
 	sound.g_base_core_explo(x, y);
 	release();
@@ -863,7 +863,7 @@ const enemy_kind pipe1 = {
 
 /*
  * ===========================================================================
- *                                pipe2
+ *                                my_pipe2
  * ===========================================================================
  */
 void _enemy::make_pipe2()
@@ -978,19 +978,19 @@ void _enemy::move_pipe2()
 	}
 	p ^= a;
 	if(p & U_MASK)
-		enemies.make(&pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 1);
+		enemies.make(&my_pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 1);
 	if(p & R_MASK)
-		enemies.make(&pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 3);
+		enemies.make(&my_pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 3);
 	if(p & D_MASK)
-		enemies.make(&pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 5);
+		enemies.make(&my_pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 5);
 	if(p & L_MASK)
-		enemies.make(&pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 7);
+		enemies.make(&my_pipe2, CS2PIXEL(x), CS2PIXEL(y), 0, 0, 7);
 	manage.add_score(10);
 	release();
 }
 
 
-const enemy_kind pipe2 = {
+const enemy_kind my_pipe2 = {
 	0,
 	&_enemy::make_pipe2,
 	&_enemy::move_pipe2,
