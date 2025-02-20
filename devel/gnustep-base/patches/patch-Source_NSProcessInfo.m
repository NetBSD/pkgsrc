$NetBSD: patch-Source_NSProcessInfo.m,v 1.2 2025/02/20 14:28:46 manu Exp $

Work around an issue regarding GNUstep and locale. GNUstep hijacks
application main() with its own function to setup some global
variables before the actual main() is called. _gnu_process_args(),
called by the fake main(), eventually calls nl_langinfo(CODESET) via
GSPrivateICUCStringEncoding() to determine the locale charset but
without initializing the locale. When this happens on NetBSD,
nl_langinfo(CODESET) returns "646" regardless of the actual locale and
ICU (correctly) interprets this as US-ASCII. This causes all the
subsequent calls to -[NSString fileSystemRepresentation] to fail for
any non-ASCII file paths. Applications usually call setlocale(LC_ALL,
"") in their main() but it's too late at that point because the
previous value is cached forever.

This is a dirty hack on top of a dirty hack and I'm obvisouly not
happy with this, but if the dirty hack is broken we still have to fix
it.

--- Source/NSProcessInfo.m.orig	2025-02-10 18:00:46.000000000 +0100
+++ Source/NSProcessInfo.m	2025-02-18 15:29:10.462572672 +0100
@@ -1006,8 +1006,10 @@
   exit(1);
 }
 int main(int argc, char *argv[], char *env[])
 {
+  setlocale(LC_ALL, "");
+
 #ifdef NeXT_RUNTIME
   /* This memcpy has to be done before the first message is sent to any
      constant string object. See Apple Radar 2870817 */
   memcpy(&_NSConstantStringClassReference,
