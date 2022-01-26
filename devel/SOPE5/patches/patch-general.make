$NetBSD: patch-general.make,v 1.2 2022/01/26 16:41:45 tm Exp $

Don't include command line in output.
Add missing linker flag objc in general.make because env or pkgsrc
LDFLAGS are not working.

--- general.make.orig	Tue Jan 18 16:17:06 2022
+++ general.make	Wed Jan 26 16:19:05 2022
@@ -23,5 +23,8 @@
 # information plus the compiler flags used; that can
 # be afterwards read with:
 # readelf -p .GCC.command.line /path/to/elf_file
-ADDITIONAL_OBJCFLAGS += -g $(call cc-option,-frecord-gcc-switches)
-
+ADDITIONAL_OBJCFLAGS += -g
+# Ensure linking to objc works correctly. Because the
+# env or pkgsrc variable LDFLAGS isn't working it's
+# required configure it here:
+ADDITIONAL_LDFLAGS += -lobjc
