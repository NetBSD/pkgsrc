$NetBSD: patch-imakemdep.h,v 1.6 2016/09/17 17:49:36 richard Exp $

 - Configure for pkgsrc: never set FIXUP_CPP_WHITESPACE as pkgsrc now
always uses a whitespace-preserving cpp and fixing it twice causes
bizarre lossage.

 - Remove all the "logic" for guessing how to invoke cpp, and get it
via RAWCPP defined on the command line.

 - Make argv[0] for invoking cpp "cpp" by default.

 - Do not pass -m32 to cpp; it is not portable, valid, or even a
reasonable thing to do.

 - Add support for __aarch64__

--- imakemdep.h.orig	2013-08-17 10:11:06.000000000 +0000
+++ imakemdep.h
@@ -229,7 +229,7 @@ in this Software without prior written a
  *     all colons).  One way to tell if you need this is to see whether or not
  *     your Makefiles have no tabs in them and lots of @@ strings.
  */
-#  if defined(sun) || defined(SYSV) || defined(SVR4) || defined(hcx) || defined(WIN32) || defined(__SCO__) || (defined(AMOEBA) && defined(CROSS_COMPILE)) || defined(__QNX__) || defined(__sgi) || defined(__UNIXWARE__)
+#  if 0
 #   define FIXUP_CPP_WHITESPACE
 #  endif
 #  ifdef WIN32
@@ -257,79 +257,7 @@ in this Software without prior written a
  *     If the cpp you need is not in /lib/cpp, define DEFAULT_CPP.
  */
 #  if !defined (CROSSCOMPILE) || defined (CROSSCOMPILE_CPP)
-
-#   if defined(__APPLE__)
-#    define DEFAULT_CPP "/usr/bin/cpp"
-#    define DEFAULT_CC "cc"
-#   endif
-#   if defined(Lynx) || defined(__Lynx__)
-#    define DEFAULT_CC "gcc"
-#    define USE_CC_E
-#   endif
-#   ifdef hpux
-#    define USE_CC_E
-#   endif
-#   ifdef WIN32
-#    define USE_CC_E
-#    ifdef __GNUC__
-#     define DEFAULT_CC "gcc"
-#    else
-#     define DEFAULT_CC "cl"
-#    endif
-#   endif
-#   ifdef apollo
-#    define DEFAULT_CPP "/usr/lib/cpp"
-#   endif
-#   if defined(clipper) || defined(__clipper__)
-#    define DEFAULT_CPP "/usr/lib/cpp"
-#   endif
-#   if defined(_IBMR2) && !defined(DEFAULT_CPP)
-#    define DEFAULT_CPP "/usr/ccs/lib/cpp"
-#   endif
-#   ifdef __bsdi__
-#    define DEFAULT_CPP "/usr/bin/cpp"
-#   endif
-#   ifdef __uxp__
-#    define DEFAULT_CPP "/usr/ccs/lib/cpp"
-#   endif
-#   ifdef __sxg__
-#    define DEFAULT_CPP "/usr/lib/cpp"
-#   endif
-#   ifdef _CRAY
-#    define DEFAULT_CPP "/lib/pcpp"
-#   endif
-#   if defined(__386BSD__)
-#    define DEFAULT_CPP "/usr/libexec/cpp"
-#   endif
-#   if defined(__FreeBSD__)  || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__)
-#    define USE_CC_E
-#   endif
-#   if defined(__sgi) && defined(__ANSI_CPP__)
-#    define USE_CC_E
-#   endif
-#   if defined(MACH) && !defined(__GNU__)
-#    define USE_CC_E
-#   endif
-#   ifdef __minix_vmd
-#    define DEFAULT_CPP "/usr/lib/cpp"
-#   endif
-#   ifdef __CYGWIN__
-#    define DEFAULT_CC "gcc"
-#    define DEFAULT_CPP "/usr/bin/cpp"
-#   endif
-#   if defined (__QNX__)
-#    ifdef __QNXNTO__
-#     define DEFAULT_CPP "/usr/bin/cpp"
-#    else
-#     define DEFAULT_CPP "/usr/X11R6/bin/cpp"
-#    endif
-#   endif
-#   if defined(__GNUC__) && !defined(USE_CC_E)
-#    define USE_CC_E
-#    ifndef DEFAULT_CC
-#     define DEFAULT_CC "gcc"
-#    endif
-#   endif
+#    define DEFAULT_CPP RAWCPP
 
 #  endif /* !defined (CROSSCOMPILE) || defined (CROSSCOMPILE_CPP) */
 /*
@@ -352,7 +280,7 @@ in this Software without prior written a
 #  define	ARGUMENTS 50	/* number of arguments in various arrays */
 #  if !defined (CROSSCOMPILE) || defined (CROSSCOMPILE_CPP)
 const char *cpp_argv[ARGUMENTS] = {
-	"cc",		/* replaced by the actual program to exec */
+	"cpp",		/* replaced by the actual program to exec */
 	"-I.",		/* add current directory to include path */
 #   if !defined(__NetBSD_Version__) || __NetBSD_Version__ < 103080000
 #    ifdef unix
@@ -365,9 +293,6 @@ const char *cpp_argv[ARGUMENTS] = {
     defined(__GNUC__) || defined(__GLIBC__)
 #    ifdef __i386__
 	"-D__i386__",
-#     if defined(__GNUC__) && (__GNUC__ >= 3)
-	"-m32",
-#     endif
 #    endif
 #    ifdef __i486__
 	"-D__i486__",
@@ -399,6 +324,9 @@ const char *cpp_argv[ARGUMENTS] = {
 #    ifdef __arm__
 	"-D__arm__",
 #    endif
+#    ifdef __aarch64__
+	"-D__aarch64__",
+#    endif
 #    ifdef __s390x__
        "-D__s390x__",
 #    endif
