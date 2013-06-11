$NetBSD: patch-src_Unix.cs,v 1.1 2013/06/11 02:29:40 obache Exp $

* Reverse the way the dllmap for libsocket is handled, by using libc
  https://github.com/mono/dbus-sharp/commit/1561585d601058392d5864e3add2bac3c67e14a7

--- src/Unix.cs.orig	2010-09-14 09:17:50.000000000 +0000
+++ src/Unix.cs
@@ -197,7 +197,7 @@ namespace DBus.Unix
 
 		// Solaris provides socket functionality in libsocket rather than libc.
 		// We use a dllmap in the .config to deal with this.
-		internal const string LIBSOCKET = "libsocket";
+		internal const string LIBSOCKET = "libc";
 
 		public const short AF_UNIX = 1;
 		// FIXME: SOCK_STREAM is 2 on Solaris
