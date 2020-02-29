$NetBSD: patch-src_time_ISO8601.cxx,v 1.1 2020/02/29 08:58:33 wiz Exp $

../src/time/ISO8601.cxx:67:24: error: use of undeclared identifier 'strtoul'
        unsigned long value = strtoul(s, &endptr, 10);
                              ^
../src/time/ISO8601.cxx:77:14: error: use of undeclared identifier 'strtoul'
                        minutes = strtoul(s, &endptr, 10);
                                  ^

https://github.com/MusicPlayerDaemon/MPD/pull/775

--- src/time/ISO8601.cxx.orig	2020-02-16 19:43:35.000000000 +0000
+++ src/time/ISO8601.cxx
@@ -37,6 +37,7 @@
 #include <stdexcept>
 
 #include <assert.h>
+#include <stdlib.h>
 
 StringBuffer<64>
 FormatISO8601(const struct tm &tm) noexcept
