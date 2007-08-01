# $NetBSD: emulator.mk,v 1.1 2007/08/01 16:28:08 jlam Exp $
#
# This file is included by darwin-opendarwin.mk in the emulator framework.
#
# Variables set by this file:
#
# EMUL_DISTRO
#	The OpenDarwin distribution.
#

EMUL_DISTRO=		opendarwin-6.6.2

# The Darwin emulation supports no modules, so always depend on darwin_lib.
.if !defined(DARWIN_PKG)
DEPENDS+=		darwin_lib>=6.6.2:../../emulators/darwin_lib
.endif
