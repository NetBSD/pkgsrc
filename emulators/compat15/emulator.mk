# $NetBSD: emulator.mk,v 1.1 2007/08/21 22:49:13 jlam Exp $
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

EMUL_DISTRO=		netbsd-1.5

# arm, m68k and vax switched from a.out to ELF post-1.5.
# ns32k never switched from a.out.
#
.if (${EMUL_ARCH} == "arm") || (${EMUL_ARCH} == "m68k") || \
    (${EMUL_ARCH} == "ns32k") || (${EMUL_ARCH} == "vax")
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

# For COMPAT_NETBSD32, we always need the dependency to supply 32-bit
# shared libaries for NetBSD-1.5.
#
.if ((${EMUL_ARCH} == "i386") && (${MACHINE_ARCH} == "x86_64")) || \
    ((${EMUL_ARCH} == "sparc") && (${MACHINE_ARCH} == "sparc64"))
EMULSUBDIR=		emul/netbsd32
OPSYS_EMULDIR=		${_OPSYS_EMULDIR.netbsd32}

DEPENDS_netbsd-1.5.base?=	netbsd32_compat15>=1.5:../../emulators/netbsd32_compat15
#
# We need to depend on the compat15 package to supply missing shared
# libraries only on NetBSD>1.5.
#
.elif empty(OS_VERSION:M0.[0-9]*) && empty(OS_VERSION:M1.[0-4]*) && \
      empty(OS_VERSION:M1.5) && empty(OS_VERSION:M1.5.*)
DEPENDS_netbsd-1.5.base?=	compat15>=1.5:../../emulators/compat15
.endif
