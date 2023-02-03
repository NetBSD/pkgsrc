$NetBSD: patch-.._github.com_pganalyze_pg__query__go_v2@v2.2.0_parser_include_pg__config.h,v 1.1 2023/02/03 14:28:58 bsiegert Exp $

NetBSD also has strchrnul.
https://github.com/pganalyze/pg_query_go/pull/72

--- ../github.com/pganalyze/pg_query_go/v2@v2.2.0/parser/include/pg_config.h.orig	1979-11-30 00:00:00.000000000 +0000
+++ ../github.com/pganalyze/pg_query_go/v2@v2.2.0/parser/include/pg_config.h
@@ -990,6 +990,6 @@
 #undef HAVE_EXECINFO_H
 #undef HAVE_BACKTRACE_SYMBOLS
 #undef HAVE__GET_CPUID
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define HAVE_STRCHRNUL
 #endif
