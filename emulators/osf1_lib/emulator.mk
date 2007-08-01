# $NetBSD: emulator.mk,v 1.1 2007/08/01 17:19:23 jlam Exp $
#
# This file is included by osf1-netscape.mk in the emulator framework.
#
# Variables set by this file:
#
# EMUL_DISTRO
#	The OSF/1 distribution.
#

EMUL_DISTRO=		osf1-netscape-1.1

# The OSF/1 emulation supports no modules, so always depend on osf1_lib.
.if !defined(OSF1_PKG)
DEPENDS+=		osf1_lib>=1.1:../../emulators/osf1_lib
.endif
