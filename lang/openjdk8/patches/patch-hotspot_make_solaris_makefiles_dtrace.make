$NetBSD: patch-hotspot_make_solaris_makefiles_dtrace.make,v 1.1 2015/07/03 20:40:59 fhajny Exp $

Enable DTrace support with GCC.

--- hotspot/make/solaris/makefiles/dtrace.make.orig	2015-06-10 10:31:44.000000000 +0000
+++ hotspot/make/solaris/makefiles/dtrace.make
@@ -29,13 +29,6 @@
 
 ifneq ("${TYPE}", "CORE")
 
-ifdef USE_GCC
-
-dtraceCheck:
-	$(QUIETLY) echo "**NOTICE** Dtrace support disabled for gcc builds"
-
-else
-
 JVM_DB = libjvm_db
 LIBJVM_DB = libjvm_db.so
 
@@ -56,14 +49,23 @@ DTRACE_SRCDIR = $(GAMMADIR)/src/os/$(Pla
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
@@ -352,8 +354,6 @@ dtraceCheck:
 
 endif # ifneq ("${dtraceFound}", "")
 
-endif # ifdef USE_GCC
-
 else # CORE build
 
 dtraceCheck:
