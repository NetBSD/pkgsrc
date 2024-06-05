# $NetBSD: bsd.prefs.mk,v 1.449 2024/06/05 17:17:21 riastradh Exp $
#
# This file includes the mk.conf file, which contains the user settings.
#
# Packages should include this file before any of the .if directives, as
# well as before modifying variables like CFLAGS, LDFLAGS, and so on.
# Otherwise the behavior may be unexpected.
#
# When mk.conf is included by this file, the following variables are
# defined:
#
# ACCEPTABLE_LICENSES
#	This variable is set to the list of Open Source licenses. See
#	mk/license.mk for details.
#
# MACHINE_PLATFORM
#	The platform for which the packages are built. It has the form
#	${OPSYS}-${OS_VERSION}-${MACHINE_ARCH}.
#
# NATIVE_MACHINE_PLATFORM
#	The platform on which the packages are built. This is usually
#	the same as ${MACHINE_PLATFORM}, but can be different when
#	cross-building packages.
#
# PKGPATH
#	The path of the package, relative to the pkgsrc top-level
#	directory. Typical values look like editors/emacs or
#	misc/openoffice-bin.
#
# Package-settable variables:
#
# PKGSRC_OVERRIDE_MKPIE
#	When this variable is set to no, MKPIE is enforced by putting toolchain
#	flags into tool wrapper scripts. Setting it to yes prevents that and
#	shifts the responsibility of building PIE from the pkgsrc infrastructure
#	to an individual package.
#
#	Possible values: yes, no
#	Default value: no
#
# Keywords: mk.conf user platform
#

.if !defined(BSD_PKG_MK)

# Let mk.conf know that this is pkgsrc.
BSD_PKG_MK=1
__PREFIX_SET__:=${PREFIX}

# Set PATH if not already set
.if !defined(PATH)
PATH=/bin:/usr/bin:/sbin:/usr/sbin
.endif

# Expand MAKE to a full path.
.if !defined(_MAKE)
_MAKE:=	${MAKE}
# allow for MAKE=./make and similar.
.  if empty(_MAKE:M/*) && !empty(_MAKE:M*/*) && defined(PWD) && exists(${PWD}/${MAKE})
_MAKE:=	${PWD}/${MAKE}
.  endif
.  for _dir_ in ${PATH:C/\:/ /g}
.    if empty(_MAKE:M/*)
.      if exists(${_dir_}/${MAKE})
_MAKE:=	${_dir_}/${MAKE}
.      endif
.    endif
.  endfor
.  if !empty(_MAKE:M/*)
MAKEFLAGS+=	_MAKE=${_MAKE:Q}
.  endif
.endif
MAKE:=	${_MAKE}

# Whether bmake has been called with one of the "clean" targets followed by
# another non-cleaning target like "depends" or "build". This is to make
# the call "bmake clean depends" equivalent to "bmake clean && bmake depends".
_CLEANING:=	${"${.TARGETS:C,( [[:alnum:]-]*clean[[:alnum:]-]*)+$,,W:M*clean*}":?yes:}

.if exists(/usr/bin/uname)
UNAME=/usr/bin/uname
.elif exists(/bin/uname)
UNAME=/bin/uname
.elif exists(/run/current-system/sw/bin/uname)
UNAME=/run/current-system/sw/bin/uname
.else
UNAME=echo Unknown
.endif

.if !defined(NATIVE_OPSYS)
NATIVE_OPSYS:=		${:!${UNAME} -s!:S/-//g:S/\///g:C/^CYGWIN_.*$/Cygwin/}
MAKEFLAGS+=		NATIVE_OPSYS=${NATIVE_OPSYS:Q}
.endif

# OS_VARIANT is used to differentiate operating systems which have a common
# basis but offer contrasting environments, for example Linux distributions
# or illumos forks.
NATIVE_OS_VARIANT?=	# empty

# The _CMD indirection allows code below to modify these values
# without executing the commands at all.  Later, recursed make
# invocations will skip these blocks entirely thanks to MAKEFLAGS.
.if !defined(NATIVE_OS_VERSION)
_NATIVE_OS_VERSION_CMD=	${UNAME} -r
NATIVE_OS_VERSION=	${_NATIVE_OS_VERSION_CMD:sh}
MAKEFLAGS+=		NATIVE_OS_VERSION=${NATIVE_OS_VERSION:Q}
.endif

#
# OPSYS_VERSION differs from OS_VERSION in that it should always evaluate to
# an integer, allowing arithmetic expressions to simplify make(1) tests.  The
# default command is likely correct for most OS, those that need to can set
# it to a custom command in the later OPSYS-specific section.
#
.if !defined(NATIVE_OPSYS_VERSION)
_NATIVE_OPSYS_VERSION_CMD=	${UNAME} -r | \
			awk -F. '{major=int($$1); minor=int($$2); if (minor>=100) minor=99; patch=int($$3); if (patch>=100) patch=99; printf "%02d%02d%02d", major, minor, patch}'
NATIVE_OPSYS_VERSION=	${_NATIVE_OPSYS_VERSION_CMD:sh}
MAKEFLAGS+=		NATIVE_OPSYS_VERSION=${NATIVE_OPSYS_VERSION:Q}
.endif

# Preload these for architectures not in all variations of bsd.own.mk,
# which do not match their GNU names exactly.
GNU_ARCH.aarch64eb?=	aarch64_be
GNU_ARCH.coldfire?=	m5407
GNU_ARCH.arm26?=	arm
GNU_ARCH.arm32?=	arm
GNU_ARCH.amd64?=	x86_64
GNU_ARCH.earm?=		arm
GNU_ARCH.earmhf?=	arm
GNU_ARCH.earmeb?=	armeb
GNU_ARCH.earmhfeb?=	armeb
GNU_ARCH.earmv4?=	armv4
GNU_ARCH.earmv4eb?=	armv4eb
GNU_ARCH.earmv5?=	arm
GNU_ARCH.earmv5eb?=	armeb
GNU_ARCH.earmv6?=	armv6
GNU_ARCH.earmv6hf?=	armv6
GNU_ARCH.earmv6eb?=	armv6eb
GNU_ARCH.earmv6hfeb?=	armv6eb
GNU_ARCH.earmv7?=	armv7
GNU_ARCH.earmv7hf?=	armv7
GNU_ARCH.earmv7eb?=	armv7eb
GNU_ARCH.earmv7hfeb?=	armv7eb
GNU_ARCH.i386?=		i486
GNU_ARCH.i586?=		i486
GNU_ARCH.i686?=		i486
GNU_ARCH.m68000?=	m68010
GNU_ARCH.mips?=		mipsel
GNU_ARCH.sh3eb?=	sh
GNU_ARCH.sh3el?=	shle
GNU_ARCH.mips64eb?=	mips64
NATIVE_MACHINE_GNU_ARCH?=	${GNU_ARCH.${NATIVE_MACHINE_ARCH}:U${NATIVE_MACHINE_ARCH}}
MACHINE_GNU_ARCH?=		${GNU_ARCH.${MACHINE_ARCH}:U${MACHINE_ARCH}}

## If changes are made to how OS_VERSION is set below please keep
## "pkgsrc/pkgtools/osabi/INSTALL" in-sync.
.if ${NATIVE_OPSYS} == "NetBSD"
NATIVE_LOWER_OPSYS?=	netbsd

# Ensure HOST_MACHINE_ARCH is set for native-but-compat builds, such as
# building i386 packages on an amd64 system with compat32 libraries.
# This is not quite a cross-build, so not NATIVE_ or CROSS_ here.
.  if !defined(HOST_MACHINE_ARCH)
HOST_MACHINE_ARCH!=	${UNAME} -m
MAKEFLAGS+=		HOST_MACHINE_ARCH=${HOST_MACHINE_ARCH:Q}
.  endif

.elif ${NATIVE_OPSYS} == "AIX"
.  if exists(/usr/bin/oslevel)
_NATIVE_OS_VERSION!=	/usr/bin/oslevel
.  else
_NATIVE_OS_VERSION!=	echo `${UNAME} -v`.`${UNAME} -r`
.  endif
NATIVE_OS_VERSION=		${_NATIVE_OS_VERSION:C/([0-9]*\.[0-9]*).*/\1/}
NATIVE_LOWER_OPSYS_VERSUFFIX=	${_NATIVE_OS_VERSION}
NATIVE_LOWER_OPSYS?=		aix
NATIVE_LOWER_VENDOR?=		ibm

