$NetBSD: patch-security_coreconf_Linux.mk,v 1.1 2012/05/07 03:22:36 sbd Exp $

Apply attachment 543716 from 
https://bugzilla.mozilla.org/show_bug.cgi?id=661609
to fix building on Linux 3.0 and up.

--- security/coreconf/Linux.mk.orig	2012-05-07 02:03:05.764485874 +0000
+++ security/coreconf/Linux.mk
@@ -192,3 +192,18 @@ RPATH = -Wl,-rpath,'$$ORIGIN:/opt/sun/pr
 endif
 endif
 
+OS_REL_CFLAGS   += -DLINUX2_1
+MKSHLIB         = $(CC) $(DSO_LDOPTS) -Wl,-soname -Wl,$(@:$(OBJDIR)/%.so=%.so) $(RPATH)
+
+ifdef MAPFILE
+	MKSHLIB += -Wl,--version-script,$(MAPFILE)
+endif
+PROCESS_MAP_FILE = grep -v ';-' $< | \
+        sed -e 's,;+,,' -e 's; DATA ;;' -e 's,;;,,' -e 's,;.*,;,' > $@
+
+ifeq ($(OS_RELEASE),2.4)
+# Softoken 3.13 uses NO_FORK_CHECK only.
+# Softoken 3.12 uses NO_FORK_CHECK and NO_CHECK_FORK.
+# Don't use NO_CHECK_FORK in new code.
+DEFINES += -DNO_FORK_CHECK -DNO_CHECK_FORK
+endif
