# $NetBSD: bsd.prefs.mk,v 1.159 2004/04/25 22:42:51 tv Exp $
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

# Expand MAKE to a full path.
.if !defined(_MAKE)
_MAKE:=	${MAKE}
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

.if exists(/usr/bin/cut)
CUT=/usr/bin/cut
.elif exists(/bin/cut)
CUT=/bin/cut
.else
CUT=echo Unknown
.endif

.ifndef OPSYS
OPSYS!=			${UNAME} -s | tr -d /
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

.elif ${OPSYS} == "BSDOS"
LOWER_OPSYS?=		bsdi

.elif ${OPSYS} == "FreeBSD"
LOWER_OPSYS?=		freebsd
LOWER_ARCH!=		${UNAME} -p
MACHINE_ARCH=		${LOWER_ARCH}
MAKEFLAGS+=		LOWER_ARCH=${LOWER_ARCH}
LOWER_OPSYS_VERSUFFIX!=	echo ${LOWER_OS_VERSION} | ${CUT} -c -1
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
LOWER_OPSYS_VERSUFFIX=	2

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

.elif ${OPSYS} == "Interix"
LOWER_OPSYS?=		interix3
LOWER_VENDOR?=		pc

.elif !defined(LOWER_OPSYS)
LOWER_OPSYS!=		echo ${OPSYS} | tr A-Z a-z
.endif

MAKEFLAGS+=		LOWER_OPSYS=${LOWER_OPSYS}

LOWER_VENDOR?=
LOWER_ARCH?=		${MACHINE_GNU_ARCH}

MACHINE_PLATFORM?=	${OPSYS}-${OS_VERSION}-${MACHINE_ARCH}
MACHINE_GNU_PLATFORM?=	${LOWER_ARCH}-${LOWER_VENDOR}-${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}

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

.include <bsd.own.mk>

# /usr/share/mk/bsd.own.mk on NetBSD 1.3 does not define OBJECT_FMT
.if !empty(MACHINE_PLATFORM:MNetBSD-1.3*)
.  if ${MACHINE_ARCH} == "alpha" || \
      ${MACHINE_ARCH} == "mipsel" || ${MACHINE_ARCH} == "mipseb" || \
      ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc64"
OBJECT_FMT?=		ELF
.  else
OBJECT_FMT?=		a.out
.  endif
# override what bootstrap-pkgsrc sets, which isn't right for NetBSD
# 1.4.
# XXX other ELF platforms in 1.4 need to be added to here.
.elif !empty(MACHINE_PLATFORM:MNetBSD-1.4*)
.  if ${MACHINE_ARCH} == "alpha" || \
      ${MACHINE_ARCH} == "mipsel" || ${MACHINE_ARCH} == "mipseb" || \
      ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc64"
OBJECT_FMT=		ELF
.  else
OBJECT_FMT=		a.out
.  endif
.endif

.if ${OPSYS} == "OpenBSD"
.  if defined(ELF_TOOLCHAIN) && ${ELF_TOOLCHAIN} == "yes"
OBJECT_FMT?=	ELF
.  else
OBJECT_FMT?=	a.out
.  endif
.endif

# include the defaults file
.if exists(${.CURDIR}/../../mk/bsd.pkg.defaults.mk)
.  include "${.CURDIR}/../../mk/bsd.pkg.defaults.mk"
.elif exists(${.CURDIR}/../mk/bsd.pkg.defaults.mk)
.  include "${.CURDIR}/../mk/bsd.pkg.defaults.mk"
.elif exists(${.CURDIR}/mk/bsd.pkg.defaults.mk)
.  include "${.CURDIR}/mk/bsd.pkg.defaults.mk"
.endif

.if ${OPSYS} == "NetBSD"
.  if ${OBJECT_FMT} == "ELF" && \
   (${MACHINE_GNU_ARCH} == "arm" || \
    ${MACHINE_ARCH} == "i386" || \
    ${MACHINE_ARCH} == "m68k" || \
    ${MACHINE_ARCH} == "m68000" || \
    ${MACHINE_GNU_ARCH} == "sh" || \
    ${MACHINE_GNU_ARCH} == "shle" || \
    ${MACHINE_ARCH} == "sparc" || \
    ${MACHINE_ARCH} == "vax")
APPEND_ELF=		elf
.  endif
.endif

