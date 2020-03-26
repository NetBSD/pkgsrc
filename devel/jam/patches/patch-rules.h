$NetBSD: patch-rules.h,v 1.1 2020/03/26 21:19:58 rillig Exp $

make.c: In function 'make0':
make.c:249:41: error: array subscript has type 'char' [-Werror=char-subscripts]
    spaces( depth ), t->name, target_bind[ t->binding ] );^M
                                         ^
make.c:484:20: error: array subscript has type 'char' [-Werror=char-subscripts]
   flag, target_fate[ t->fate ],^M
                    ^
make.c:490:33: error: array subscript has type 'char' [-Werror=char-subscripts]
   printf( "%s %s\n", target_fate[ t->fate ], t->name );^M
                                 ^

--- rules.h.orig	2006-06-05 10:52:11.000000000 +0000
+++ rules.h
@@ -115,7 +115,7 @@ struct _target {
 # define	T_FLAG_NOUPDATE	0x20	/* NOUPDATE applied */
 # define	T_FLAG_INTERNAL	0x40	/* internal INCLUDES node */
 
-	char	binding;		/* how target relates to real file */
+	unsigned char	binding;	/* how target relates to real file */
 
 # define 	T_BIND_UNBOUND	0	/* a disembodied name */
 # define 	T_BIND_MISSING	1	/* couldn't find real file */
@@ -127,7 +127,7 @@ struct _target {
 
 	time_t	time;			/* update time */
 	time_t	leaf;			/* update time of leaf sources */
-	char	fate;			/* make0()'s diagnosis */
+	unsigned char	fate;		/* make0()'s diagnosis */
 
 # define 	T_FATE_INIT	0	/* nothing done to target */
 # define 	T_FATE_MAKING	1	/* make0(target) on stack */