.elif ${NATIVE_OPSYS} == "BSDOS"
NATIVE_LOWER_OPSYS?=	bsdi

.elif ${NATIVE_OPSYS} == "Cygwin"
NATIVE_LOWER_OPSYS?=	cygwin
NATIVE_LOWER_VENDOR?=	pc
_NATIVE_OS_VERSION!=	${UNAME} -r
NATIVE_OS_VERSION=	${_NATIVE_OS_VERSION:C/\(.*\)//}
NATIVE_OS_VARIANT!=	${UNAME} -s

.elif ${NATIVE_OPSYS} == "Darwin"
NATIVE_LOWER_OPSYS?=		darwin
NATIVE_LOWER_OPSYS_VERSUFFIX=	${NATIVE_OS_VERSION:C/([0-9]*).*/\1/}
NATIVE_LOWER_VENDOR?=		apple
_NATIVE_OPSYS_VERSION_CMD=	sw_vers -productVersion | \
			awk -F. '{major=int($$1); minor=int($$2); if (minor>=100) minor=99; patch=int($$3); if (patch>=100) patch=99; printf "%02d%02d%02d", major, minor, patch}'

.elif ${NATIVE_OPSYS} == "DragonFly"
NATIVE_OS_VERSION:=	${NATIVE_OS_VERSION:C/-.*$//}
NATIVE_LOWER_OPSYS?=	dragonfly
NATIVE_LOWER_VENDOR?=	pc

.elif ${NATIVE_OPSYS} == "FreeBSD"
NATIVE_OS_VERSION:=		${NATIVE_OS_VERSION:C/-.*$//}
NATIVE_LOWER_OPSYS?=		freebsd
NATIVE_LOWER_OPSYS_VERSUFFIX=	${NATIVE_OS_VERSION:C/([0-9]*).*/\1/}
.  if ${MACHINE_ARCH} == "i386"		# pre-NATIVE_MACHINE_ARCH switcheroo
NATIVE_LOWER_VENDOR?=		pc
.  endif
NATIVE_LOWER_VENDOR?=		unknown

.elif ${NATIVE_OPSYS} == "Haiku"
NATIVE_LOWER_OPSYS?=		haiku
.  if ${MACHINE_ARCH} == "i386"		# pre-NATIVE_MACHINE_ARCH switcheroo
NATIVE_LOWER_VENDOR?=		pc
.  endif

.elif ${NATIVE_OPSYS} == "Interix"
NATIVE_LOWER_OPSYS?=		interix
NATIVE_LOWER_VENDOR?=		pc
.  if exists(/usr/lib/libc.so.5.2) || exists(/usr/lib/x86/libc.so.5.2)
NATIVE_LOWER_OPSYS_VERSUFFIX=	${NATIVE_OS_VERSION:C/([0-9]*).*/\1/}
.  else
NATIVE_LOWER_OPSYS_VERSUFFIX?=	3
.    if exists(/usr/lib/libc.so.3.5)
NATIVE_OS_VERSION=		3.5
.    elif exists(/usr/lib/libc.so.3.1)
NATIVE_OS_VERSION=		3.1
.    else
NATIVE_OS_VERSION=		3.0
.    endif
.  endif

.elif ${NATIVE_OPSYS} == "MirBSD"
NATIVE_LOWER_OPSYS?=		mirbsd
NATIVE_LOWER_OPSYS_VERSUFFIX=	${NATIVE_OS_VERSION}
NATIVE_LOWER_VENDOR?=		unknown

.elif !empty(NATIVE_OPSYS:MIRIX*)
NATIVE_LOWER_OPSYS?=		irix
NATIVE_LOWER_OPSYS_VERSUFFIX?=	${NATIVE_OS_VERSION}
NATIVE_LOWER_VENDOR?=		sgi

.elif ${NATIVE_OPSYS} == "Linux"
NATIVE_OS_VERSION:=		${NATIVE_OS_VERSION:C/-.*$//}
NATIVE_LOWER_OPSYS?=		linux
.  if exists(/etc/lsb-release)
CHROMEOS_RELEASE_NAME!=	awk -F = '$$1 == "CHROMEOS_RELEASE_NAME" { print $$2 }' /etc/lsb-release
.  endif
.  if exists(/etc/debian_version)
NATIVE_LOWER_VENDOR?=		debian
.  elif exists(/etc/mandrake-release)
NATIVE_LOWER_VENDOR?=		mandrake
.  elif exists(/etc/redhat-version) || exists(/etc/redhat-release)
NATIVE_LOWER_VENDOR?=		redhat
.  elif exists(/etc/slackware-version)
NATIVE_LOWER_VENDOR?=		slackware
.  elif exists(/etc/ssdlinux_version)
NATIVE_LOWER_VENDOR?=		ssd
.  elif !empty(CHROMEOS_RELEASE_NAME)
NATIVE_LOWER_VENDOR?=		chromeos
.  elif ${MACHINE_ARCH} == "i386"	# pre-NATIVE_MACHINE_ARCH switcheroo
NATIVE_LOWER_VENDOR?=          pc
.  endif
NATIVE_LOWER_VENDOR?=          unknown
NATIVE_OS_VARIANT!=		${UNAME} -r
NATIVE_OS_VARIANT:=		${NATIVE_OS_VARIANT:C/^.*-//}
.  if ${NATIVE_OS_VARIANT} != "Microsoft"
NATIVE_OS_VARIANT=		${NATIVE_LOWER_VENDOR}
.  endif
# Ensure HOST_MACHINE_ARCH is set for native-but-compat builds, such as
# building i386 packages on an amd64 system with compat32 libraries.
# This is not quite a cross-build, so not NATIVE_ or CROSS_ here.
.  if !defined(HOST_MACHINE_ARCH)
HOST_MACHINE_ARCH!=	${UNAME} -m
MAKEFLAGS+=		HOST_MACHINE_ARCH=${HOST_MACHINE_ARCH:Q}
.  endif

.elif ${NATIVE_OPSYS} == "OpenBSD"
NATIVE_LOWER_OPSYS?= 		openbsd

.elif ${NATIVE_OPSYS} == "OSF1"
NATIVE_OS_VERSION:=		${NATIVE_OS_VERSION:C/^V//}
NATIVE_LOWER_OPSYS?=		osf1
NATIVE_LOWER_OPSYS_VERSUFFIX?=	${NATIVE_OS_VERSION}
NATIVE_LOWER_VENDOR?=		dec

.elif ${NATIVE_OPSYS} == "HPUX"
NATIVE_OS_VERSION:=		${NATIVE_OS_VERSION:C/^B.//}
NATIVE_LOWER_OPSYS?=		hpux
NATIVE_LOWER_OPSYS_VERSUFFIX?=	${NATIVE_OS_VERSION}
NATIVE_LOWER_VENDOR?=		hp

.elif ${NATIVE_OPSYS} == "SunOS"
NATIVE_LOWER_VENDOR?=		sun
NATIVE_LOWER_OPSYS?=		solaris
NATIVE_LOWER_OPSYS_VERSUFFIX=	2.${NATIVE_OS_VERSION:C/5.//}
.  if !defined(_UNAME_V)
_UNAME_V!=		${UNAME} -v
MAKEFLAGS+=		_UNAME_V=${_UNAME_V:Q}
.  endif
.  if !empty(_UNAME_V:Mjoyent_*)
NATIVE_OS_VARIANT=		SmartOS
NATIVE_LOWER_VARIANT_VERSION=	${_UNAME_V:C/joyent_//}
.  elif !empty(_UNAME_V:Momnios-*)
NATIVE_OS_VARIANT=		OmniOS
NATIVE_LOWER_VARIANT_VERSION!=	/usr/bin/awk '{ print $$3; exit 0; }' /etc/release
.  elif !empty(_UNAME_V:Mtribblix-*)
NATIVE_OS_VARIANT=		Tribblix
NATIVE_LOWER_VARIANT_VERSION!=	/usr/bin/awk '{ print $$2; exit 0; }' /etc/release
.  else
NATIVE_OS_VARIANT=		Solaris
NATIVE_LOWER_VARIANT_VERSION=	${_UNAME_V}
.  endif

.elif ${OPSYS} == "SCO_SV"
SCO_RELEASE!=			${UNAME} -r
SCO_VERSION!=			${UNAME} -v
NATIVE_LOWER_VENDOR?=		pc
NATIVE_LOWER_OPSYS?=		sco
NATIVE_LOWER_OPSYS_VERSUFFIX=	${SCO_RELEASE}v${SCO_VERSION}
_UNAME_V!=			${UNAME} -v
.  if !empty(_UNAME_V:M5.0*)
NATIVE_OS_VARIANT=		SCOOSR5
.  elif !empty(_UNAME_V:M6.0*)
NATIVE_OS_VARIANT=		SCOOSR6
.  endif

.elif ${NATIVE_OPSYS} == "UnixWare"
SCO_RELEASE?=			sysv5${NATIVE_OPSYS}
SCO_VERSION!=			${UNAME} -v
NATIVE_LOWER_VENDOR?=		unknown
NATIVE_LOWER_OPSYS_VERSUFFIX=	${SCO_RELEASE}${SCO_VERSION}

.elif ${NATIVE_OPSYS} == "Minix"
NATIVE_LOWER_VENDOR?=		unknown
NATIVE_LOWER_OPSYS:=		${NATIVE_OPSYS:tl}

.elif !defined(NATIVE_LOWER_OPSYS)
NATIVE_LOWER_OPSYS:=		${NATIVE_OPSYS:tl}
.endif

# Now commit the version values computed above, eliding the :sh
NATIVE_OS_VERSION:=	${NATIVE_OS_VERSION}

MAKEFLAGS+=		NATIVE_LOWER_OPSYS=${NATIVE_LOWER_OPSYS:Q}

NATIVE_LOWER_VENDOR?=	# empty ("arch--opsys")

# List of variables that must be set to determine a cross-compilation
# target.
CROSSVARS?=	# empty

# Cross-compilation target settings.
#
# We set these to have conditional expansions so that when <bsd.own.mk>
# includes mk.conf, and mk.conf sets USE_CROSS_COMPILE, the _rest_ of
# <bsd.own.mk> gets the right cross vs native versions of the
# variables.
#
# As soon as <bsd.own.mk> is done we can commit the switcheroo without
# the conditional expansions -- but there's no hook to do that inside
# <bsd.own.mk> between inclusion of mk.conf and the rest of
# <bsdf.own.mk>.  And there's no way to know, before we include
# mk.conf, whether the user _might_ be doing cross-builds.  So we have
# to use this massive kludge.
#
CROSSVARS+=	OPSYS
OPSYS=			\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_OPSYS}:${NATIVE_OPSYS}}
CROSSVARS+=	OS_VERSION
OS_VERSION=		\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_OS_VERSION}:${NATIVE_OS_VERSION}}
CROSSVARS+=	OPSYS_VERSION
OPSYS_VERSION=		\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_OPSYS_VERSION}:${NATIVE_OPSYS_VERSION}}
CROSSVARS+=	LOWER_OPSYS
LOWER_OPSYS=		\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_LOWER_OPSYS}:${NATIVE_LOWER_OPSYS}}
CROSSVARS+=	LOWER_OPSYS_VERSUFFIX
LOWER_OPSYS_VERSUFFIX=	\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_LOWER_OPSYS_VERSUFFIX}:${NATIVE_LOWER_OPSYS_VERSUFFIX}}
CROSSVARS+=	LOWER_VARIANT_VERSION
LOWER_VARIANT_VERSION=	\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_LOWER_VARIANT_VERSION}:${NATIVE_LOWER_VARIANT_VERSION}}
CROSSVARS+=	LOWER_VENDOR
LOWER_VENDOR=		\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_LOWER_VENDOR}:${NATIVE_LOWER_VENDOR}}
CROSSVARS+=	LOWER_OS_VARIANT
OS_VARIANT=		\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_OS_VARIANT}:${NATIVE_OS_VARIANT}}

