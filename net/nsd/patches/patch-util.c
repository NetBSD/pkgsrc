$NetBSD: patch-util.c,v 1.1 2011/09/12 17:05:02 taca Exp $

* Use u_int32_t instead of obsolete u_long.

--- util.c.orig	2011-03-22 13:13:32.000000000 +0000
+++ util.c
@@ -742,7 +742,7 @@ mktime_from_utc(const struct tm *tm)
    http://www.tsfr.org/~orc/Code/bsd/bsd-current/cksum/crc.c.
    or http://gobsd.com/code/freebsd/usr.bin/cksum/crc.c
    The polynomial is 0x04c11db7L. */
-static u_long crctab[] = {
+static const u_int32_t crctab[] = {
 	0x0,
 	0x04c11db7, 0x09823b6e, 0x0d4326d9, 0x130476dc, 0x17c56b6b,
 	0x1a864db2, 0x1e475005, 0x2608edb8, 0x22c9f00f, 0x2f8ad6d6,