PKGDIRMODE?=		755
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
.  include "${.CURDIR}/../../mk/defs.${OPSYS}.mk"
.elif exists(${.CURDIR}/../mk/defs.${OPSYS}.mk)
.  include "${.CURDIR}/../mk/defs.${OPSYS}.mk"
.elif exists(${.CURDIR}/mk/defs.${OPSYS}.mk)
.  include "${.CURDIR}/mk/defs.${OPSYS}.mk"
.elif exists(${.CURDIR}/../../mk/defs.NetBSD.mk)
.  include "${.CURDIR}/../../mk/defs.NetBSD.mk"
.elif exists(${.CURDIR}/../mk/defs.NetBSD.mk)
.  include "${.CURDIR}/../mk/defs.NetBSD.mk"
.else exists(${.CURDIR}/mk/defs.NetBSD.mk)
.  include "${.CURDIR}/mk/defs.NetBSD.mk"
.endif

PKG_PHASE?=		none
#
# The PHASES_AFTER_<phase> variables list every phase "greater than or
# equal to" <phase>.
#
PHASES_AFTER_FETCH=	fetch ${PHASES_AFTER_EXTRACT}
PHASES_AFTER_EXTRACT=	extract ${PHASES_AFTER_PATCH}
PHASES_AFTER_PATCH=	patch ${PHASES_AFTER_TOOLS}
PHASES_AFTER_TOOLS=	tools ${PHASES_AFTER_BUILDLINK}
PHASES_AFTER_BUILDLINK=	buildlink ${PHASES_AFTER_CONFIGURE}
PHASES_AFTER_CONFIGURE=	configure ${PHASES_AFTER_BUILD}
PHASES_AFTER_BUILD=	build ${PHASES_AFTER_INSTALL}
PHASES_AFTER_INSTALL=	install ${PHASES_AFTER_PACKAGE}
PHASES_AFTER_PACKAGE=	package

