$NetBSD: patch-hotspot_make_solaris_makefiles_dtrace.make,v 1.1 2013/06/15 09:31:05 jperkin Exp $

Enable DTrace support with GCC.

--- hotspot/make/solaris/makefiles/dtrace.make.orig	2012-08-10 16:23:13.000000000 +0000
+++ hotspot/make/solaris/makefiles/dtrace.make
@@ -30,13 +30,6 @@
 ifneq ("${TYPE}", "CORE")
 ifneq ("${TYPE}", "KERNEL")
 
-ifdef USE_GCC
-
-dtraceCheck:
-	$(QUIETLY) echo "**NOTICE** Dtrace support disabled for gcc builds"
-
-else
-
 JVM_DB = libjvm_db
 LIBJVM_DB = libjvm_db.so
 LIBJVM_DB_G = libjvm$(G_SUFFIX)_db.so
@@ -63,14 +56,23 @@ DTRACE_SRCDIR = $(GAMMADIR)/src/os/$(Pla
 DTRACE = dtrace
 DTRACE.o = $(DTRACE).o
 
-# to remove '-g' option which causes link problems
-# also '-z nodefs' is used as workaround
-GENOFFS_CFLAGS = $(shell echo $(CFLAGS) | sed -e 's/ -g / /g' -e 's/ -g0 / /g';)
+ifdef USE_GCC
+  # solaris linker does not like gcc and -fvisibility=hidden without mapfiles
+  GENOFFS_CFLAGS = $(shell echo $(CFLAGS) | sed -e 's/ -g / /g' -e 's/ -g0 / /g' -e 's/ -fvisibility=hidden / /g';)
+else
+  # to remove '-g' option which causes link problems
+  # also '-z nodefs' is used as workaround
+  GENOFFS_CFLAGS = $(shell echo $(CFLAGS) | sed -e 's/ -g / /g' -e 's/ -g0 / /g';)
+endif
 
 ifdef LP64
 DTRACE_OPTS = -64 -D_LP64
 endif
 
+ifdef USE_GCC
+  DTRACE_OPTS = -D_GNU_SOURCE
+endif # USE_GCC
+
 # making libjvm_db
 
 # Use mapfile with libjvm_db.so
@@ -384,8 +386,6 @@ dtraceCheck:
 
 endif # ifneq ("${dtraceFound}", "")
 
-endif # ifdef USE_GCC
-
 else # KERNEL build
 
 dtraceCheck:
