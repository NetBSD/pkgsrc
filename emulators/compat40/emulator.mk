# $NetBSD: emulator.mk,v 1.1 2007/12/31 20:06:40 jlam Exp $
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

EMUL_DISTRO=		netbsd-4.0

EMUL_EXEC_FMT=		ELF
EMULSUBDIR=		emul/netbsd
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.netbsd}

# For COMPAT_NETBSD32, we always need the dependency to supply 32-bit
# shared libaries for NetBSD-4.0.
#
.if ((${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")) || \
    ((${EMUL_ARCH} == "sparc") && (${MACHINE_ARCH} == "sparc64"))
EMULSUBDIR=		emul/netbsd32
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.netbsd32}

DEPENDS_netbsd-4.0.base?=	netbsd32_compat40>=4.0:../../emulators/netbsd32_compat40
#
# We need to depend on the compat40 package to supply missing shared
# libraries only on NetBSD>4.0.
#
.elif empty(OS_VERSION:M[0-3].*) && empty(OS_VERSION:M4.[0-9]) && \
      empty(OS_VERSION:M4.[0-9].*) && empty(OS_VERSION:M4.[1-8][0-9].*) && \
      empty(OS_VERSION:M4.9[0-8]*)
DEPENDS_netbsd-4.0.base?=	compat40>=4.0:../../emulators/compat40
.endif
