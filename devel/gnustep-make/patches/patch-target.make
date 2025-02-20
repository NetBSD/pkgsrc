$NetBSD: patch-target.make,v 1.2 2025/02/20 14:34:52 manu Exp $

Prefer SUBST_VARS instead of SUBST_SED since mk/scripts/subst-identity.awk
seems to be broken on FreeBSD.

--- target.make.orig	2025-02-10 16:22:04.000000000 +0100
+++ target.make	2025-02-18 15:59:18.064294492 +0100
@@ -626,9 +626,9 @@
 # NetBSD (ELF)
 #
 ifeq ($(findstring netbsd, $(GNUSTEP_TARGET_OS)), netbsd)
 HAVE_SHARED_LIBS    = yes
-SHARED_LD_POSTFLAGS = -Wl,-R/usr/pkg/lib -L/usr/pkg/lib
+SHARED_LD_POSTFLAGS = -Wl,-R@PREFIX@/lib -L@PREFIX@/lib
 SHARED_LIB_LINK_CMD = \
 	$(LD) -shared -Wl,-soname,$(LIB_LINK_VERSION_FILE) \
               $(ALL_LDFLAGS) -o $(LIB_LINK_OBJ_DIR)/$(LIB_LINK_VERSION_FILE) \
                  $^ $(INTERNAL_LIBRARIES_DEPEND_UPON) \
@@ -659,9 +659,9 @@
 # DragonFly
 #
 ifeq ($(findstring dragonfly, $(GNUSTEP_TARGET_OS)), dragonfly)
 HAVE_SHARED_LIBS    = yes
-SHARED_LD_POSTFLAGS = -Wl,-R/usr/pkg/lib -L/usr/pkg/lib
+SHARED_LD_POSTFLAGS = -Wl,-R@PREFIX@/lib -L@PREFIX@/lib
 SHARED_LIB_LINK_CMD = \
 	$(LD) -shared -Wl,-soname,$(LIB_LINK_VERSION_FILE) \
               $(ALL_LDFLAGS) -o $(LIB_LINK_OBJ_DIR)/$(LIB_LINK_VERSION_FILE) \
                  $^ $(INTERNAL_LIBRARIES_DEPEND_UPON) \
@@ -677,11 +677,11 @@
 
 HAVE_BUNDLES	= yes
 BUNDLE_LD	= $(LD)
 BUNDLE_LDFLAGS	+= -shared
-ADDITIONAL_LDFLAGS += -Wl,-R/usr/pkg/lib -L/usr/pkg/lib -Wl,-R/usr/X11R6/lib -L/usr/X11R6/lib
+ADDITIONAL_LDFLAGS += -Wl,-R@PREFIX@/lib -L@PREFIX@/lib -Wl,-R/usr/X11R6/lib -L/usr/X11R6/lib
 FINAL_LDFLAGS   = -rdynamic
-ADDITIONAL_INCLUDE_DIRS += -I/usr/pkg/include
+ADDITIONAL_INCLUDE_DIRS += -I@PREFIX@/include
 STATIC_LDFLAGS += -static
 endif
 #
 # end DragonFly
