$NetBSD: patch-target.make,v 1.1 2020/11/03 11:24:31 triaxx Exp $

Prefer SUBST_VARS instead of SUBST_SED since mk/scripts/subst-identity.awk
seems to be broken on FreeBSD.

--- target.make.orig	2020-04-05 14:59:54.000000000 +0000
+++ target.make
@@ -591,7 +591,7 @@ endif
 #
 ifeq ($(findstring netbsd, $(GNUSTEP_TARGET_OS)), netbsd)
 HAVE_SHARED_LIBS    = yes
-SHARED_LD_POSTFLAGS = -Wl,-R/usr/pkg/lib -L/usr/pkg/lib
+SHARED_LD_POSTFLAGS = -Wl,-R@PREFIX@/lib -L@PREFIX@/lib
 SHARED_LIB_LINK_CMD = \
 	$(LD) -shared -Wl,-soname,$(LIB_LINK_VERSION_FILE) \
               $(ALL_LDFLAGS) -o $(LIB_LINK_OBJ_DIR)/$(LIB_LINK_VERSION_FILE) \
@@ -624,7 +624,7 @@ endif
 #
 ifeq ($(findstring dragonfly, $(GNUSTEP_TARGET_OS)), dragonfly)
 HAVE_SHARED_LIBS    = yes
-SHARED_LD_POSTFLAGS = -Wl,-R/usr/pkg/lib -L/usr/pkg/lib
+SHARED_LD_POSTFLAGS = -Wl,-R@PREFIX@/lib -L@PREFIX@/lib
 SHARED_LIB_LINK_CMD = \
 	$(LD) -shared -Wl,-soname,$(LIB_LINK_VERSION_FILE) \
               $(ALL_LDFLAGS) -o $(LIB_LINK_OBJ_DIR)/$(LIB_LINK_VERSION_FILE) \
@@ -642,8 +642,8 @@ SHARED_LIBEXT	= .so
 HAVE_BUNDLES	= yes
 BUNDLE_LD	= $(LD)
 BUNDLE_LDFLAGS	+= -shared
-ADDITIONAL_LDFLAGS += -rdynamic -Wl,-R/usr/pkg/lib -L/usr/pkg/lib -Wl,-R/usr/X11R6/lib -L/usr/X11R6/lib
-ADDITIONAL_INCLUDE_DIRS += -I/usr/pkg/include
+ADDITIONAL_LDFLAGS += -rdynamic -Wl,-R@PREFIX@/lib -L@PREFIX@/lib -Wl,-R/usr/X11R6/lib -L/usr/X11R6/lib
+ADDITIONAL_INCLUDE_DIRS += -I@PREFIX@/include
 STATIC_LDFLAGS += -static
 endif
 #
