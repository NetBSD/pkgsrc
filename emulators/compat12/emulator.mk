# $NetBSD: emulator.mk,v 1.1 2007/08/21 22:49:05 jlam Exp $
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
# OPSYS_EMULDIR
#       Path through which the platform expects to find a "chroot"
#       installation of the files and directories, e.g. /emul/aout.
#
# DEPENDS_${EMUL_DISTRO}.*
#	A table that maps "modules" to NetBSD package dependencies.
#

EMUL_DISTRO=		netbsd-1.2

# i386 and sparc switched from a.out to ELF post-1.4.
# arm, m68k and vax switched from a.out to ELF post-1.5.
# ns32k never switched from a.out.
#
.if (${EMUL_ARCH} == "arm") || (${EMUL_ARCH} == "i386") || \
    (${EMUL_ARCH} == "m68k") || (${EMUL_ARCH} == "ns32k") || \
    (${EMUL_ARCH} == "sparc") || (${EMUL_ARCH} == "vax")
EMUL_EXEC_FMT=		a.out
.else
EMUL_EXEC_FMT=		ELF
.endif

.if (${NATIVE_EXEC_FMT} == "ELF") && (${EMUL_EXEC_FMT} == "a.out")
EMULSUBDIR=		emul/aout
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.aout}
.else
EMULSUBDIR=		emul/netbsd
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.netbsd}
.endif

# We need a dependency only for NetBSD>=1.3.
.if empty(OS_VERSION:M0.[0-9]*) && empty(OS_VERSION:M1.[0-1]*) && \
    empty(OS_VERSION:M1.2) && empty(OS_VERSION:M1.2.*)
DEPENDS_netbsd-1.2.base?=	compat12>=1.2:../../emulators/compat12
.endif
