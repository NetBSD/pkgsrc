$NetBSD: patch-sql_mysqld.cc,v 1.1 2013/02/13 21:00:07 adam Exp $

--- sql/mysqld.cc.orig	2013-01-22 16:54:50.000000000 +0000
+++ sql/mysqld.cc
@@ -184,7 +184,7 @@ extern int memcntl(caddr_t, size_t, int,
 int initgroups(const char *,unsigned int);
 #endif
 
-#if defined(__FreeBSD__) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT)
+#if (defined(__FreeBSD__) || defined(__DragonFly__)) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT)
 #include <ieeefp.h>
 #ifdef HAVE_FP_EXCEPT       // Fix type conflict
 typedef fp_except fp_except_t;
@@ -215,7 +215,7 @@ extern "C" my_bool reopen_fstreams(const
 
 inline void setup_fpu()
 {
-#if defined(__FreeBSD__) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT)
+#if (defined(__FreeBSD__) || defined(__DragonFly__)) && defined(HAVE_IEEEFP_H) && !defined(HAVE_FEDISABLEEXCEPT)
   /* We can't handle floating point exceptions with threads, so disable
      this on freebsd
      Don't fall for overflow, underflow,divide-by-zero or loss of precision.
@@ -6292,7 +6292,7 @@ void handle_connections_sockets()
             The connection was refused by TCP wrappers.
             There are no details (by client IP) available to update the host_cache.
           */
-          statistic_increment(connection_tcpwrap_errors, &LOCK_status);
+          statistic_increment(connection_errors_tcpwrap, &LOCK_status);
           continue;
         }
       }
