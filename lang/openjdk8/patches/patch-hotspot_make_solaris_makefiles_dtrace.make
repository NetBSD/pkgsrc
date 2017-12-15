$NetBSD: patch-hotspot_make_solaris_makefiles_dtrace.make,v 1.2 2017/12/15 14:27:52 jperkin Exp $

Enable DTrace support with GCC.

--- hotspot/make/solaris/makefiles/dtrace.make.orig	2017-11-28 00:13:38.000000000 +0000
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
@@ -99,7 +101,7 @@ XLIBJVM_DTRACE_DIZ         = $(XLIBJVM_D
 $(XLIBJVM_DB): $(DTRACE_SRCDIR)/$(JVM_DB).c $(JVMOFFS).h $(LIBJVM_DB_MAPFILE)
 	@echo Making $@
 	$(QUIETLY) mkdir -p $(XLIBJVM_DIR) ; \
-	$(CC) $(SYMFLAG) $(ARCHFLAG/$(ISA)) -D$(TYPE) -I. -I$(GENERATED) \
+	$(CC) $(CFLAGS) $(SYMFLAG) $(ARCHFLAG/$(ISA)) -D$(TYPE) -I. -I$(GENERATED) \
 		$(SHARED_FLAG) $(LFLAGS_JVM_DB) -o $@ $(DTRACE_SRCDIR)/$(JVM_DB).c -lc
 ifeq ($(ENABLE_FULL_DEBUG_SYMBOLS),1)
 	$(QUIETLY) $(OBJCOPY) --only-keep-debug $@ $(XLIBJVM_DB_DEBUGINFO)
@@ -125,7 +127,7 @@ endif
 $(XLIBJVM_DTRACE): $(DTRACE_SRCDIR)/$(JVM_DTRACE).c $(DTRACE_SRCDIR)/$(JVM_DTRACE).h $(LIBJVM_DTRACE_MAPFILE)
 	@echo Making $@
 	$(QUIETLY) mkdir -p $(XLIBJVM_DIR) ; \
-	$(CC) $(SYMFLAG) $(ARCHFLAG/$(ISA)) -D$(TYPE) -I. \
+	$(CC) $(CFLAGS) $(SYMFLAG) $(ARCHFLAG/$(ISA)) -D$(TYPE) -I. \
 		$(SHARED_FLAG) $(LFLAGS_JVM_DTRACE) -o $@ $(DTRACE_SRCDIR)/$(JVM_DTRACE).c -lc -lthread -ldoor
 ifeq ($(ENABLE_FULL_DEBUG_SYMBOLS),1)
 	$(QUIETLY) $(OBJCOPY) --only-keep-debug $@ $(XLIBJVM_DTRACE_DEBUGINFO)
@@ -190,7 +192,7 @@ $(JVMOFFS.o): $(JVMOFFS).h $(JVMOFFS).cp
 
 $(LIBJVM_DB): $(DTRACE_SRCDIR)/$(JVM_DB).c $(JVMOFFS.o) $(XLIBJVM_DB) $(LIBJVM_DB_MAPFILE)
 	@echo Making $@
-	$(QUIETLY) $(CC) $(SYMFLAG) $(ARCHFLAG) -D$(TYPE) -I. -I$(GENERATED) \
+	$(QUIETLY) $(CC) $(CFLAGS) $(SYMFLAG) $(ARCHFLAG) -D$(TYPE) -I. -I$(GENERATED) \
 		$(SHARED_FLAG) $(LFLAGS_JVM_DB) -o $@ $(DTRACE_SRCDIR)/$(JVM_DB).c -lc
 ifeq ($(ENABLE_FULL_DEBUG_SYMBOLS),1)
 	$(QUIETLY) $(OBJCOPY) --only-keep-debug $@ $(LIBJVM_DB_DEBUGINFO)
@@ -211,7 +213,7 @@ endif
 
 $(LIBJVM_DTRACE): $(DTRACE_SRCDIR)/$(JVM_DTRACE).c $(XLIBJVM_DTRACE) $(DTRACE_SRCDIR)/$(JVM_DTRACE).h $(LIBJVM_DTRACE_MAPFILE)
 	@echo Making $@
-	$(QUIETLY) $(CC) $(SYMFLAG) $(ARCHFLAG) -D$(TYPE) -I.  \
+	$(QUIETLY) $(CC) $(CFLAGS) $(SYMFLAG) $(ARCHFLAG) -D$(TYPE) -I.  \
 		$(SHARED_FLAG) $(LFLAGS_JVM_DTRACE) -o $@ $(DTRACE_SRCDIR)/$(JVM_DTRACE).c -lc -lthread -ldoor
 ifeq ($(ENABLE_FULL_DEBUG_SYMBOLS),1)
 	$(QUIETLY) $(OBJCOPY) --only-keep-debug $@ $(LIBJVM_DTRACE_DEBUGINFO)
@@ -352,8 +354,6 @@ dtraceCheck:
 
 endif # ifneq ("${dtraceFound}", "")
 
-endif # ifdef USE_GCC
-
 else # CORE build
 
 dtraceCheck:
