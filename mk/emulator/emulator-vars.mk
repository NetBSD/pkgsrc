# $NetBSD: emulator-vars.mk,v 1.9 2015/09/08 11:36:34 jperkin Exp $
#
# This file is included by bsd.prefs.mk only if EMUL_PLATFORMS is defined
# and non-empty.
#
# User-settable variables:
#
# EMUL_TYPE.${EMUL_OPSYS}
#	Specifies the "type" or "variant" of ${EMUL_OPSYS} to use, e.g.
#	${EMUL_TYPE.linux} == "suse".
#
# EMUL_PLATFORM
#	Specifies the platform to emulate, and is of the form
#	${EMUL_OPSYS}-${EMUL_ARCH}, e.g. linux-i386.  By default
#	this is the best-matching platform listed in EMUL_PLATFORMS
#	chosen based on EMUL_PREFER.
#
# EMUL_PREFER
#	The list of platforms to try to emulate in order of preference.
#	By default, only try to emulate the native platform.  See the
#	_EMUL_PREFER.* table below for additional preferences for various
#	platforms.
#
# Package-settable variables:
#
# EMUL_PLATFORMS
#	List of "${EMUL_OPSYS}-${EMUL_ARCH}" binary emulations supported
#	by the package.  This should be set prior to the inclusion of
#	bsd.prefs.mk.
#
#	Default value: undefined
#
# Variables defined by this file:
#
# EMUL_ARCH
#	The machine architecture being emulated, e.g. i386.  If the
#	package isn't supported on this machine, then its value is
#	"none".
#
# EMUL_OPSYS
#	The operating system being emulated, e.g. linux.  If the
#	package isn't supported on this machine, then its value is
#	"none".
#
# EMUL_IS_NATIVE
#	Whether or not the operating system being emulated matches the
#	native operating system.  It is either defined or undefined.
#

_VARGROUPS+=		emulator
_USER_VARS.emulator=	EMUL_TYPE.${EMUL_OPSYS} EMUL_PLATFORM EMUL_PREFER
_PKG_VARS.emulator=	EMUL_PLATFORMS
_SYS_VARS.emulator=	EMUL_ARCH EMUL_OPSYS EMUL_IS_NATIVE

# _EMUL_OPSYS
#	A table that maps ${OPSYS} to the operating system names
#	(${EMUL_OPSYS}) used by the emulator framework.
#
# _EMUL_MACHINE_PLATFORM
#	An "opsys-arch" pair that describes the "native" platform.
#
# _EMUL_PREFER.*
#	A table that maps ${_EMUL_MACHINE_PLATFORM} to a list of
#	platforms to try to emulate on the native platform, excluding
#	itself.
#
_EMUL_OPSYS.HPUX=	hpux
_EMUL_OPSYS.IRIX=	irix
_EMUL_OPSYS.OSF1=	osf1
.if !empty(OS_VERSION:M4.*)
_EMUL_OPSYS.SunOS=	sunos
.else
_EMUL_OPSYS.SunOS=	solaris
.endif
.if defined(_EMUL_OPSYS.${OPSYS})
_EMUL_OPSYS=		${_EMUL_OPSYS.${OPSYS}}
.else
_EMUL_OPSYS=		${LOWER_OPSYS}
.endif

_EMUL_MACHINE_PLATFORM=	${_EMUL_OPSYS}-${MACHINE_ARCH}

_EMUL_PREFER.netbsd-alpha=	osf1-alpha linux-alpha
_EMUL_PREFER.netbsd-arm=	linux-arm
_EMUL_PREFER.netbsd-i386=	linux-i386 freebsd-i386 solaris-i386 darwin-i386
_EMUL_PREFER.netbsd-m68k=	sunos-m68k linux-m68k
_EMUL_PREFER.netbsd-powerpc=	linux-powerpc darwin-powerpc
_EMUL_PREFER.netbsd-sparc64=	netbsd-sparc solaris-sparc64 solaris-sparc sunos-sparc
_EMUL_PREFER.netbsd-sparc=	solaris-sparc sunos-sparc
_EMUL_PREFER.netbsd-x86_64=	netbsd-i386 linux-x86_64 linux-i386

_EMUL_PREFER.dragonfly-i386=	linux-i386

_EMUL_PREFER.solaris-sparc64=	solaris-sparc
_EMUL_PREFER.solaris-x86_64=	solaris-i386

_EMUL_PREFER.linux-sparc64=	linux-sparc
_EMUL_PREFER.linux-x86_64=	linux-i386

# Prefer "emulating" the native operating system, then fall back to
# the other preferences listed above.
#
EMUL_PREFER?=		${_EMUL_MACHINE_PLATFORM}			\
			${_EMUL_PREFER.${_EMUL_MACHINE_PLATFORM}}

.for _platform_ in ${EMUL_PREFER}
.  if !empty(EMUL_PLATFORMS:M${_platform_})
EMUL_PLATFORM?=		${_platform_}
.  endif
.endfor
EMUL_PLATFORM?=		none

.if ${EMUL_PLATFORM} == "none"
EMUL_ARCH?=		none
EMUL_OPSYS?=		none
.else
EMUL_ARCH?=		${EMUL_PLATFORM:C/.*-//}
EMUL_OPSYS?=		${EMUL_PLATFORM:C/-.*//}
.endif

.if ${_EMUL_OPSYS} == ${EMUL_OPSYS}
EMUL_IS_NATIVE=		defined
.endif
