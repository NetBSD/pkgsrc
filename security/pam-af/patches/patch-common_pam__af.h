$NetBSD: patch-common_pam__af.h,v 1.1 2017/02/08 00:07:38 joerg Exp $

Don't pessimize the build or even create unaligned access by forcing the
structures to be packed.

--- common/pam_af.h.orig	2017-01-08 20:09:41.718970211 +0000
+++ common/pam_af.h
@@ -90,14 +90,6 @@
 # define _PATH_BSHELL DEFSHL
 #endif
 
-#ifndef __packed
-# ifdef __GNUC__
-#  define __packed __attribute__((packed))
-# else /* __GNUC__ */
-#  define __packed
-# endif /* __GNUC__ */
-#endif
-
 #ifndef __unused
 # ifdef __GNUC__
 #  define __unused __attribute__((unused))
@@ -114,7 +106,7 @@ typedef struct hostrec {
 	unsigned long	num;
 	time_t		last_attempt;
 	unsigned long	locked_for;
-} __packed hostrec_t;
+} hostrec_t;
 
 typedef struct hostrule {
 	uint mask;
@@ -122,7 +114,7 @@ typedef struct hostrule {
 	long		locktime;
 	char		lock_cmd[MAX_CMD_LEN];
 	char		unlock_cmd[MAX_CMD_LEN];
-} __packed hostrule_t;
+} hostrule_t;
 #define DEFAULT_ATTEMPTS	ULONG_MAX
 #define DEFAULT_LOCKTIME	0
 #define DEFRULE "*"