# Remember the MACHINE_ARCH that make was built with before we override
# it with CROSS_MACHINE_ARCH if USE_CROSS_COMPILE is enabled.
CROSSVARS+=	MACHINE_ARCH
NATIVE_MACHINE_ARCH:=		${MACHINE_ARCH}

NATIVE_MACHINE_PLATFORM?=	${NATIVE_OPSYS}-${NATIVE_OS_VERSION}-${NATIVE_MACHINE_ARCH}
MACHINE_PLATFORM?=		${OPSYS}-${OS_VERSION}-${MACHINE_ARCH}
NATIVE_MACHINE_GNU_PLATFORM?=	${NATIVE_MACHINE_GNU_ARCH}-${NATIVE_LOWER_VENDOR}-${NATIVE_LOWER_OPSYS:C/[0-9]//g}${NATIVE_APPEND_ELF}${NATIVE_LOWER_OPSYS_VERSUFFIX}${NATIVE_APPEND_ABI}
MACHINE_GNU_PLATFORM?=		${MACHINE_GNU_ARCH}-${LOWER_VENDOR}-${LOWER_OPSYS:C/[0-9]//g}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}${APPEND_ABI}

.ifdef TARGET_MACHINE_ARCH
TARGET_MACHINE_GNU_ARCH=	${GNU_ARCH.${TARGET_MACHINE_ARCH}:U${TARGET_MACHINE_ARCH}}
TARGET_MACHINE_GNU_PLATFORM=	${TARGET_MACHINE_GNU_ARCH}-${TARGET_LOWER_VENDOR}-${TARGET_LOWER_OPSYS:C/[0-9]//g}${TARGET_APPEND_ELF}${TARGET_LOWER_OPSYS_VERSUFFIX}${TARGET_APPEND_ABI}
TARGET_MACHINE_PLATFORM=	${TARGET_OPSYS}-${TARGET_OS_VERSION}-${TARGET_MACHINE_ARCH}
.endif

# Set this before <bsd.own.mk> does, since it doesn't know about Darwin
# or Cygwin (XXX or HP-UX or AIX or OSF/1 or ...).
#
# We will later set OBJECT_FMT to be conditional on USE_CROSS_COMPILE.
.if ${NATIVE_OPSYS} == "Cygwin"
NATIVE_OBJECT_FMT?=	PE
OBJECT_FMT?=		PE
.elif ${NATIVE_OPSYS} == "Darwin"
NATIVE_OBJECT_FMT?=	Mach-O
OBJECT_FMT?=		Mach-O
.endif

#
# cross-libtool is special -- it is built as a native package, but it
# needs tools set up as if for a cross-compiled package because it
# remembers the paths for use to later assist in cross-compiling other
# packages.
#
# So normally TOOLS_USE_CROSS_COMPILE is the same as USE_CROSS_COMPILE,
# but for cross-libtool, we set TOOLS_USE_CROSS_COMPILE=yes while doing
# the rest of the native package build with USE_CROSS_COMPILE=no.
#
# This can't live inside the cross-libtool makefile because the
# TARGET_MACHINE_ARCH / MACHINE_ARCH / NATIVE_MACHINE_ARCH switcheroo
# has to happen in the middle of this file -- after NATIVE_MACHINE_ARCH
# is determined, before MACHINE_ARCH is used for anything else.
#
.if ${LIBTOOL_CROSS_COMPILE:U:tl} == "yes"
.  if !defined(TARGET_MACHINE_ARCH)
PKG_FAIL_REASON+=	"Must set TARGET_MACHINE_ARCH for cross-libtool."
.  endif
.  for _v_ in ${CROSSVARS}
${_v_}=				${TARGET_${_v_}}
.  endfor
# XXX Other CROSSVARS for _BUILD_DEFS?
_BUILD_DEFS.MACHINE_ARCH=	${NATIVE_MACHINE_ARCH}
_BUILD_DEFS.MACHINE_GNU_ARCH=	${NATIVE_MACHINE_GNU_ARCH}
_BUILD_DEFS.OBJECT_FMT=		${NATIVE_OBJECT_FMT}
_BUILD_DEFS.OPSYS=		${NATIVE_OPSYS}
_BUILD_DEFS.OS_VERSION=		${NATIVE_OS_VERSION}
TOOLS_USE_CROSS_COMPILE=	yes
.else
TOOLS_USE_CROSS_COMPILE=	${USE_CROSS_COMPILE:Uno}
.endif

# Needed to prevent an "install:" target from being created in bsd.own.mk.
NEED_OWN_INSTALL_TARGET=no

# This prevents default use of the cross-tool harness in the "src" tree,
# in the odd possible case of someone extracting "pkgsrc" underneath "src".
USETOOLS=		no
MAKE_ENV+=		USETOOLS=no

ACCEPTABLE_LICENSES?=	${DEFAULT_ACCEPTABLE_LICENSES}

# Provide PKGPATH early on so that mk.conf can use it.
PKGPATH?=		${.CURDIR:C|.*/([^/]*/[^/]*)$|\1|}

# Load the settings from MAKECONF, which is /etc/mk.conf by default.
.include <bsd.own.mk>

# Save the OBJECT_FMT determined by bsd.own.mk, and turn OBJECT_FMT
# into a cross-compilation variable so it can be overridden by
# CROSS_OBJECT_FMT.
NATIVE_OBJECT_FMT:=	${OBJECT_FMT}
CROSSVARS+=		OBJECT_FMT
OBJECT_FMT=		\
	${"${USE_CROSS_COMPILE:U:tl}" == "yes":?${CROSS_OBJECT_FMT}:${NATIVE_OBJECT_FMT}}

# When cross-compilation support is requested, the following options
# must be specified as well or guessable:
# - Variables like MACHINE_ARCH are set to CROSS_MACHINE_ARCH.
# - CROSS_DESTDIR is guessed from MAKEOBJDIR and MACHINE_ARCH.
# - PKG_DBDIR is expanded and prefixed with CROSS_DESTDIR
# - DESTDIR support is required
#
# _CROSS_DESTDIR is set for internal use to avoid conditionalising
# the use.

.if ${USE_CROSS_COMPILE:U:tl} == "yes" # defaults/mk.conf not yet loaded, so :U
.  for _v_ in ${CROSSVARS}
.    ifndef CROSS_${_v_}
MISSING_CROSSVARS=	yes
.      warning Missing CROSS_${_v_} setting
.    endif
${_v_}:=	${CROSS_${_v_}}
.  endfor
.  ifdef MISSING_CROSSVARS
.    error USE_CROSS_COMPILE=yes but missing cross variable settings
.  endif
CROSS_DESTDIR?=	${MAKEOBJDIR}/destdir.${MACHINE_ARCH}
.  if !exists(${CROSS_DESTDIR}/usr/include/stddef.h)
PKG_FAIL_REASON+=	"The cross-compiling root ${CROSS_DESTDIR:Q} is incomplete"
.  else
_CROSS_DESTDIR=	${CROSS_DESTDIR}
.  endif
.endif

.if ${OPSYS} == "OpenBSD"
.  if defined(ELF_TOOLCHAIN) && ${ELF_TOOLCHAIN} == "yes"
OBJECT_FMT?=	ELF
.  else
OBJECT_FMT?=	a.out
.  endif
.elif ${OPSYS} == "FreeBSD"
OBJECT_FMT?=	ELF
.elif ${OPSYS} == "DragonFly"
OBJECT_FMT=	ELF
.elif ${OPSYS} == "Minix"
OBJECT_FMT=	ELF
.elif ${OPSYS} == "MirBSD"
OBJECT_FMT=	ELF
MKPROFILE=	no
.elif ${OPSYS} == "Linux"
OBJECT_FMT=	ELF
.elif ${OPSYS} == "AIX"
OBJECT_FMT=	XCOFF
.elif ${OPSYS} == "OSF1"
OBJECT_FMT=	ECOFF
.elif ${OPSYS} == "HPUX"
.  if ${MACHINE_ARCH} == "ia64"
OBJECT_FMT=	ELF
.  elif ${MACHINE_ARCH} == "hppa64"
# it is ELF but for most purposes behaves like SOM (.sl suffix, ...)
OBJECT_FMT=	SOM
.  else # hppa
OBJECT_FMT=	SOM
.  endif
.elif ${OPSYS} == "Cygwin"
OBJECT_FMT=	PE
.elif ${OPSYS} == "SCO_SV"
OBJECT_FMT=	ELF
.elif ${OPSYS} == "UnixWare"
OBJECT_FMT=	ELF
.endif

# Calculate depth
.if exists(${.CURDIR}/mk/bsd.pkg.mk)
_PKGSRC_TOPDIR=	${.CURDIR}
.elif exists(${.CURDIR}/../mk/bsd.pkg.mk)
_PKGSRC_TOPDIR=	${.CURDIR}/..
.elif exists(${.CURDIR}/../../mk/bsd.pkg.mk)
_PKGSRC_TOPDIR=	${.CURDIR}/../..
.endif

# include the defaults file
.include "${_PKGSRC_TOPDIR}/mk/defaults/mk.conf"

SHAREOWN?=		${DOCOWN}
SHAREGRP?=		${DOCGRP}
SHAREMODE?=		${DOCMODE}

.if defined(PREFIX) && (${PREFIX} != ${__PREFIX_SET__})
.BEGIN:
	@${ECHO_MSG} "You CANNOT set PREFIX manually or in mk.conf. Set LOCALBASE or X11BASE"
	@${ECHO_MSG} "depending on your needs. See the pkg system documentation for more info."
	@${FALSE}
.endif

# Load the OS-specific definitions for program variables.  Default to loading
# the NetBSD ones if an OS-specific file doesn't exist.
.if exists(${_PKGSRC_TOPDIR}/mk/platform/${OPSYS}.mk)
.  include "${_PKGSRC_TOPDIR}/mk/platform/${OPSYS}.mk"
.else
.  include "${_PKGSRC_TOPDIR}/mk/platform/NetBSD.mk"
PKG_FAIL_REASON+=	"missing mk/platform/${OPSYS}.mk"
.endif

# Set default SHLIB_TYPE to the ${OPSYS}-specific shared library type.
SHLIB_TYPE?=		${_OPSYS_SHLIB_TYPE}

PKGDIRMODE?=		755

# A meta-package is a package that does not have any files and whose
# only purpose is to depend on other packages, giving that collection
# a simple name.
#
# This variable must be set before including bsd.prefs.mk directly or
# indirectly.
#
# Keywords: meta meta-package META_PACKAGE
#
.if defined(META_PACKAGE)
PKG_DESTDIR_SUPPORT=	user-destdir
NO_CONFIGURE=		yes
NO_BUILD=		yes
DISTFILES=		# none
PLIST_SRC=		# none
CHECK_PERMS=		no
USE_LANGUAGES=		# empty
WRKSRC=			${WRKDIR}

do-patch:
	@${DO_NADA}
do-install:
	@${DO_NADA}
.endif

# PKG_DESTDIR_SUPPORT can only be one of "destdir", or "user-destdir".
PKG_DESTDIR_SUPPORT?=	user-destdir

.if ${PKG_DESTDIR_SUPPORT} == "user-destdir"
_USE_DESTDIR=		user-destdir
.elif ${PKG_DESTDIR_SUPPORT} == "destdir"
_USE_DESTDIR=		destdir
.else
PKG_FAIL_REASON+=	"PKG_DESTDIR_SUPPORT must be \`\`destdir'' or \`\`user-destdir''."
.endif

# When using staged installation, everything gets installed into
# ${DESTDIR}${PREFIX} instead of ${PREFIX} directly.
#
DESTDIR=		${WRKDIR}/.destdir
.if ${_USE_DESTDIR} == "destdir"
_MAKE_PACKAGE_AS_ROOT=	yes
_MAKE_CLEAN_AS_ROOT=	yes
_MAKE_INSTALL_AS_ROOT=	yes
.else
_MAKE_PACKAGE_AS_ROOT=	no
_MAKE_CLEAN_AS_ROOT=	no
_MAKE_INSTALL_AS_ROOT=	no
.  endif

# controls whether binary packages are preserved in pkgsrc/packages/All
# default is no (to preserve settings since 2013/05/23, prior to that it
# was yes)
_KEEP_BIN_PKGS?= no
.if !empty(PKGSRC_KEEP_BIN_PKGS:U:M[Yy][Ee][Ss])
_KEEP_BIN_PKGS=	yes
.endif

_MAKE_CLEAN_AS_ROOT?=	no
# Whether to run the clean target as root.
_MAKE_INSTALL_AS_ROOT?=	yes
# Whether to run the install target as root.
_MAKE_PACKAGE_AS_ROOT?=	yes
# Whether to run the package target as root.

# TOOLS_CROSS_DESTDIR is used for the libtool build to make a wrapper
# that points at the cross-destdir as sysroot, without setting
# _CROSS_DESTDIR because we're actually building a native package.
.if ${TOOLS_USE_CROSS_COMPILE:tl} == "yes"
TOOLS_CROSS_DESTDIR=		${CROSS_DESTDIR}
.else
TOOLS_CROSS_DESTDIR=		# empty
.endif

# Depends on MACHINE_ARCH override above
.if ${OPSYS} == "NetBSD"
.  ifdef TARGET_MACHINE_ARCH
TARGET_OBJECT_FMT?=	${OBJECT_FMT} # XXX
.  endif
.  if ${NATIVE_OBJECT_FMT} == "ELF" && \
   (!empty(NATIVE_MACHINE_ARCH:Mearm*) || \
    ${NATIVE_MACHINE_GNU_ARCH} == "arm" || \
    ${NATIVE_MACHINE_ARCH} == "i386" || \
    ${NATIVE_MACHINE_ARCH} == "m68k" || \
    ${NATIVE_MACHINE_ARCH} == "m68000" || \
    ${NATIVE_MACHINE_GNU_ARCH} == "sh" || \
    ${NATIVE_MACHINE_GNU_ARCH} == "shle" || \
    ${NATIVE_MACHINE_ARCH} == "sparc" || \
    ${NATIVE_MACHINE_ARCH} == "vax")
NATIVE_APPEND_ELF=	elf
.  endif
.  if ${OBJECT_FMT} == "ELF" && \
   (!empty(MACHINE_ARCH:Mearm*) || \
    ${MACHINE_GNU_ARCH} == "arm" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "m68k" || \
    ${MACHINE_ARCH} == "m68000" || \
    ${MACHINE_GNU_ARCH} == "sh" || \
    ${MACHINE_GNU_ARCH} == "shle" || \
    ${MACHINE_ARCH} == "sparc" || \
    ${MACHINE_ARCH} == "vax")
APPEND_ELF=		elf
.  endif
.  if defined(TARGET_MACHINE_ARCH) && \
   ${TARGET_OBJECT_FMT} == "ELF" && \
   (!empty(TARGET_MACHINE_ARCH:Mearm*) || \
    ${TARGET_MACHINE_GNU_ARCH} == "arm" || \
    ${TARGET_MACHINE_ARCH} == "i386" || \
    ${TARGET_MACHINE_ARCH} == "m68k" || \
    ${TARGET_MACHINE_ARCH} == "m68000" || \
    ${TARGET_MACHINE_GNU_ARCH} == "sh" || \
    ${TARGET_MACHINE_GNU_ARCH} == "shle" || \
    ${TARGET_MACHINE_ARCH} == "sparc" || \
    ${TARGET_MACHINE_ARCH} == "vax")
TARGET_APPEND_ELF=	elf
.  endif
.  if !empty(NATIVE_MACHINE_ARCH:Mearm*)
NATIVE_APPEND_ABI=	-${NATIVE_MACHINE_ARCH:C/eb//:C/v[4-7]//:S/earm/eabi/}
.  endif
.  if !empty(MACHINE_ARCH:Mearm*)
APPEND_ABI=		-${MACHINE_ARCH:C/eb//:C/v[4-7]//:S/earm/eabi/}
.  endif
.  if !empty(TARGET_MACHINE_ARCH:Mearm*)
TARGET_APPEND_ABI=	-${TARGET_MACHINE_ARCH:C/eb//:C/v[4-7]//:S/earm/eabi/}
.  endif
.endif

# if the system is IPv6-ready, compile with IPv6 support turned on.
.if empty(_OPSYS_HAS_INET6:M[nN][oO])
IPV6_READY=		YES
.else
IPV6_READY=		NO
.endif

LOCALBASE?=		/usr/pkg
TOOLBASE:=		${LOCALBASE}
.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
LOCALBASE=		${CROSS_LOCALBASE:U/usr/pkg}
VARBASE=		${CROSS_VARBASE:U/var}
SYSCONFBASE=		${CROSS_SYSCONFBASE:U/etc}
.endif
.if ${TOOLS_USE_CROSS_COMPILE:tl} == "yes"
.  if defined(CROSS_ABI)
ABI=			${CROSS_ABI}
.  else
.    undef ABI
.  endif
.endif
X11_TYPE?=		modular
.if !empty(X11_TYPE:Mnative)
.  if ${OPSYS} == "SunOS"
# On Solaris, we default to using OpenWindows for X11.
X11BASE?=	/usr/openwin
.  elif ${OPSYS} == "Cygwin" || ${OPSYS} == "IRIX" || ${OPSYS} == "OSF1" || ${OPSYS} == "HPUX"
X11BASE?=	/usr
.  elif ${OPSYS} == "Darwin"
.    if ${OPSYS_VERSION} < 100500
X11BASE?=	/usr/X11R6
.    elif ${OPSYS_VERSION} < 100800
X11BASE?=	/usr/X11
.    else
X11BASE?=	/opt/X11
.    endif
.  elif ${OPSYS} == "NetBSD"
X11BASE?=	/usr/X11R7
.  elif exists(/usr/X11R7/lib/libX11.so)
X11BASE?=	/usr/X11R7
.  elif exists(/usr/lib/libX11.so) || exists(/usr/lib64/libX11.so)
X11BASE?=	/usr
.  else
X11BASE?=	/usr/X11R6
.  endif
.endif
CROSSBASE?=	${TOOLBASE}/cross

.if defined(FIX_SYSTEM_HEADERS) && ${FIX_SYSTEM_HEADERS} == "yes" && \
    !defined(BOOTSTRAP_PKG) && \
    exists(../../pkgtools/compat_headers/buildlink3.mk)
.  include "../../pkgtools/compat_headers/buildlink3.mk"
.endif

.if ${X11_TYPE} == "modular"
X11BASE=		${LOCALBASE}
.endif

# Default directory for font encodings
.if ${X11_TYPE} == "modular"
X11_ENCODINGSDIR?=	${X11BASE}/share/fonts/X11/encodings
.else
X11_ENCODINGSDIR?=	${X11BASE}/lib/X11/fonts/encodings
.endif

CATMAN_SECTION_SUFFIX?=	no

IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_KERNMAN_SUFFIX=	4
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_GAMEMAN_SUFFIX=	6
IMAKE_MISCMAN_SUFFIX=	7
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_KERNMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_GAMEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}6
IMAKE_MISCMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}7
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}
IMAKE_MANINSTALL?=	maninstall

# LINK_RPATH_FLAG publicly exports the linker flag used to set the
# run-time library search path.
#
.if defined(_OPSYS_LINKER_RPATH_FLAG)
LINKER_RPATH_FLAG=	${_OPSYS_LINKER_RPATH_FLAG}
.else
LINKER_RPATH_FLAG?=	${_LINKER_RPATH_FLAG}
.endif

# COMPILER_RPATH_FLAG publicly exports the compiler flag used to pass
# run-time library search path directives to the linker.
#
.if defined(_OPSYS_COMPILER_RPATH_FLAG)
COMPILER_RPATH_FLAG=	${_OPSYS_COMPILER_RPATH_FLAG}
.else
COMPILER_RPATH_FLAG?=	${_COMPILER_RPATH_FLAG}
.endif

COMPILER_INCLUDE_DIRS?=	${_OPSYS_INCLUDE_DIRS:U/usr/include}
COMPILER_LIB_DIRS?=	${_OPSYS_LIB_DIRS:U/usr/lib${LIBABISUFFIX} /lib${LIBABISUFFIX}}
SYSTEM_DEFAULT_RPATH?=	${_OPSYS_SYSTEM_RPATH:U/usr/lib}

USE_TOOLS?=	# empty

# Provide default values for TOOLs used by the top-level make.
USE_TOOLS+=	[ awk dirname echo grep pwd sed test true

# These tools are used by the top-level make only in certain packages and
# should eventually be moved into those particular package Makefiles.
#
USE_TOOLS+=	date tr

# These are tools used directly by bsd.prefs.mk and files included by
# bsd.prefs.mk.
#
USE_TOOLS+=	awk:pkgsrc cut:pkgsrc echo:pkgsrc pwd:pkgsrc		\
		sed:pkgsrc tr:pkgsrc uname:pkgsrc

.include "${_PKGSRC_TOPDIR}/mk/tools/defaults.mk"

.if ${FETCH_USING} == "auto"
.  if defined(TOOLS_PLATFORM.fetch)
FETCH_USING=	fetch
.  elif defined(TOOLS_PLATFORM.ftp)
FETCH_USING=	ftp
.  elif defined(TOOLS_PLATFORM.curl)
FETCH_USING=	curl
.  elif defined(TOOLS_PLATFORM.wget)
FETCH_USING=	wget
.  else
FETCH_USING=	fetch
.  endif
.endif

.if !defined(_PKGSRCDIR)
_PKGSRCDIR!=		cd ${_PKGSRC_TOPDIR} && ${PWD_CMD}
MAKEFLAGS+=		_PKGSRCDIR=${_PKGSRCDIR:Q}
.endif
PKGSRCDIR=		${_PKGSRCDIR}

.if ${TOOLS_USE_CROSS_COMPILE:tl} == "yes"
_CROSSDIR_SUFFIX=	.${MACHINE_PLATFORM}
.endif

TEMPLATES?=		${PKGSRCDIR}/templates

PATCHDIR?=		${.CURDIR}/patches
FILESDIR?=		${.CURDIR}/files
PKGDIR?=		${.CURDIR}

_PKGSRC_DEPS?=		# empty
_BUILTIN_PKGS?=		# empty

# If WRKOBJDIR is set, use that tree to build
.if defined(WRKOBJDIR)
BUILD_DIR?=		${WRKOBJDIR}/${PKGPATH}
.else
BUILD_DIR!=		cd ${.CURDIR} && ${PWD_CMD}
.endif

# If OBJHOSTNAME is set, use first component of hostname in directory name.
# If OBJMACHINE is set, use ${MACHINE_ARCH} in the working directory name.
#
.if defined(OBJHOSTNAME)
.  if !defined(_HOSTNAME)
_HOSTNAME!=		${UNAME} -n
MAKEFLAGS+=		_HOSTNAME=${_HOSTNAME:Q}
.  endif
WRKDIR_BASENAME?=	work${_CROSSDIR_SUFFIX}.${_HOSTNAME:C|\..*||}
MAKEFLAGS+=		OBJHOSTNAME=${OBJHOSTNAME:Q}
.elif defined(OBJMACHINE)
WRKDIR_BASENAME?=	work.${MACHINE_ARCH}
MAKEFLAGS+=		OBJMACHINE=${OBJMACHINE:Q}
.else
WRKDIR_BASENAME?=	work${_CROSSDIR_SUFFIX}
.endif

WRKDIR?=		${BUILD_DIR}/${WRKDIR_BASENAME}

# There are many uses for a common log file, so define one that may be
# picked up and used by tools.mk, bsd.buildlink3.mk, etc.
#
WRKLOG?=		${WRKDIR}/.work.log

PKG_DEFAULT_OPTIONS?=	# empty
PKG_OPTIONS?=		# empty

# we want this *before* compiler.mk, so that compiler.mk paths override them
.if ${X11_TYPE} != "modular" && defined(USE_X11)
PREPEND_PATH+=		${X11BASE}/bin
.endif
PREPEND_PATH+=		${LOCALBASE}/bin

.if ${_USE_NEW_PKGINSTALL:Uno} == "no"
# Support alternative init systems.
#
INIT_SYSTEM?=		rc.d
_BUILD_DEFS+=		INIT_SYSTEM
.endif

# Build Position Independent Executables if supported
# Allows the security mitigation of ASLR to be used.
# Impact: very small performance drop.
#
PKGSRC_OVERRIDE_MKPIE?=	no
_PKGSRC_MKPIE=		no
.if ${PKGSRC_MKPIE:tl} == "yes" && \
    ${MKPIE_SUPPORTED:Uyes:tl} == "yes" && \
    ${_OPSYS_SUPPORTS_MKPIE:Uno} == "yes"
_PKGSRC_MKPIE=		yes
.endif

# Enable reproducible build flags
# Adjusts debug symbols to omit workdir references
#
_PKGSRC_MKREPRO=	no
.if ${PKGSRC_MKREPRO:tl} == "yes" && \
    ${MKREPRO_SUPPORTED:Uyes:tl} == "yes" && \
    ${_OPSYS_SUPPORTS_MKREPRO:Uno} == "yes"
_PKGSRC_MKREPRO=	yes
.endif

# Enable FORTIFY
# Security mitigation: compile and run-time checks for buffer overflows.
# Impact: performance drop
#
_PKGSRC_USE_FORTIFY=	no
.if ${PKGSRC_USE_FORTIFY:tl} != "no" && \
    ${FORTIFY_SUPPORTED:Uyes:tl} == "yes" && \
    ${_OPSYS_SUPPORTS_FORTIFY:Uno} == "yes"
_PKGSRC_USE_FORTIFY=	yes
.endif

# Use read-only relocations
# Security mitigation: some ELF sections are mapped read-only.
# Impact: increases program startup time as it disables lazy-binding
#
_PKGSRC_USE_RELRO=	no
.if ${PKGSRC_USE_RELRO:tl} != "no" && \
    ${RELRO_SUPPORTED:Uyes:tl} != "no" && \
    ${_OPSYS_SUPPORTS_RELRO:Uno} == "yes"
.  if ${PKGSRC_USE_RELRO:tl} != "full"
_PKGSRC_USE_RELRO=	partial
.  else
_PKGSRC_USE_RELRO=	full
.  endif
.endif

# Enable Stack-Smashing Protection
# Security mitigation: add and check canaries on the stack at runtime
# to find buffer overruns.
# Impact: performance drop
#
_PKGSRC_USE_SSP=	no
.if ${PKGSRC_USE_SSP:tl} != "no" && \
    ${SSP_SUPPORTED:Uyes:tl} == "yes" && \
    ${_OPSYS_SUPPORTS_SSP:Uno} == "yes"
_PKGSRC_USE_SSP=	yes
.endif

# Enable stack check
# Generate code to ensure we don't exceed our given stack.
# Impact: performance drop
#
_PKGSRC_USE_STACK_CHECK=no
.if ${PKGSRC_USE_STACK_CHECK:tl} != "no" && \
    ${STACK_CHECK_SUPPORTED:Uyes:tl} == "yes" && \
    ${_OPSYS_SUPPORTS_STACK_CHECK:Uno} == "yes"
.  if ${PKGSRC_USE_STACK_CHECK:tl} == "stack-clash"
_PKGSRC_USE_STACK_CHECK=stack-clash
.  else
_PKGSRC_USE_STACK_CHECK=yes
.  endif
.endif

# Enable CTF conversion if the user requested it, the OPSYS supports it, there
# is a tool for it, and the package supports it.  We also need to explicitly
# turn on _INSTALL_UNSTRIPPED as conversion is impossible on stripped files.
#
.if ${PKGSRC_USE_CTF:Uno:tl} == "yes" && \
    ${_OPSYS_SUPPORTS_CTF:Uno:tl} == "yes" && \
    defined(TOOLS_PLATFORM.ctfconvert) && \
    ${CTF_SUPPORTED:Uyes:tl} == "yes"
_PKGSRC_USE_CTF=	yes
_INSTALL_UNSTRIPPED=	# defined
.else
_PKGSRC_USE_CTF=	no
.endif

# Enable cwrappers if not building the wrappers themselves, and if the user has
# explicitly requested them, or if they haven't but the compiler/platform is
# known to support them.
.if empty(PKGPATH:Mpkgtools/cwrappers) && \
    (${USE_CWRAPPERS:tl} == "yes" || \
    (${USE_CWRAPPERS:tl} == "auto" && \
     ${_OPSYS_SUPPORTS_CWRAPPERS:Uno} == "yes"))
_USE_CWRAPPERS=		yes
.else
_USE_CWRAPPERS=		no
.endif

# Use C-based tools to speed up pkgsrc infrastructure tasks.
.if empty(PKGPATH:Mpkgtools/mktools) && \
    (${PKGSRC_USE_MKTOOLS:tl} == "yes" || \
    (${PKGSRC_USE_MKTOOLS:tl} == "auto" && \
     ${_OPSYS_SUPPORTS_MKTOOLS:Uno} == "yes"))
_PKGSRC_USE_MKTOOLS=	yes
.else
_PKGSRC_USE_MKTOOLS=	no
.endif

# Wrapper framework definitions
.include "wrapper/wrapper-defs.mk"

# Binary emulator framework definitions
.if defined(EMUL_PLATFORMS) && !empty(EMUL_PLATFORMS)
.  include "emulator/emulator-vars.mk"
.endif

# System features framework
.include "features/features-vars.mk"

.if ${_USE_NEW_PKGINSTALL:Uno} != "no"
# Init services framework
.include "init/bsd.init-vars.mk"
.endif

# Package system format definitions
.include "pkgformat/bsd.pkgformat-vars.mk"

# Make variable definitions cache
.include "bsd.makevars.mk"

# If MAKECONF is defined, then pass it down to all recursive make
# processes invoked by pkgsrc.
#
PKGSRC_MAKE_ENV+=	${MAKECONF:DMAKECONF=${MAKECONF:Q}}
RECURSIVE_MAKE=		${PKGSRC_SETENV} ${PKGSRC_MAKE_ENV} ${MAKE}

_VARGROUPS+=		dirs
_USER_VARS.dirs=	DISTDIR LOCALBASE PACKAGES PKG_SYSCONFDIR WRKOBJDIR
_USER_VARS.dirs+=	PKG_DBDIR
_PKG_VARS.dirs=		WRKSRC PATCHDIR FILESDIR PKGDIR
_SYS_VARS.dirs=		WRKDIR DESTDIR PREFIX PKG_SYSCONFBASEDIR

# List of 32-bit operating systems
# This can be used with BROKEN_ON_PLATFORM for software that is not
# 32-bit clean.
#
# Keywords: BROKEN_ON_PLATFORM 32bit
#
LP32PLATFORMS=		*-*-earm* *-*-hppa *-*-i386 *-*-m68000 *-*-m68k \
			*-*-mipseb *-*-mipsel *-*-powerpc *-*-riscv32 \
			*-*-sparc *-*-vax

# List of 64-bit operating systems with sizeof(int) != sizeof(void *).
# This can be used with BROKEN_ON_PLATFORM for software that is not
# 64-bit clean.
#
# Keywords: BROKEN_ON_PLATFORM 64bit
#
LP64PLATFORMS=		*-*-aarch64 *-*-aarch64eb *-*-alpha *-*-ia64 \
			*-*-powerpc64* *-*-riscv64 *-*-sparc64 *-*-x86_64

# Lists of big-endian and little-endian platforms, to be used with
# BROKEN_ON_PLATFORM.
#
# Keywords: BROKEN_ON_PLATFORM little-endian big-endian endian
#
_BIGENDIANCPUS=		coldfire hppa m68000 m68k mips64eb mipseb or1k \
			powerpc powerpc64 sh3eb sparc sparc64
_LITTLEENDIANCPUS=	alpha i386 ia64 mips64el mipsel powerpc64le riscv32 \
			riscv64 sh3el vax x86_64

# piles of ARM variants
_ARMCPUS+=		arm earm earmhf earmv4 earmv5 earmv6 earmv6hf
_ARMCPUS+=		earmv7 earmv7hf aarch64
_BIGENDIANCPUS+=	${_ARMCPUS:S/$/eb/}
_LITTLEENDIANCPUS+=	${_ARMCPUS}

BIGENDIANPLATFORMS=	${_BIGENDIANCPUS:S/^/*-*-/}
LITTLEENDIANPLATFORMS=	${_LITTLEENDIANCPUS:S/^/*-*-/}

#
# Allow installing a newer C/C++ compiler to build a package
# than what the system provides.
#
# Impact: allowing this can sometimes result in mismatches
# with libstdc++ versions.
#
ALLOW_NEWER_COMPILER?=	yes

.endif	# BSD_PKG_MK
