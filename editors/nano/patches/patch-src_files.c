$NetBSD: patch-src_files.c,v 1.3 2019/04/01 10:26:42 wiedi Exp $

The lack of initialization caused a nasty bug on some targets (such as
ARMv7) which would make it so that ^S would just say "Cancelled".

While x86 (both 64 and 32 bits) seems to initialize 'response' to zero or
a positive number, ARM does not, and there is usually a negative value in
its place, which triggers the 'if (response < 0)' check and, as a result,
the code says "Cancelled".

This fixes https://savannah.gnu.org/bugs/?56023.
Reported-by: Devin Hussey <husseydevin@gmail.com>

Bug existed since version 4.0, commit 0f9d60a3.

--- src/files.c.orig	2019-03-23 08:26:13.000000000 +0000
+++ src/files.c
@@ -2101,7 +2101,7 @@ int do_writeout(bool exiting, bool withp
 
 	while (TRUE) {
 		const char *msg;
-		int response, choice;
+		int response = 0, choice = 0;
 		functionptrtype func;
 #ifndef NANO_TINY
 		const char *formatstr, *backupstr;
