#	$NetBSD: netbsd.mk,v 1.2 1998/08/12 18:58:09 tv Exp $

# Definitions for building a cross-compile environment for a NetBSD target.

# If the MACHINE_ARCH matches the package target, we can use a special
# "shortcut" hack that makes use of the native compiler with a bundle of
# includes and libraries for the target version of NetBSD.  Otherwise, or
# if USE_EGCS_FOR_NATIVE is set in mk.conf, we use the standard egcs+binutils
# cross setup.  (For now, we just use egcs.)

#.include "../../mk/bsd.prefs.mk"
#.if defined(USE_EGCS_FOR_NATIVE) || (${MACHINE_ARCH} != ${TARGET_ARCH})
.include "../COMMON/cross.mk"
#.else
#.endif
