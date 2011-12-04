$NetBSD: patch-unix-pipechan.cxx,v 1.1 2011/12/04 21:59:37 marino Exp $

--- src/ptlib/unix/pipechan.cxx.orig	2009-09-21 00:25:17.000000000 +0000
+++ src/ptlib/unix/pipechan.cxx
@@ -199,7 +199,7 @@ PBoolean PPipeChannel::PlatformOpen(cons
 
   // Set up new environment if one specified.
   if (environment != NULL) {
-#if defined(P_SOLARIS) || defined(P_FREEBSD) || defined(P_OPENBSD) || defined (P_NETBSD) || defined(__BEOS__) || defined(P_MACOSX) || defined(P_MACOS) || defined (P_AIX) || defined(P_IRIX) || defined(P_QNX)
+#if defined(P_SOLARIS) || defined(P_FREEBSD) || defined(P_OPENBSD) || defined (P_NETBSD) || defined(__BEOS__) || defined(P_MACOSX) || defined(P_MACOS) || defined (P_AIX) || defined(P_IRIX) || defined(P_QNX) || defined(P_DRAGONFLY)
     extern char ** environ;
 #  if defined(P_MACOSX)
 #    define environ (*_NSGetEnviron())
