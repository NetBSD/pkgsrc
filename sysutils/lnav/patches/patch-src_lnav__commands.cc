$NetBSD: patch-src_lnav__commands.cc,v 1.1 2023/05/24 22:42:53 he Exp $

`time_t` may not be a `long int`, but may be `long long`, so cast
and adapt format accordingly.

--- src/lnav_commands.cc.orig	2022-10-06 17:08:45.000000000 +0000
+++ src/lnav_commands.cc
@@ -226,8 +226,8 @@ com_adjust_log_time(exec_context& ec,
             snprintf(
                 buffer,
                 sizeof(buffer),
-                "info: log timestamps will be adjusted by %ld.%06ld seconds",
-                time_diff.tv_sec,
+                "info: log timestamps will be adjusted by %lld.%06ld seconds",
+                (long long)time_diff.tv_sec,
                 (long) time_diff.tv_usec);
 
             retval = buffer;
@@ -295,7 +295,7 @@ com_unix_time(exec_context& ec,
                      "%a %b %d %H:%M:%S %Y  %z %Z",
                      localtime(&u_time));
             len = strlen(ftime);
-            snprintf(ftime + len, sizeof(ftime) - len, " -- %ld", u_time);
+            snprintf(ftime + len, sizeof(ftime) - len, " -- %lld", (long long)u_time);
             retval = std::string(ftime);
         } else {
             return ec.make_error("invalid unix time -- {}", args[1]);
