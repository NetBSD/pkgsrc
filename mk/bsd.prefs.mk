# $NetBSD: bsd.prefs.mk,v 1.118.2.1 2003/07/16 09:33:47 jlam Exp $
#
# Make file, included to get the site preferences, if any.  Should
# only be included by package Makefiles before any .if defined()
# statements or modifications to "passed" variables (CFLAGS, LDFLAGS, ...),
# to make sure any variables defined in /etc/mk.conf, $MAKECONF, or
# the system defaults (sys.mk and bsd.own.mk) are used.

# Do not recursively include mk.conf, redefine OPSYS, include bsd.own.mk, etc.
.ifndef BSD_PKG_MK

# Let mk.conf know that this is pkgsrc.
BSD_PKG_MK=1
__PREFIX_SET__:=${PREFIX}

.if exists(/usr/bin/uname)
UNAME=/usr/bin/uname
.elif exists(/bin/uname)
UNAME=/bin/uname
.else
UNAME=echo Unknown
.endif

.ifndef OPSYS
OPSYS!=			${UNAME} -s
.endif
MAKEFLAGS+=		OPSYS=${OPSYS}
.ifndef OS_VERSION
OS_VERSION!=		${UNAME} -r
.endif
.ifndef LOWER_OS_VERSION
LOWER_OS_VERSION!=	echo ${OS_VERSION} | tr 'A-Z' 'a-z'
.endif
MAKEFLAGS+=		OS_VERSION=${OS_VERSION}

# Preload these for architectures not in all variations of bsd.own.mk.
GNU_ARCH.alpha?=	alpha
GNU_ARCH.arm26?=	arm
GNU_ARCH.arm32?=	arm
GNU_ARCH.i386?=		i386
GNU_ARCH.i486?=		i386
GNU_ARCH.i586?=		i386
GNU_ARCH.i686?=		i386
GNU_ARCH.m68000?=	m68010
GNU_ARCH.m68k?=		m68k
GNU_ARCH.mips?=		mipsel
GNU_ARCH.mipseb?=	mipseb
GNU_ARCH.mipsel?=	mipsel
GNU_ARCH.ns32k?=	ns32k
GNU_ARCH.powerpc?=	powerpc
GNU_ARCH.sh3eb?=	sh
GNU_ARCH.sh3el?=	shle
GNU_ARCH.sparc?=	sparc
GNU_ARCH.sparc64?=	sparc64
GNU_ARCH.vax?=		vax
MACHINE_GNU_ARCH?=	${GNU_ARCH.${MACHINE_ARCH}}

.if ${OPSYS} == "NetBSD"
LOWER_OPSYS?=		netbsd

.elif ${OPSYS} == "FreeBSD"
LOWER_OPSYS?=		freebsd
LOWER_ARCH!=		${UNAME} -p
MACHINE_ARCH=		${LOWER_ARCH}
MAKEFLAGS+=		LOWER_ARCH=${LOWER_ARCH}
.  if ${LOWER_ARCH} == "i386"
LOWER_VENDOR?=		pc
.  else
LOWER_VENDOR?=		unknown
.  endif

.elif ${OPSYS} == "SunOS"
.  if ${MACHINE_ARCH} == "sparc"
SPARC_TARGET_ARCH?=	sparcv7
.  elif ${MACHINE_ARCH} == "sun4"
MACHINE_ARCH=		sparc
SPARC_TARGET_ARCH?=	sparcv7
.  elif ${MACHINE_ARCH} == "i86pc"
MACHINE_ARCH=		i386
.  elif ${MACHINE_ARCH} == "unknown"
.    if !defined(LOWER_ARCH)
LOWER_ARCH!=		${UNAME} -p
.    endif	# !defined(LOWER_ARCH)
MAKEFLAGS+=		LOWER_ARCH=${LOWER_ARCH}
.  endif
LOWER_VENDOR?=		sun
LOWER_OPSYS?=		solaris

.elif ${OPSYS} == "Linux"
LOWER_OPSYS?=		linux
MACHINE_ARCH:=          ${MACHINE_ARCH:C/i.86/i386/}
.  if !defined(LOWER_ARCH)
LOWER_ARCH!=		${UNAME} -m | sed -e 's/i.86/i386/'
.  endif # !defined(LOWER_ARCH)
.  if ${MACHINE_ARCH} == "unknown" || ${MACHINE_ARCH} == ""
MACHINE_ARCH=		${LOWER_ARCH}
MAKEFLAGS+=		LOWER_ARCH=${LOWER_ARCH}
.  endif
.  if exists(/etc/debian_version)
LOWER_VENDOR?=		debian
.  elif exists(/etc/mandrake-release)
LOWER_VENDOR?=		mandrake
.  elif exists(/etc/redhat-version)
LOWER_VENDOR?=		redhat
.  elif exists(/etc/slackware-version)
LOWER_VENDOR?=		slackware
.  elif ${LOWER_ARCH} == "i386"
LOWER_VENDOR?=          pc
.  else
LOWER_VENDOR?=          unknown
.  endif

.elif ${OPSYS} == "Darwin"
LOWER_OPSYS?=		darwin
LOWER_ARCH!=		${UNAME} -p
MACHINE_ARCH=		${LOWER_ARCH}
MAKEFLAGS+=		LOWER_ARCH=${LOWER_ARCH}
LOWER_VENDOR?=		apple

.elif ${OPSYS:MIRIX*} != ""
LOWER_ARCH!=		${UNAME} -p
LOWER_OPSYS?=		irix${OS_VERSION}
LOWER_VENDOR?=		sgi

.elif !defined(LOWER_OPSYS)
LOWER_OPSYS!=		echo ${OPSYS} | tr A-Z a-z
.endif

MAKEFLAGS+=		LOWER_OPSYS=${LOWER_OPSYS}

LOWER_VENDOR?=
LOWER_ARCH?=		${MACHINE_GNU_ARCH}

MACHINE_PLATFORM?=	${OPSYS}-${OS_VERSION}-${MACHINE_ARCH}
MACHINE_GNU_PLATFORM?=	${LOWER_ARCH}-${LOWER_VENDOR}-${LOWER_OPSYS}${APPEND_ELF}

# Needed on NetBSD and SunOS (zoularis) to prevent an "install:" target
# from being created in bsd.own.mk.
NEED_OWN_INSTALL_TARGET=no

# This prevents default use of the cross-tool harness in the "src" tree,
# in the odd possible case of someone extracting "pkgsrc" underneath "src".
USETOOLS=		no
MAKE_ENV+=		USETOOLS=no

# Set this before <bsd.own.mk> does, since it doesn't know about Darwin
.if ${OPSYS} == "Darwin"
OBJECT_FMT?=		Mach-O
.endif

.include <bsd.own.mk>

