$NetBSD: patch-src_serial.c,v 1.1 2023/05/16 06:01:45 thorpej Exp $

Squelch "passing arguments to 'xxxxx' without a prototype is
deprecated in all versions of C and is not supported in C2x" error
thrown by Apple clang version 14.0.3 (clang-1403.0.22.14.1) (Xcode 14.3).

In this instance, passing the argument is incorrect, since UNLSN() and
UNTLK() don't actually take one.

--- src/serial.c.orig	2022-05-09 06:32:54
+++ src/serial.c	2023-05-16 05:53:45
@@ -203,7 +203,7 @@ serial_step(int clocks)
 								switch (byte & 0x60) {
 									case 0x20:
 										if (byte == 0x3f) {
-											int ret = UNLSN(byte);
+											int ret = UNLSN();
 											fnf = ret == 2;
 											listening = false;
 										} else {
@@ -213,7 +213,7 @@ serial_step(int clocks)
 										break;
 									case 0x40:
 										if (byte == 0x5f) {
-											UNTLK(byte);
+											UNTLK();
 											talking = false;
 										} else {
 											TALK(byte);
