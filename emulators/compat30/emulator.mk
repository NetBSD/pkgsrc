# $NetBSD: emulator.mk,v 1.1 2007/08/21 22:49:23 jlam Exp $
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

EMUL_DISTRO=		netbsd-3.0

EMUL_EXEC_FMT=		ELF
EMULSUBDIR=		emul/netbsd
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.netbsd}

# For COMPAT_NETBSD32, we always need the dependency to supply 32-bit
# shared libaries for NetBSD-3.0.
#
.if ((${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")) || \
    ((${EMUL_ARCH} == "sparc") && (${MACHINE_ARCH} == "sparc64"))
EMULSUBDIR=		emul/netbsd32
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.netbsd32}

DEPENDS_netbsd-3.0.base?=	netbsd32_compat30>=3.0:../../emulators/netbsd32_compat30
#
# We need to depend on the compat30 package to supply missing shared
# libraries only on NetBSD>3.0.
#
.elif empty(OS_VERSION:M[0-2].*) && empty(OS_VERSION:M3.[0-9]) && \
      empty(OS_VERSION:M3.[0-9].*) && empty(OS_VERSION:M3.[1-8][0-9].*) && \
      empty(OS_VERSION:M3.9[0-8]*)
DEPENDS_netbsd-3.0.base?=	compat30>=3.0:../../emulators/compat30
.endif