# /usr/share/mk/bsd.own.mk on NetBSD 1.3 does not define OBJECT_FMT
.if ${MACHINE_PLATFORM:MNetBSD-1.3*} != ""
.if ${MACHINE_ARCH} == "alpha" || \
${MACHINE_ARCH} == "mipsel" || ${MACHINE_ARCH} == "mipseb" || \
${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc64"
OBJECT_FMT?=		ELF
.else
OBJECT_FMT?=		a.out
.endif
.endif

# include the defaults file
.if exists(${.CURDIR}/../../mk/bsd.pkg.defaults.mk)
.include "${.CURDIR}/../../mk/bsd.pkg.defaults.mk"
.elif exists(${.CURDIR}/../mk/bsd.pkg.defaults.mk)
.include "${.CURDIR}/../mk/bsd.pkg.defaults.mk"
.elif exists(${.CURDIR}/mk/bsd.pkg.defaults.mk)
.include "${.CURDIR}/mk/bsd.pkg.defaults.mk"
.endif

.if ${OPSYS} == "NetBSD"
. if ${OBJECT_FMT} == "ELF" && \
    (${MACHINE_GNU_ARCH} == "arm" || \
     ${MACHINE_ARCH} == "i386" || \
     ${MACHINE_ARCH} == "m68k" || \
     ${MACHINE_ARCH} == "m68000" || \
     ${MACHINE_GNU_ARCH} == "sh" || \
     ${MACHINE_GNU_ARCH} == "shle" || \
     ${MACHINE_ARCH} == "sparc" || \
     ${MACHINE_ARCH} == "vax")
APPEND_ELF=		elf
. endif
.endif

SHAREOWN?=		${DOCOWN}
SHAREGRP?=		${DOCGRP}
SHAREMODE?=		${DOCMODE}

.if defined(PREFIX) && (${PREFIX} != ${__PREFIX_SET__})
.BEGIN:
	@${ECHO_MSG} "You can NOT set PREFIX manually or in mk.conf.  Set LOCALBASE or X11BASE"
	@${ECHO_MSG} "depending on your needs.  See the pkg system documentation for more info."
	@${FALSE}
.endif

# Preload all default values for CFLAGS, LDFLAGS, etc. before bsd.pkg.mk
# or a pkg Makefile modifies them.
.include <sys.mk>

# Load the OS-specific definitions for program variables.  Default to loading
# the NetBSD ones if an OS-specific file doesn't exist.
.if exists(${.CURDIR}/../../mk/defs.${OPSYS}.mk)
.include "${.CURDIR}/../../mk/defs.${OPSYS}.mk"
.elif exists(${.CURDIR}/../mk/defs.${OPSYS}.mk)
.include "${.CURDIR}/../mk/defs.${OPSYS}.mk"
.elif exists(${.CURDIR}/mk/defs.${OPSYS}.mk)
.include "${.CURDIR}/mk/defs.${OPSYS}.mk"
.elif exists(${.CURDIR}/../../mk/defs.NetBSD.mk)
.include "${.CURDIR}/../../mk/defs.NetBSD.mk"
.elif exists(${.CURDIR}/../mk/defs.NetBSD.mk)
.include "${.CURDIR}/../mk/defs.NetBSD.mk"
.else exists(${.CURDIR}/mk/defs.NetBSD.mk)
.include "${.CURDIR}/mk/defs.NetBSD.mk"
.endif

# if the system is IPv6-ready, compile with IPv6 support turned on.
.if empty(_OPSYS_HAS_INET6:M[nN][oO]) && !defined(USE_SOCKS)
USE_INET6?=		YES
.else
USE_INET6?=		NO
.endif

LOCALBASE?=		${DESTDIR}/usr/pkg
.if ${OPSYS} == "SunOS"
# On Solaris, we default to using OpenWindows for X11.
X11BASE?=               ${DESTDIR}/usr/openwin
.else
X11BASE?=		${DESTDIR}/usr/X11R6
.endif
CROSSBASE?=		${LOCALBASE}/cross

# Set X11PREFIX to reflect the install directory of X11 packages.
# Set XMKMF_CMD properly if xpkgwedge is installed.
#
# The check for the existence of ${X11BASE}/lib/X11/config/xpkgwedge.def
# is to catch users of xpkgwedge<1.0.
#
XMKMF?=			${XMKMF_CMD} ${XMKMF_FLAGS} -a
XMKMF_FLAGS?=		# empty
.if exists(${LOCALBASE}/lib/X11/config/xpkgwedge.def) || \
    exists(${X11BASE}/lib/X11/config/xpkgwedge.def)
HAVE_XPKGWEDGE=		yes
X11PREFIX=		${LOCALBASE}
XMKMF_CMD?=		${X11PREFIX}/bin/pkgxmkmf
.else
X11PREFIX=		${X11BASE}
XMKMF_CMD?=		${X11PREFIX}/bin/xmkmf
.endif

# RPATH_FLAG publicly exports the linker flag used to specify run-time
# library search paths.
#
RPATH_FLAG?=	${_OPSYS_RPATH_NAME}

# WHOLE_ARCHIVE_FLAG and NO_WHOLE_ARCHIVE_FLAG publically export the
# linker flags to extract all symbols from a static archive.
WHOLE_ARCHIVE_FLAG?=	${_OPSYS_WHOLE_ARCHIVE_FLAG}
NO_WHOLE_ARCHIVE_FLAG?=	${_OPSYS_NO_WHOLE_ARCHIVE_FLAG}

.ifndef DIGEST
DIGEST:=		${LOCALBASE}/bin/digest
MAKEFLAGS+=		DIGEST=${DIGEST}
.endif

# Only add the DIGEST_VERSION value to MAKEFLAGS when we know
# we've got a valid version number, retrieved from the digest(1)
# binary. This is different to PKGTOOLS_VERSION, since, in that
# case, the build dies when pkg_info(1) is out of date.

.if !exists(${DIGEST})
DIGEST_VERSION=		20010301
.elif !defined(DIGEST_VERSION)
DIGEST_VERSION!= 	${DIGEST} -V 2>/dev/null
MAKEFLAGS+=		DIGEST_VERSION="${DIGEST_VERSION}"
.endif

PKG_DBDIR?=		${DESTDIR}/var/db/pkg

PKG_ADD_CMD?=		${PKG_TOOLS_BIN}/pkg_add
PKG_ADMIN_CMD?=		${PKG_TOOLS_BIN}/pkg_admin
PKG_CREATE_CMD?=	${PKG_TOOLS_BIN}/pkg_create
PKG_DELETE_CMD?=	${PKG_TOOLS_BIN}/pkg_delete
PKG_INFO_CMD?=		${PKG_TOOLS_BIN}/pkg_info
PKG_VIEW_CMD?=		${PKG_TOOLS_BIN}/pkg_view

PKG_ADD?=		PKG_DBDIR=${PKG_DBDIR} ${PKG_ADD_CMD}
PKG_ADMIN?=		PKG_DBDIR=${PKG_DBDIR} ${PKG_ADMIN_CMD}
PKG_CREATE?=		PKG_DBDIR=${PKG_DBDIR} ${PKG_CREATE_CMD}
PKG_DELETE?=		PKG_DBDIR=${PKG_DBDIR} ${PKG_DELETE_CMD}
PKG_INFO?=		PKG_DBDIR=${PKG_DBDIR} ${PKG_INFO_CMD}
PKG_VIEW?=		${PKG_VIEW_CMD}

DEPOT_PKG_DELETE?=	PKG_DBDIR=${DEPOTBASE} ${PKG_DELETE_CMD}
DEPOT_PKG_INFO?=	PKG_DBDIR=${DEPOTBASE} ${PKG_INFO_CMD}

.ifndef PKGTOOLS_VERSION
PKGTOOLS_VERSION!=	${PKG_INFO} -V 2>/dev/null || echo 20010302
MAKEFLAGS+=		PKGTOOLS_VERSION="${PKGTOOLS_VERSION}"
.endif

.if (${OPSYS} == SunOS) && !defined(ZOULARIS_VERSION)
.if !exists(${ZOULARISBASE}/share/mk/zoularis.mk)
ZOULARIS_VERSION=	20000522
.else
.include "${ZOULARISBASE}/share/mk/zoularis.mk"
.endif
MAKEFLAGS+=		ZOULARIS_VERSION="${ZOULARIS_VERSION}"
.endif

_PKGSRCDIR?=		${.CURDIR:C|/[^/]*/[^/]*$||}
PKGPATH?=		${.CURDIR:C|.*/([^/]*/[^/]*)$|\1|}

DISTDIR?=		${_PKGSRCDIR}/distfiles
PACKAGES?=		${_PKGSRCDIR}/packages
TEMPLATES?=		${_PKGSRCDIR}/templates

PATCHDIR?=		${.CURDIR}/patches
SCRIPTDIR?=		${.CURDIR}/scripts
FILESDIR?=		${.CURDIR}/files
PKGDIR?=		${.CURDIR}

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
MAKEFLAGS+=		_HOSTNAME=${_HOSTNAME}
.  endif
WRKDIR_BASENAME?=	work.${_HOSTNAME:C|\..*||}
MAKEFLAGS+=		OBJHOSTNAME="${OBJHOSTNAME}"
.elif defined(OBJMACHINE)
WRKDIR_BASENAME?=	work.${MACHINE_ARCH}
MAKEFLAGS+=		OBJMACHINE="${OBJMACHINE}"
.else
WRKDIR_BASENAME?=	work
.endif

WRKDIR?=		${BUILD_DIR}/${WRKDIR_BASENAME}

# Sun C++ compilers don't support passing ld flags with -Wl to CC.
#
.if defined(USE_SUNPRO)
_COMPILER_LD_FLAG=		# pattern for Sun compilers
.else
_COMPILER_LD_FLAG=	-Wl,	# pattern for GCC and others
.endif

.endif	# BSD_PKG_MK
