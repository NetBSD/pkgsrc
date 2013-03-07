$NetBSD: patch-lef_defRead.c,v 1.2 2013/03/07 22:05:13 joerg Exp $

--- lef/defRead.c.orig	2013-03-02 22:27:45.000000000 +0000
+++ lef/defRead.c
@@ -568,12 +568,8 @@ enum def_orient {DEF_NORTH, DEF_SOUTH, D
 	DEF_FLIPPED_NORTH, DEF_FLIPPED_SOUTH, DEF_FLIPPED_EAST,
 	DEF_FLIPPED_WEST};
 
-int
-DefReadLocation(use, f, oscale, tptr)
-    CellUse *use;
-    FILE *f;
-    float oscale;
-    Transform *tptr;
+static void
+DefReadLocation(CellUse *use, FILE *f, float oscale, Transform *tptr)
 {
     Rect *r, tr;
     int keyword;
@@ -645,11 +641,11 @@ DefReadLocation(use, f, oscale, tptr)
     GeoTranslateTrans(&t2, (int)roundf(x / oscale), (int)roundf(y / oscale), tptr);
     if (use)
 	DBSetTrans(use, tptr);
-    return 0;
+    return;
 
 parse_error:
     LefError("Cannot parse location: must be ( X Y ) orient\n");
-    return -1;
+    return;
 }
 
 /*
