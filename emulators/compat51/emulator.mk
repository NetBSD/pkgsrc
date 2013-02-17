# $NetBSD: emulator.mk,v 1.1 2013/02/17 17:24:08 spz Exp $
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

EMUL_DISTRO=		netbsd-5.1

EMUL_EXEC_FMT=		ELF
EMULSUBDIR=		emul/netbsd
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.netbsd}

.if empty(OS_VERSION:M[0-4].*) && empty(OS_VERSION:M5.[012].*)
DEPENDS_netbsd-5.1.base?=	compat51>=5.1:../../emulators/compat51
.endif