# Set the style of installation to be performed for the package.  The
# funky make variable modifiers just select the first word of the value
# stored in the referenced variable.
#
.for _pref_ in ${PKG_INSTALLATION_PREFS}
.  if !empty(PKG_INSTALLATION_TYPES:M${_pref_})
PKG_INSTALLATION_TYPE?=	${PKG_INSTALLATION_TYPES:M${_pref_}:S/^/_pkginsttype_/1:M_pkginsttype_*:S/^_pkginsttype_//}
.  endif
.endfor
PKG_INSTALLATION_TYPE?=	none

# if the system is IPv6-ready, compile with IPv6 support turned on.
.if defined(USE_INET6)
.  if empty(USE_INET6:M[Yy][Ee][Ss]) || defined(USE_SOCKS)
USE_INET6=		NO
.  else
USE_INET6=		YES
.  endif
.elif empty(_OPSYS_HAS_INET6:M[nN][oO]) && !defined(USE_SOCKS)
USE_INET6=		YES
.else
USE_INET6=		NO
.endif

LOCALBASE?=		${DESTDIR}/usr/pkg
.if ${OPSYS} == "SunOS"
# On Solaris, we default to using OpenWindows for X11.
X11BASE?=               ${DESTDIR}/usr/openwin
.else
X11BASE?=		${DESTDIR}/usr/X11R6
.endif
CROSSBASE?=		${LOCALBASE}/cross

# If xpkgwedge.def is found, then clearly we're using xpkgwedge.
.if exists(${LOCALBASE}/lib/X11/config/xpkgwedge.def) || \
    exists(${X11BASE}/lib/X11/config/xpkgwedge.def)
USE_XPKGWEDGE=  yes
.else
USE_XPKGWEDGE?=	yes
.endif

.if defined(_OPSYS_NEEDS_XPKGWEDGE) && \
    !empty(_OPSYS_NEEDS_XPKGWEDGE:M[yY][eE][sS])
USE_XPKGWEDGE=	yes
.endif

.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
USE_XPKGWEDGE=		yes
_XPKGWEDGE_REQD=	1.9
.else
_XPKGWEDGE_REQD=	1.5
.endif

# Set X11PREFIX to reflect the install directory of X11 packages.
# Set XMKMF_CMD properly if xpkgwedge is installed.
#
# The check for the existence of ${X11BASE}/lib/X11/config/xpkgwedge.def
# is to catch users of xpkgwedge<1.0.
#
XMKMF?=			${XMKMF_CMD} ${XMKMF_FLAGS} -a
XMKMF_FLAGS?=		# empty
.if !empty(USE_XPKGWEDGE:M[Yy][Ee][Ss]) 
X11PREFIX=		${LOCALBASE}
XMKMF_CMD?=		${X11PREFIX}/bin/pkgxmkmf
.else
X11PREFIX=		${X11BASE}
XMKMF_CMD?=		${X11PREFIX}/bin/xmkmf
.endif

DEPOT_SUBDIR?=		packages
DEPOTBASE=		${LOCALBASE}/${DEPOT_SUBDIR}

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
MAKEFLAGS+=		DIGEST_VERSION=${DIGEST_VERSION}
.endif

# This is the package database directory for the default view.
PKG_DBDIR?=		${DESTDIR}/var/db/pkg

# _PKG_DBDIR is the actual packages database directory where we register
# packages.
#
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
_PKG_DBDIR=		${PKG_DBDIR}
.elif ${PKG_INSTALLATION_TYPE} == "pkgviews"
_PKG_DBDIR=		${DEPOTBASE}
.endif

PKG_ADD_CMD?=		${PKG_TOOLS_BIN}/pkg_add
PKG_ADMIN_CMD?=		${PKG_TOOLS_BIN}/pkg_admin
PKG_CREATE_CMD?=	${PKG_TOOLS_BIN}/pkg_create
PKG_DELETE_CMD?=	${PKG_TOOLS_BIN}/pkg_delete
PKG_INFO_CMD?=		${PKG_TOOLS_BIN}/pkg_info
PKG_VIEW_CMD?=		${PKG_TOOLS_BIN}/pkg_view
LINKFARM_CMD?=		${PKG_TOOLS_BIN}/linkfarm

.if !defined(PKGTOOLS_VERSION)
PKGTOOLS_VERSION!=	${PKG_INFO_CMD} -V 2>/dev/null || echo 20010302
MAKEFLAGS+=		PKGTOOLS_VERSION=${PKGTOOLS_VERSION}
.endif

# The binary pkg_install tools all need to consistently to refer to the
# correct package database directory.
#
.if ${PKGTOOLS_VERSION} < 20030823
PKGTOOLS_ENV?=		PKG_DBDIR=${_PKG_DBDIR}
PKGTOOLS_ARGS?=		# empty
.else
PKGTOOLS_ENV?=		# empty
PKGTOOLS_ARGS?=		-K ${_PKG_DBDIR}
.endif

# Views are rooted in ${LOCALBASE}, all packages are depoted in
# ${DEPOTBASE}, and the package database directory for the default view
# is in ${PKG_DBDIR}.
#
PKG_VIEW_ARGS?=		-W ${LOCALBASE} -d ${DEPOTBASE} -k ${PKG_DBDIR}

PKG_ADD?=		${PKGTOOLS_ENV} ${PKG_ADD_CMD} ${PKGTOOLS_ARGS}
PKG_ADMIN?=		${PKGTOOLS_ENV} ${PKG_ADMIN_CMD} ${PKGTOOLS_ARGS}
PKG_CREATE?=		${PKGTOOLS_ENV} ${PKG_CREATE_CMD} ${PKGTOOLS_ARGS}
PKG_DELETE?=		${PKGTOOLS_ENV} ${PKG_DELETE_CMD} ${PKGTOOLS_ARGS}
PKG_INFO?=		${PKGTOOLS_ENV} ${PKG_INFO_CMD} ${PKGTOOLS_ARGS}
PKG_VIEW?=		${PKGTOOLS_ENV} ${PKG_VIEW_CMD} ${PKG_VIEW_ARGS}
LINKFARM?=		${LINKFARM_CMD}

# "${PKG_BEST_EXISTS} pkgpattern" prints out the name of the installed
# package that best matches pkgpattern.  Use this instead of
# "${PKG_INFO} -e pkgpattern" if the latter would return more than one
# package name.
#
PKG_BEST_EXISTS?=	${PKG_ADMIN} -b -d ${_PKG_DBDIR} -S lsbest

USE_BUILDLINK2?=	no	# default to not using buildlink2
USE_BUILDLINK3?=	no	# default to not using buildlink3
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
USE_BUILDLINK3=		yes	# pkgviews requires buildlink3
.endif

.if exists(${LOCALBASE}/bsd/share/mk/zoularis.mk)
PKG_FAIL_REASON+=	'You appear to have a deprecated Zoularis installation.'
PKG_FAIL_REASON+=	'Please update your system to bootstrap-pkgsrc and remove the'
PKG_FAIL_REASON+=	'${LOCALBASE}/bsd directory.'
PKG_FAIL_REASON+=	'See http://mail-index.NetBSD.org/tech-pkg/2004/02/14/0004.html'
PKG_FAIL_REASON+=	'for more details.'
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

_PKGSRC_DEPS?=		# empty

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
MAKEFLAGS+=		OBJHOSTNAME=${OBJHOSTNAME}
.elif defined(OBJMACHINE)
WRKDIR_BASENAME?=	work.${MACHINE_ARCH}
MAKEFLAGS+=		OBJMACHINE=${OBJMACHINE}
.else
WRKDIR_BASENAME?=	work
.endif

WRKDIR?=		${BUILD_DIR}/${WRKDIR_BASENAME}

# There are many uses for a common log file, so define one that may be
# picked up and used by tools.mk, bsd.buildlink2.mk, etc.
#
WRKLOG?=		${WRKDIR}/.work.log

.endif	# BSD_PKG_MK
