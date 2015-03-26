$NetBSD: patch-compat_fts.h,v 1.1 2015/03/26 14:16:12 sevan Exp $

"We always use FTS_NOCHDIR, so delete the directory changing code.
This not only simplifies matters, but also helps operating systems
lacking dirfd(3), for example Solaris 10."

--- compat_fts.h.orig	2015-03-26 04:16:43.000000000 +0000
+++ compat_fts.h
@@ -40,13 +40,12 @@ typedef struct {
 	struct _ftsent *fts_child;	/* linked list of children */
 	dev_t fts_dev;			/* starting device # */
 	char *fts_path;			/* path for this descent */
-	int fts_rfd;			/* fd for root */
 	size_t fts_pathlen;		/* sizeof(path) */
 
 #define	FTS_NOCHDIR	0x0004		/* don't change directories */
 #define	FTS_PHYSICAL	0x0010		/* physical walk */
 #define	FTS_XDEV	0x0040		/* don't cross devices */
-#define	FTS_OPTIONMASK	0x00ff		/* valid user option mask */
+#define	FTS_OPTIONMASK	0x0054		/* valid user option mask */
 
 #define	FTS_STOP	0x2000		/* (private) unrecoverable error */
 	int fts_options;		/* fts_open options, global flags */
@@ -85,9 +84,6 @@ typedef struct _ftsent {
 #define	FTS_SL		12		/* symbolic link */
 	unsigned short fts_info;	/* user flags for FTSENT structure */
 
-#define	FTS_DONTCHDIR	 0x01		/* don't chdir .. to the parent */
-	unsigned short fts_flags;	/* private flags for FTSENT structure */
-
 #define	FTS_NOINSTR	 3		/* no instructions */
 #define	FTS_SKIP	 4		/* discard node */
 	unsigned short fts_instr;	/* fts_set() instructions */
