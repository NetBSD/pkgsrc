$NetBSD: manual-funcs.c,v 1.1 2020/07/06 10:11:34 jperkin Exp $

Apple switched from using RLIMIT_RSS (ulimit -m) in 10.3 (xnu-517.12.7) over
to RLIMIT_AS (ulimit -v) in 10.4 (xnu-792), providing a compatibility define
for RLIMIT_RSS.  The default bash shell since 10.4 supports both -m and -v.

Because the current design of the ULIMIT_CMD_* variables in mk/platform/*.mk
dictates that we must use a single value, -m is chosen so that all releases
are supported.  However, mksh removes -m support by default if it is
identical to -v, thus breaking ULIMIT_CMD_memorysize.

In order to provide maximum compatibility in pkgsrc, we apply the following
patch so that "ulimit -m" continues to work with mksh, acting as an alias
for -v.

For the record, it appears that /bin/zsh also supports -v but not -m,
whereas shells/pdksh supports -m but not -v.

--- files/funcs.c.orig	2020-06-25 09:34:59.000000000 +0000
+++ files/funcs.c
@@ -3240,7 +3240,7 @@ ptest_error(Test_env *te, int ofs, const
 #else
 #define ULIMIT_M_IS_RSS
 #endif
-#if defined(ULIMIT_M_IS_RSS) && defined(RLIMIT_AS) && (RLIMIT_RSS == RLIMIT_AS)
+#if defined(ULIMIT_M_IS_RSS) && defined(RLIMIT_AS) && (RLIMIT_RSS == RLIMIT_AS) && !defined(__APPLE__)
 #undef ULIMIT_M_IS_RSS
 #endif
 #endif
