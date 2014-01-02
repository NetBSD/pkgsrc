$NetBSD: patch-hotspot_make_solaris_makefiles_gcc.make,v 1.3 2014/01/02 01:16:35 ryoon Exp $

GCC support.

Disable SunOS multiarch.

--- hotspot/make/solaris/makefiles/gcc.make.orig	2014-01-01 05:50:04.000000000 +0000
+++ hotspot/make/solaris/makefiles/gcc.make
@@ -70,11 +70,23 @@ VM_PICFLAG/LIBJVM = $(PICFLAG)
 VM_PICFLAG/AOUT   =
 VM_PICFLAG        = $(VM_PICFLAG/$(LINK_INTO))
 
+ifeq ($(JVM_VARIANT_ZERO), true)
+  CFLAGS += $(LIBFFI_CFLAGS)
+endif
+ifeq ($(JVM_VARIANT_ZEROSHARK), true)
+  CFLAGS += $(LIBFFI_CFLAGS)
+  CFLAGS += $(LLVM_CFLAGS)
+endif
 CFLAGS += $(VM_PICFLAG)
 CFLAGS += -fno-rtti
 CFLAGS += -fno-exceptions
 CFLAGS += -D_REENTRANT
 CFLAGS += -fcheck-new
+# version 4 and above support fvisibility=hidden (matches jni_x86.h file)
+# except 4.1.2 gives pointless warnings that can't be disabled (afaik)
+ifneq "$(shell expr \( $(CC_VER_MAJOR) \> 4 \) \| \( \( $(CC_VER_MAJOR) = 4 \) \& \( $(CC_VER_MINOR) \>= 3 \) \))" "0"
+  CFLAGS += -fvisibility=hidden
+endif
 
 ARCHFLAG = $(ARCHFLAG/$(BUILDARCH))
 
@@ -86,7 +98,8 @@ ARCHFLAG/amd64   = -m64 -march=k8
 
 # Optional sub-directory in /usr/lib where BUILDARCH libraries are kept.
 ISA_DIR=$(ISA_DIR/$(BUILDARCH))
-ISA_DIR/amd64=/amd64
+ISA_DIR/amd64=
+NOMULTIARCHISA_DIR/amd64=/amd64
 ISA_DIR/i486=
 ISA_DIR/sparcv9=/64
 
@@ -107,6 +120,11 @@ ifdef CC_INTERP
   CFLAGS += -DCC_INTERP
 endif
 
+# Build for embedded targets
+ifdef JAVASE_EMBEDDED
+  CFLAGS += -DJAVASE_EMBEDDED
+endif
+
 # Keep temporary files (.ii, .s)
 ifdef NEED_ASM
   CFLAGS += -save-temps
@@ -117,9 +135,18 @@ endif
 
 # Compiler warnings are treated as errors 
 WARNINGS_ARE_ERRORS = -Werror 
-# Enable these warnings. See 'info gcc' about details on these options
-ADDITIONAL_WARNINGS = -Wpointer-arith -Wconversion -Wsign-compare 
-CFLAGS_WARN/DEFAULT = $(WARNINGS_ARE_ERRORS) $(ADDITIONAL_WARNINGS) 
+
+# Except for a few acceptable ones
+# Since GCC 4.3, -Wconversion has changed its meanings to warn these implicit
+# conversions which might affect the values. To avoid that, we need to turn
+# it off explicitly. 
+ifneq "$(shell expr \( $(CC_VER_MAJOR) \> 4 \) \| \( \( $(CC_VER_MAJOR) = 4 \) \& \( $(CC_VER_MINOR) \>= 3 \) \))" "0"
+  ACCEPTABLE_WARNINGS = -Wpointer-arith -Wsign-compare
+else
+  ACCEPTABLE_WARNINGS = -Wpointer-arith -Wconversion -Wsign-compare
+endif
+
+CFLAGS_WARN/DEFAULT = $(WARNINGS_ARE_ERRORS) $(ACCEPTABLE_WARNINGS)
 # Special cases 
 CFLAGS_WARN/BYFILE = $(CFLAGS_WARN/$@)$(CFLAGS_WARN/DEFAULT$(CFLAGS_WARN/$@))  
 
@@ -177,7 +204,7 @@ MAPFLAG = -Xlinker -M -Xlinker FILENAME 
 endif 
 
 # Use $(SONAMEFLAG:SONAME=soname) to specify the intrinsic name of a shared obj
-SONAMEFLAG = -Xlinker -soname=SONAME
+SONAMEFLAG = -Wl,-soname=SONAME
 
 # Build shared library
 SHARED_FLAG = -shared
@@ -185,15 +212,32 @@ SHARED_FLAG = -shared
 #------------------------------------------------------------------------
 # Debug flags
 
-# Use the stabs format for debugging information (this is the default 
-# on gcc-2.91). It's good enough, has all the information about line 
-# numbers and local variables, and libjvm_g.so is only about 16M. 
-# Change this back to "-g" if you want the most expressive format. 
-# (warning: that could easily inflate libjvm_g.so to 150M!) 
-# Note: The Itanium gcc compiler crashes when using -gstabs. 
-DEBUG_CFLAGS/ia64  = -g 
-DEBUG_CFLAGS/amd64 = -g 
-DEBUG_CFLAGS += $(DEBUG_CFLAGS/$(BUILDARCH)) 
-ifeq ($(DEBUG_CFLAGS/$(BUILDARCH)),) 
-DEBUG_CFLAGS += -gstabs 
-endif 
+# DEBUG_BINARIES uses full -g debug information for all configs
+ifeq ($(DEBUG_BINARIES), true)
+  CFLAGS += -g
+else
+# Use the stabs format for debugging information (this is the default
+# on gcc-2.91). It's good enough, has all the information about line
+# numbers and local variables, and libjvm_g.so is only about 16M.
+# Change this back to "-g" if you want the most expressive format.
+# (warning: that could easily inflate libjvm_g.so to 150M!)
+# Note: The Itanium gcc compiler crashes when using -gstabs.
+DEBUG_CFLAGS/ia64  = -g
+DEBUG_CFLAGS/amd64 = -g
+DEBUG_CFLAGS += $(DEBUG_CFLAGS/$(BUILDARCH))
+ifeq ($(DEBUG_CFLAGS/$(BUILDARCH)),)
+DEBUG_CFLAGS += -gstabs
+endif
+endif
+
+# If we are building HEADLESS, pass on to VM
+# so it can set the java.awt.headless property
+ifdef HEADLESS
+  CFLAGS += -DHEADLESS
+endif
+
+# We are building Embedded for a small device
+# favor code space over speed
+ifdef MINIMIZE_RAM_USAGE
+  CFLAGS += -DMINIMIZE_RAM_USAGE
+endif
