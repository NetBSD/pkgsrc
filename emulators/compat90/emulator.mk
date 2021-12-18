# $NetBSD: emulator.mk,v 1.1 2021/12/18 01:01:33 he Exp $
#
# This file is included by netbsd-compat.mk in the emulator framework.
#
# Variables set by this file:
#
# EMUL_DISTRO
#	The NetBSD distribution used to provide the files.
#
# EMUL_EXEC_FMT
#	The executable format of the emulated operating system.
#
# EMULSUBDIR
#	Path relative to ${PREFIX} where the files and directories are
#	located, e.g. emul/aout.
#
# DEPENDS_${EMUL_DISTRO}.*
#	A table that maps "modules" to NetBSD package dependencies.
#

EMUL_DISTRO=		netbsd-9.99.82

EMUL_EXEC_FMT=		ELF
EMULSUBDIR=		emul/netbsd
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.netbsd}

#.if empty(OS_VERSION:M[0-5].*) && empty(OS_VERSION:M6.1*)
#DEPENDS_netbsd-9.1.base?=	compat61>=6.1:../../emulators/compat61
#.endif
