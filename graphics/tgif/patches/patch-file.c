$NetBSD: patch-file.c,v 1.1 2024/06/18 08:44:33 markd Exp $

c99 fixes from Fedora 

--- file.c.orig	2011-05-16 16:21:57.000000000 +0000
+++ file.c
@@ -4737,6 +4737,7 @@ int LoadFile(FullName, ObjFile, GzippedO
    int ObjFile; /* equals TRUE if the file is an OBJ file */
                 /* equals FALSE if the file is a SYM or PIN file */
                 /* equals -1 if the file is an temporary OBJ file */
+   int GzippedObjFile;
 {
    struct ObjRec *obj_ptr=NULL;
    char tmp_filename[MAXPATHLENGTH+1], tmp_filefullpath[MAXPATHLENGTH+1];
