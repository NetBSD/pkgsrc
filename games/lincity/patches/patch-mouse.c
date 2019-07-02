$NetBSD: patch-mouse.c,v 1.1 2019/07/02 13:46:29 nia Exp $

mouse.c:1262: undefined reference to `mt_erase'
mouse.c:1264: undefined reference to `mt_temp'
mouse.c:1252: undefined reference to `mt_erase'
mouse.c:1292: undefined reference to `mt_temp'
mouse.c:1224: undefined reference to `mt_erase'
mouse.c:1233: undefined reference to `mt_perm'
mouse.c:1267: undefined reference to `mt_erase'
mouse.c:1295: undefined reference to `mt_erase'

--- mouse.c.orig	2003-10-05 05:53:32.000000000 +0000
+++ mouse.c
@@ -1056,7 +1056,7 @@ choose_residence (void)
    and set to 1 if the existing transport if the more expensive sort
    (e.g. GROUP_RAIL when overwriting GROUP_ROAD).
 */
-inline int
+static inline int
 mt_erase(int x, int y)
 {
     if (x < 0 || y < 0 || x >= WORLD_SIDE_LEN || y >= WORLD_SIDE_LEN)
@@ -1093,7 +1093,7 @@ mt_erase(int x, int y)
     return 0;
 }
 
-inline int
+static inline int
 mt_temp(int x, int y)
 {
     if (x < 0 || y < 0 || x >= WORLD_SIDE_LEN || y >= WORLD_SIDE_LEN)
@@ -1127,7 +1127,7 @@ mt_temp(int x, int y)
     return 0;
 }
 
-inline int
+static inline int
 mt_perm(int x, int y)
 {
     /* By now, it has already been mt_erase()'d */
