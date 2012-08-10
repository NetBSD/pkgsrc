$NetBSD: patch-src_libgame_misc.h,v 1.1 2012/08/10 18:04:53 joerg Exp $

--- src/libgame/misc.h.orig	2012-08-10 12:06:04.000000000 +0000
+++ src/libgame/misc.h
@@ -137,8 +137,8 @@ void dumpLevelDirInfo(struct LevelDirInf
 void sortLevelDirInfo(struct LevelDirInfo **,
 		      int (*compare_function)(const void *, const void *));
 
-inline void swap_numbers(int *, int *);
-inline void swap_number_pairs(int *, int *, int *, int *);
+void swap_numbers(int *, int *);
+void swap_number_pairs(int *, int *, int *, int *);
 
 char *getUserDataDir(void);
 char *getSetupDir(void);
