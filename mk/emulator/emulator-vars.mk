# $NetBSD: emulator-vars.mk,v 1.5 2007/08/21 22:49:33 jlam Exp $
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
# EMUL_DISTRO
#	The distribution of the emulated operating system being used,
#	e.g. native-linux, suse-10.0, etc.  If the package isn't
#	supported on this machine, then its value is "none".
#
# EMULDIR
#	Convenience variable that expands to ${PREFIX}/${EMULSUBDIR}
#
# EMULSUBDIR
#       Path relative to ${PREFIX} where the files and directories
#       are located, e.g. emul/linux.
#
# OPSYS_EMULDIR
#       Path through which the platform expects to find a "chroot"
#       installation of the files and directories, e.g. /emul/linux.
#

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
.if !empty(MACHINE_PLATFORM:MNetBSD-1.*-sparc*)
_EMUL_PREFER.netbsd-sparc=	sunos-sparc
.else
_EMUL_PREFER.netbsd-sparc=	solaris-sparc sunos-sparc
.endif
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

# _EMUL_RUN_LDCONFIG
#	This is YesNo variable that is modified by makefiles in the
#	emulator framework.  This is used as the default value of
#	RUN_LDCONFIG by any package that uses the emulator framework.
#	
#	Default value: no
#
_EMUL_RUN_LDCONFIG=	no

.if ${EMUL_PLATFORM} == "none"
EMUL_ARCH?=		none
EMUL_OPSYS?=		none
EMUL_DISTRO?=		none
EMULSUBDIR?=		# empty
EMULDIR?=		${PREFIX}
OPSYS_EMULDIR?=		# empty
.else
EMUL_ARCH?=		${EMUL_PLATFORM:C/.*-//}
EMUL_OPSYS?=		${EMUL_PLATFORM:C/-.*//}
.  include "../../mk/emulator/${EMUL_OPSYS}.mk"
.endif
