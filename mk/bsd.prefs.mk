# $NetBSD: bsd.prefs.mk,v 1.381 2016/03/11 23:54:08 khorben Exp $
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

.if exists(/usr/bin/uname)
UNAME=/usr/bin/uname
.elif exists(/bin/uname)
UNAME=/bin/uname
.else
UNAME=echo Unknown
.endif

.if !defined(OPSYS)
OPSYS:=			${:!${UNAME} -s!:S/-//g:S/\///g:C/^CYGWIN_.*$/Cygwin/}
MAKEFLAGS+=		OPSYS=${OPSYS:Q}
.endif

# OS_VARIANT is used to differentiate operating systems which have a common
# basis but offer contrasting environments, for example Linux distributions
# or illumos forks.
OS_VARIANT?=		# empty

# The _CMD indirection allows code below to modify these values
# without executing the commands at all.  Later, recursed make
# invocations will skip these blocks entirely thanks to MAKEFLAGS.
.if !defined(OS_VERSION)
_OS_VERSION_CMD=	${UNAME} -r
OS_VERSION=		${_OS_VERSION_CMD:sh}
MAKEFLAGS+=		OS_VERSION=${OS_VERSION:Q}
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
.if ${OPSYS} == "NetBSD"
LOWER_OPSYS?=		netbsd

.elif ${OPSYS} == "AIX"
.  if exists(/usr/bin/oslevel)
_OS_VERSION!=		/usr/bin/oslevel
.  else
_OS_VERSION!=		echo `${UNAME} -v`.`${UNAME} -r`
.  endif
OS_VERSION=		${_OS_VERSION:C/([0-9]*\.[0-9]*).*/\1/}
LOWER_OPSYS_VERSUFFIX=	${_OS_VERSION}
LOWER_OPSYS?=		aix
LOWER_VENDOR?=		ibm

.elif ${OPSYS} == "BSDOS"
LOWER_OPSYS?=		bsdi

.elif ${OPSYS} == "Bitrig"
LOWER_OPSYS?= 		bitrig
LOWER_VENDOR?= 		unknown

.elif ${OPSYS} == "Cygwin"
LOWER_OPSYS?=		cygwin
LOWER_VENDOR?=		pc
_OS_VERSION!=		${UNAME} -r
OS_VERSION=		${_OS_VERSION:C/\(.*\)//}
OS_VARIANT!=		${UNAME} -s

.elif ${OPSYS} == "Darwin"
LOWER_OPSYS?=		darwin
LOWER_OPSYS_VERSUFFIX=	${LOWER_OS_VERSION:C/([0-9]*).*/\1/}
LOWER_VENDOR?=		apple

.elif ${OPSYS} == "DragonFly"
OS_VERSION:=		${OS_VERSION:C/-.*$//}
LOWER_OPSYS?=		dragonfly
LOWER_VENDOR?=		pc

.elif ${OPSYS} == "FreeBSD"
OS_VERSION:=		${OS_VERSION:C/-.*$//}
LOWER_OPSYS?=		freebsd
LOWER_OPSYS_VERSUFFIX=	${LOWER_OS_VERSION:C/([0-9]*).*/\1/}
.  if ${MACHINE_ARCH} == "i386"
LOWER_VENDOR?=		pc
.  endif
LOWER_VENDOR?=		unknown

.elif ${OPSYS} == "Haiku"
LOWER_OPSYS?=		haiku
.  if ${MACHINE_ARCH} == "i386"
LOWER_VENDOR?=		pc
.  endif

.elif ${OPSYS} == "Interix"
LOWER_OPSYS?=		interix
LOWER_VENDOR?=		pc
.  if exists(/usr/lib/libc.so.5.2) || exists(/usr/lib/x86/libc.so.5.2)
LOWER_OPSYS_VERSUFFIX=	${LOWER_OS_VERSION:C/([0-9]*).*/\1/}
.  else
LOWER_OPSYS_VERSUFFIX?=	3
.    if exists(/usr/lib/libc.so.3.5)
OS_VERSION=		3.5
.    elif exists(/usr/lib/libc.so.3.1)
OS_VERSION=		3.1
.    else
OS_VERSION=		3.0
.    endif
.  endif

.elif ${OPSYS} == "MirBSD"
LOWER_OPSYS?=		mirbsd
LOWER_OS_VERSION=	${OS_VERSION}
LOWER_OPSYS_VERSUFFIX=	${OS_VERSION}
LOWER_VENDOR?=		unknown

.elif !empty(OPSYS:MIRIX*)
LOWER_OPSYS?=		irix
LOWER_OPSYS_VERSUFFIX?=	${OS_VERSION}
LOWER_VENDOR?=		sgi

.elif ${OPSYS} == "Linux"
OS_VERSION:=		${OS_VERSION:C/-.*$//}
LOWER_OPSYS?=		linux
.  if exists(/etc/debian_version)
LOWER_VENDOR?=		debian
.  elif exists(/etc/mandrake-release)
LOWER_VENDOR?=		mandrake
.  elif exists(/etc/redhat-version) || exists(/etc/redhat-release)
LOWER_VENDOR?=		redhat
.  elif exists(/etc/slackware-version)
LOWER_VENDOR?=		slackware
.  elif exists(/etc/ssdlinux_version)
LOWER_VENDOR?=		ssd
.  elif ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
LOWER_VENDOR?=          pc
.  endif
LOWER_VENDOR?=          unknown

.elif ${OPSYS} == "OpenBSD"
LOWER_OPSYS?= 		openbsd

.elif ${OPSYS} == "OSF1"
OS_VERSION:=		${OS_VERSION:C/^V//}
LOWER_OPSYS?=		osf1
LOWER_OPSYS_VERSUFFIX?=	${OS_VERSION}
LOWER_VENDOR?=		dec

.elif ${OPSYS} == "HPUX"
OS_VERSION:=		${OS_VERSION:C/^B.//}
LOWER_OPSYS?=		hpux
LOWER_OPSYS_VERSUFFIX?=	${OS_VERSION}
LOWER_VENDOR?=		hp

.elif ${OPSYS} == "SunOS"
LOWER_VENDOR?=		sun
LOWER_OPSYS?=		solaris
LOWER_OPSYS_VERSUFFIX=	2.${OS_VERSION:C/5.//}
_UNAME_V!=		${UNAME} -v
.  if !empty(_UNAME_V:Mjoyent_*)
OS_VARIANT=		SmartOS
LOWER_VARIANT_VERSION=	${_UNAME_V:C/joyent_//}
.  elif !empty(_UNAME_V:Momnios-*)
OS_VARIANT=		OmniOS
LOWER_VARIANT_VERSION!=	/usr/bin/awk '{ print $$3; exit 0; }' /etc/release
.  else
OS_VARIANT=		Solaris
LOWER_VARIANT_VERSION=	${_UNAME_V}
.  endif

.elif ${OPSYS} == "SCO_SV"
SCO_RELEASE!=		${UNAME} -r
SCO_VERSION!=		${UNAME} -v
LOWER_VENDOR?=		pc
LOWER_OPSYS?=		sco
LOWER_OPSYS_VERSUFFIX=	${SCO_RELEASE}v${SCO_VERSION}
_UNAME_V!=		${UNAME} -v
.  if !empty(_UNAME_V:M5.0*)
OS_VARIANT=		SCOOSR5
.  elif !empty(_UNAME_V:M6.0*)
OS_VARIANT=		SCOOSR6
.  endif

.elif ${OPSYS} == "Minix"
LOWER_VENDOR?=		pc
LOWER_OPSYS:=		${OPSYS:tl}
LDFLAGS+=		-lcompat_minix -lminlib

.elif !defined(LOWER_OPSYS)
LOWER_OPSYS:=		${OPSYS:tl}
.endif

# Now commit the [LOWER_]OS_VERSION values computed above, eliding the :sh
OS_VERSION:=		${OS_VERSION}
LOWER_OS_VERSION:=	${OS_VERSION:tl}

MAKEFLAGS+=		LOWER_OPSYS=${LOWER_OPSYS:Q}

LOWER_VENDOR?=			# empty ("arch--opsys")

NATIVE_MACHINE_ARCH:=		${MACHINE_ARCH}
NATIVE_MACHINE_PLATFORM?=	${OPSYS}-${OS_VERSION}-${NATIVE_MACHINE_ARCH}
MACHINE_PLATFORM?=		${OPSYS}-${OS_VERSION}-${MACHINE_ARCH}
NATIVE_MACHINE_GNU_PLATFORM?=	${NATIVE_MACHINE_GNU_ARCH}-${LOWER_VENDOR}-${LOWER_OPSYS:C/[0-9]//g}${NATIVE_APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}${NATIVE_APPEND_ABI}
MACHINE_GNU_PLATFORM?=		${MACHINE_GNU_ARCH}-${LOWER_VENDOR}-${LOWER_OPSYS:C/[0-9]//g}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}${APPEND_ABI}

# Needed to prevent an "install:" target from being created in bsd.own.mk.
NEED_OWN_INSTALL_TARGET=no

# This prevents default use of the cross-tool harness in the "src" tree,
# in the odd possible case of someone extracting "pkgsrc" underneath "src".
USETOOLS=		no
MAKE_ENV+=		USETOOLS=no

# Set this before <bsd.own.mk> does, since it doesn't know about Darwin
.if ${OPSYS} == "Darwin"
OBJECT_FMT?=		Mach-O
.endif

ACCEPTABLE_LICENSES?=	${DEFAULT_ACCEPTABLE_LICENSES}

# Provide PKGPATH early on so that mk.conf can use it.
PKGPATH?=		${.CURDIR:C|.*/([^/]*/[^/]*)$|\1|}

# Load the settings from MAKECONF, which is /etc/mk.conf by default.
.include <bsd.own.mk>

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

# After 2011Q1, the default is to use DESTDIR.
USE_DESTDIR?=		yes
# PKG_DESTDIR_SUPPORT can only be one of "none", "destdir", or "user-destdir".
PKG_DESTDIR_SUPPORT?=	user-destdir

.if ${PKG_DESTDIR_SUPPORT} == "none" || empty(USE_DESTDIR:M[Yy][Ee][Ss])
.  if empty(USE_DESTDIR:M[Yy][Ee][Ss]) && empty(USE_DESTDIR:M[Nn][Oo])
PKG_FAIL_REASON+=	"USE_DESTDIR must be either \`\`yes'' or \`\`no''"
.  endif
_USE_DESTDIR=		no
.elif ${PKG_DESTDIR_SUPPORT} == "user-destdir"
_USE_DESTDIR=		user-destdir
.elif ${PKG_DESTDIR_SUPPORT} == "destdir"
_USE_DESTDIR=		destdir
.else
PKG_FAIL_REASON+=	"PKG_DESTDIR_SUPPORT must be \`\`none'', \`\`destdir'', or \`\`user-destdir''."
.endif

# This stanza serves to warn the user; deciding to not build
# non-DESTDIR-capable packages when not in DESTDIR mode is above.
.if ${PKG_DESTDIR_SUPPORT} == "none"
WARNINGS+=	"[bsd.prefs.mk] The package ${PKGNAME} is missing DESTDIR support."
.endif

# When using staged installation, everything gets installed into
# ${DESTDIR}${PREFIX} instead of ${PREFIX} directly.
#
.if ${_USE_DESTDIR} != "no"
DESTDIR=		${WRKDIR}/.destdir
.  if ${_USE_DESTDIR} == "destdir"
_MAKE_PACKAGE_AS_ROOT=	yes
_MAKE_CLEAN_AS_ROOT=	yes
_MAKE_INSTALL_AS_ROOT=	yes
.  elif ${_USE_DESTDIR} == "user-destdir"
_MAKE_PACKAGE_AS_ROOT=	no
_MAKE_CLEAN_AS_ROOT=	no
_MAKE_INSTALL_AS_ROOT=	no
.  endif
.else
PKG_FAIL_REASON+=	"USE_DESTDIR=no is no longer supported."
DESTDIR=
.endif

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

# When cross-compilation support is requested, the following options
# must be specified as well or guessable:
# - MACHINE_ARCH is set to TARGET_ARCH if set.
# - CROSS_DESTDIR is guessed from MAKEOBJDIR and MACHINE_ARCH.
# - PKG_DBDIR is expanded and prefixed with CROSS_DESTDIR
# - DESTDIR support is required
#
# _CROSS_DESTDIR is set for internal use to avoid conditionalising
# the use.

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
.  if defined(TARGET_ARCH)
MACHINE_ARCH=	${TARGET_ARCH}
.  endif
CROSS_DESTDIR?=	${MAKEOBJDIR}/destdir.${MACHINE_ARCH}
.  if !exists(${CROSS_DESTDIR}/usr/include/stddef.h)
PKG_FAIL_REASON+=	"The cross-compiling root ${CROSS_DESTDIR:Q} is incomplete"
.  else
_CROSS_DESTDIR=	${CROSS_DESTDIR}
.  endif
.endif

# Depends on MACHINE_ARCH override above
.if ${OPSYS} == "NetBSD"
# XXX NATIVE_OBJECT_FMT is a cop-out -- but seriously, who is going to
# do cross-builds on a NetBSD host that still uses a.out?
NATIVE_OBJECT_FMT?=	${OBJECT_FMT}
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
.  if !empty(NATIVE_MACHINE_ARCH:Mearm*)
NATIVE_APPEND_ABI=	-${NATIVE_MACHINE_ARCH:C/eb//:C/v[4-7]//:S/earm/eabi/}
.  endif
.  if !empty(MACHINE_ARCH:Mearm*)
APPEND_ABI=		-${MACHINE_ARCH:C/eb//:C/v[4-7]//:S/earm/eabi/}
.  endif
.endif

# if the system is IPv6-ready, compile with IPv6 support turned on.
.if empty(_OPSYS_HAS_INET6:M[nN][oO])
IPV6_READY=		YES
.else
IPV6_READY=		NO
.endif

LOCALBASE?=		/usr/pkg
X11_TYPE?=		modular
.if !empty(X11_TYPE:Mnative)
.  if ${OPSYS} == "SunOS"
# On Solaris, we default to using OpenWindows for X11.
X11BASE?=	/usr/openwin
.  elif ${OPSYS} == "Cygwin" || ${OPSYS} == "IRIX" || ${OPSYS} == "OSF1" || ${OPSYS} == "HPUX"
X11BASE?=	/usr
.  elif !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
X11BASE?=	/usr/X11R6
.  elif !empty(MACHINE_PLATFORM:MDarwin-9.*-*) || \
        !empty(MACHINE_PLATFORM:MDarwin-10.*-*) || \
        !empty(MACHINE_PLATFORM:MDarwin-11.*-*)
X11BASE?=	/usr/X11
.  elif !empty(MACHINE_PLATFORM:MDarwin-??.*-*)
X11BASE?=	/opt/X11
.  elif ${OPSYS} == "NetBSD" && ${X11FLAVOUR:U} == "Xorg"
X11BASE?=	/usr/X11R7
.  elif exists(/usr/X11R7/lib/libX11.so)
X11BASE?=	/usr/X11R7
.  elif exists(/usr/lib/libX11.so) || exists(/usr/lib64/libX11.so)
X11BASE?=	/usr
.  else
X11BASE?=	/usr/X11R6
.  endif
.endif
CROSSBASE?=	${LOCALBASE}/cross

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
.  elif defined(TOOLS_PLATFORM.curl)
FETCH_USING=	curl
.  elif defined(TOOLS_PLATFORM.wget)
FETCH_USING=	wget
.  else
FETCH_USING=	ftp
.  endif
.endif

.if !defined(_PKGSRCDIR)
_PKGSRCDIR!=		cd ${_PKGSRC_TOPDIR} && ${PWD_CMD}
MAKEFLAGS+=		_PKGSRCDIR=${_PKGSRCDIR:Q}
.endif
PKGSRCDIR=		${_PKGSRCDIR}

DISTDIR?=		${PKGSRCDIR}/distfiles
PACKAGES?=		${PKGSRCDIR}/packages
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
WRKDIR_BASENAME?=	work.${_HOSTNAME:C|\..*||}
MAKEFLAGS+=		OBJHOSTNAME=${OBJHOSTNAME:Q}
.elif defined(OBJMACHINE)
WRKDIR_BASENAME?=	work.${MACHINE_ARCH}
MAKEFLAGS+=		OBJMACHINE=${OBJMACHINE:Q}
.else
WRKDIR_BASENAME?=	work
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

# Support alternative init systems.
#
INIT_SYSTEM?=		rc.d
_BUILD_DEFS+=		INIT_SYSTEM

_PKGSRC_MKPIE=	no
.if (${PKGSRC_MKPIE:tl} == "yes") && \
    (${_OPSYS_SUPPORTS_MKPIE:Uno} == "yes")
_PKGSRC_MKPIE=	yes
.endif

_PKGSRC_USE_FORTIFY=	no
.if (${PKGSRC_USE_FORTIFY:tl} == "yes") && \
    (${_OPSYS_SUPPORTS_FORTIFY:Uno} == "yes")
_PKGSRC_USE_FORTIFY=	yes
.endif

_PKGSRC_USE_RELRO=	no
.if (${PKGSRC_USE_RELRO:tl} == "yes") && \
    (${_OPSYS_SUPPORTS_RELRO:Uno} == "yes")
_PKGSRC_USE_RELRO=	yes
.endif

_PKGSRC_USE_SSP=	no
.if (${PKGSRC_USE_SSP:tl} == "yes") && \
    (${_OPSYS_SUPPORTS_SSP:Uno} == "yes")
_PKGSRC_USE_SSP=	yes
.endif

# Enable cwrappers if requested unless we're building the wrappers themselves.
.if ${USE_CWRAPPERS:tl} != "no" && empty(PKGPATH:Mpkgtools/cwrappers)
_USE_CWRAPPERS=		yes
.else
_USE_CWRAPPERS=		no
.endif

# Wrapper framework definitions
.include "wrapper/wrapper-defs.mk"

# Binary emulator framework definitions
.if defined(EMUL_PLATFORMS) && !empty(EMUL_PLATFORMS)
.  include "emulator/emulator-vars.mk"
.endif

# System features framework
.include "features/features-vars.mk"

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
_PKG_VARS.dirs=		WRKSRC PATCHDIR FILESDIR PKGDIR
_SYS_VARS.dirs=		WRKDIR DESTDIR PKG_SYSCONFBASEDIR

# List of 64bit operating systems with sizeof(int) != sizeof(void *).
# This can be used with BROKEN_ON_PLATFORM for software that is not
# 64bit clean.
#
# Keywords: BROKEN_ON_PLATFORM 64bit
#
LP64PLATFORMS=		*-*-aarch64 *-*-aarch64eb *-*-alpha *-*-ia64 \
			*-*-mips64eb *-*-mips64el *-*-powerpc64 *-*-riscv64 \
			*-*-sparc64 *-*-x86_64

# Lists of big-endian and little-endian platforms, to be used with
# BROKEN_ON_PLATFORM.
#
# Keywords: BROKEN_ON_PLATFORM little-endian big-endian endian
#
_BIGENDIANCPUS=		coldfire hppa m68000 m68k mips64eb mipseb or1k \
			powerpc powerpc64 sh3eb sparc sparc64
_LITTLEENDIANCPUS=	alpha i386 ia64 mips64el mipsel riscv32 riscv64 \
			sh3el vax x86_64

# piles of ARM variants
_ARMCPUS+=		arm earm earmhf earmv4 earmv5 earmv6 earmv6hf
_ARMCPUS+=		earmv7 earmv7hf aarch64
_BIGENDIANCPUS+=	${_ARMCPUS:S/$/eb/}
_LITTLEENDIANCPUS+=	${_ARMCPUS}

BIGENDIANPLATFORMS=	${_BIGENDIANCPUS:S/^/*-*-/}
LITTLEENDIANPLATFORMS=	${_LITTLEENDIANCPUS:S/^/*-*-/}


.endif	# BSD_PKG_MK
