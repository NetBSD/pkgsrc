#	$NetBSD: bsd.pkg.mk,v 1.1540.2.14 2005/01/24 18:50:16 tv Exp $
#
# This file is in the public domain.
#
# This file is derived from bsd.port.mk - 940820 Jordan K. Hubbard.
#
# Please see the pkgsrc/doc/guide manual for details on the
# variables used in this make file template.
#
# XXX tv: rev 1.1554 is not merged yet (phase "error handlers")
#

############################################################################
# Include any preferences, if not already included, and common definitions
############################################################################

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.hacks.mk"

# _PKG_PHASES_WRKDIR is an ordered list of phases which require ${WRKDIR}
# to exist.  _PKG_PHASES_ALL also includes the phases from before ${WRKDIR}
# is created.  These macros are used below mainly in .for loops.

_PKG_PHASES_ALL=	fetch checksum ${_PKG_PHASES_WRKDIR}
_PKG_PHASES_WRKDIR=	depends extract patch tools wrapper \
			configure build test install package

# PATH is recalculated below, so save its original incarnation here.
.if !defined(_PATH_ORIG)
_PATH_ORIG:=		${PATH}
MAKEFLAGS+=		_PATH_ORIG=${_PATH_ORIG:Q}
.endif

############################################################################
# Transform package Makefile variables and set defaults
############################################################################

CHECK_FILES?=		NO	# run check-files after install
CHECK_FILES_STRICT?=	NO	# make check-files very strict on errors
CHECK_SHLIBS?=		YES	# run check-shlibs after install
CLEANDEPENDS?=		NO
DEINSTALLDEPENDS?=	NO	# add -R to pkg_delete
MKCRYPTO?=		YES	# build crypto packages by default
NOCLEAN?=		NO	# don't clean up after update
REINSTALL?=		NO	# reinstall upon update
SHLIB_HANDLING?=	YES	# do automatic shared lib handling

##### Variant spellings

.if defined(LICENCE) && !defined(LICENSE)
LICENSE=		${LICENCE}
.endif
.if defined(ACCEPTABLE_LICENCES) && !defined(ACCEPTABLE_LICENSES)
ACCEPTABLE_LICENSES=	${ACCEPTABLE_LICENCES}
.endif

##### PKGBASE, PKGNAME[_NOREV], PKGVERSION

PKGBASE?=		${PKGNAME:C/-[^-]*$//}
PKGVERSION?=		${PKGNAME:C/^.*-//}
.if defined(PKGREVISION) && !empty(PKGREVISION) && (${PKGREVISION} != "0")
.  if defined(PKGNAME)
PKGNAME_NOREV:=		${PKGNAME}
PKGNAME:=		${PKGNAME}nb${PKGREVISION}
.  else
PKGNAME?=		${DISTNAME}nb${PKGREVISION}
PKGNAME_NOREV=		${DISTNAME}
.  endif
.else
PKGNAME?=		${DISTNAME}
PKGNAME_NOREV=		${PKGNAME}
.endif

##### PLIST

.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
PLIST_TYPE?=		dynamic
.endif
PLIST_TYPE?=		static

.if !defined(PLIST_SRC)
.  if exists(${PKGDIR}/PLIST.common)
PLIST_SRC+=		${PKGDIR}/PLIST.common
.  endif
.  if exists(${PKGDIR}/PLIST.${OPSYS})
PLIST_SRC+=		${PKGDIR}/PLIST.${OPSYS}
.  elif exists(${PKGDIR}/PLIST)
PLIST_SRC+=		${PKGDIR}/PLIST
.  endif
.  if exists(${PKGDIR}/PLIST.common_end)
PLIST_SRC+=		${PKGDIR}/PLIST.common_end
.  endif
.endif	# !PLIST_SRC

##### Others

_DISTDIR?=		${DISTDIR}/${DIST_SUBDIR}
BUILD_DEFS?=		# empty
BUILD_DEPENDS?=		# empty
BUILD_TARGET?=		all
DEPENDS?=		# empty
DESCR_SRC?=		${PKGDIR}/DESCR
DIGEST_ALGORITHM?=	SHA1
DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
DISTINFO_FILE?=		${PKGDIR}/distinfo
COMMENT?=		(no description)
CONFIGURE_DIRS?=	${WRKSRC}
CONFIGURE_SCRIPT?=	./configure
EXTRACT_ONLY?=		${DISTFILES}
EXTRACT_SUFX?=		.tar.gz
INSTALL_DIRS?=		${BUILD_DIRS}
INSTALL_MAKE_FLAGS?=	${MAKE_FLAGS}
INSTALL_TARGET?=	install
INTERACTIVE_STAGE?=	none
MAINTAINER?=		tech-pkg@NetBSD.org
MAKE_FLAGS?=		# empty
MAKEFILE?=		Makefile
PKG_SUFX?=		.tgz
PKGFILE?=		${PKGREPOSITORY}/${PKGNAME}${PKG_SUFX}
PKGREPOSITORY?=		${PACKAGES}/${PKGREPOSITORYSUBDIR}
PKGREPOSITORYSUBDIR?=	All
PKGWILDCARD?=		${PKGBASE}-[0-9]*
SVR4_PKGNAME?=		${PKGNAME}
USE_DIGEST?=		YES
USE_GNU_TOOLS?=		# empty
WRKSRC?=		${WRKDIR}/${DISTNAME}

BUILD_DEFS_FIXED+=	PKGPATH
BUILD_DEFS_FIXED+=	OPSYS OS_VERSION MACHINE_ARCH MACHINE_GNU_ARCH
BUILD_DEFS_FIXED+=	CPPFLAGS CFLAGS FFLAGS LDFLAGS
BUILD_DEFS_FIXED+=	CONFIGURE_ENV CONFIGURE_ARGS
BUILD_DEFS_FIXED+=	OBJECT_FMT LICENSE RESTRICTED
BUILD_DEFS_FIXED+=	NO_SRC_ON_FTP NO_SRC_ON_CDROM
BUILD_DEFS_FIXED+=	NO_BIN_ON_FTP NO_BIN_ON_CDROM
BUILD_DEFS_FIXED+=	${OSVERSION_SPECIFIC:DOSVERSION_SPECIFIC}

##### Non-overridable constants

# Latest versions of tools required for correct pkgsrc operation.
DIGEST_REQD=		20010302
PKGTOOLS_REQD=		${_OPSYS_PKGTOOLS_REQD:U20030918}

DDIR=			${WRKDIR}/.DDIR
DESCR=			${WRKDIR}/.DESCR
DLIST=			${WRKDIR}/.DLIST
PLIST=			${WRKDIR}/.PLIST

# Files to create for versioning and build information
BUILD_VERSION_FILE=	${WRKDIR}/.build_version
BUILD_INFO_FILE=	${WRKDIR}/.build_info

# Files containing size of pkg w/o and w/ all required pkgs
SIZE_PKG_FILE=		${WRKDIR}/.SizePkg
SIZE_ALL_FILE=		${WRKDIR}/.SizeAll

# File to denote "no deletion of a package"
PRESERVE_FILE=		${WRKDIR}/.PRESERVE

.for targ in ${_PKG_PHASES_WRKDIR}
${targ}_COOKIE=		${WRKDIR}/.${targ}_done
.endfor

##### Transform USE_* into dependencies

.include "../../mk/bsd.pkg.use.mk"

############################################################################
# Sanity checks
############################################################################

# Fail-safe in the case of circular dependencies
.if defined(_PKGSRC_DEPS) && defined(PKGNAME) && !empty(_PKGSRC_DEPS:M${PKGNAME})
PKG_FAIL_REASON+=	"Circular dependency detected"
.endif

# PKG_INSTALLATION_TYPE can only be one of two values: "pkgviews" or
# "overwrite".
.if (${PKG_INSTALLATION_TYPE} != "pkgviews") && \
    (${PKG_INSTALLATION_TYPE} != "overwrite")
PKG_FAIL_REASON+=	"PKG_INSTALLATION_TYPE must be \`\`pkgviews'' or \`\`overwrite''."
.endif

.if empty(PKG_INSTALLATION_TYPES:M${PKG_INSTALLATION_TYPE})
PKG_FAIL_REASON+=	"This package doesn't support PKG_INSTALLATION_TYPE=${PKG_INSTALLATION_TYPE}."
.endif

.if (${PLIST_TYPE} != "dynamic") && (${PLIST_TYPE} != "static")
PKG_FAIL_REASON+=	"PLIST_TYPE must be \`\`dynamic'' or \`\`static''."
.endif

.if (${PKG_INSTALLATION_TYPE} == "overwrite") && (${PLIST_TYPE} != "static")
PKG_FAIL_REASON+=	"PLIST_TYPE must be \`\`static'' for \`\`overwrite'' packages."
.endif

# Check that we are using up-to-date pkg_* tools with this file.
.if !defined(NO_PKGTOOLS_REQD_CHECK)
.  if ${PKGTOOLS_VERSION} < ${PKGTOOLS_REQD}
PKG_FAIL_REASON+='Error: The package tools installed on this system are out of date.'
PKG_FAIL_REASON+='The installed package tools are dated ${PKGTOOLS_VERSION:C|(....)(..)(..)|\1/\2/\3|} and you must update'
PKG_FAIL_REASON+='them to at least ${PKGTOOLS_REQD:C|(....)(..)(..)|\1/\2/\3|} using the following command:'
PKG_FAIL_REASON+=''
PKG_FAIL_REASON+='	cd ${PKGSRCDIR}/pkgtools/pkg_install && ${MAKE} clean && ${MAKE} install'
.  endif
.endif # NO_PKGTOOLS_REQD_CHECK

.if defined(ALL_TARGET)
PKG_FAIL_REASON+='ALL_TARGET is deprecated and must be replaced with BUILD_TARGET.'
.endif

.if defined(NO_WRKSUBDIR)
PKG_FAIL_REASON+='NO_WRKSUBDIR has been deprecated - please replace it with an explicit'
PKG_FAIL_REASON+='assignment of WRKSRC= $${WRKDIR}'
.endif # NO_WRKSUBDIR

# We need to make sure the buildlink-x11 package is not installed since it
# breaks builds that use imake.
.if defined(USE_IMAKE)
.  if exists(${LOCALBASE}/lib/X11/config/buildlinkX11.def) || \
      exists(${X11BASE}/lib/X11/config/buildlinkX11.def)
PKG_FAIL_REASON+= "${PKGNAME} uses imake, but the buildlink-x11 package was found." \
	 "    Please deinstall it (pkg_delete buildlink-x11)."
.  endif
.endif	# USE_IMAKE

.if !defined(CATEGORIES) || !defined(DISTNAME)
PKG_FAIL_REASON+='CATEGORIES and DISTNAME are mandatory.'
.endif

.if defined(LIB_DEPENDS)
PKG_FAIL_REASON+='LIB_DEPENDS is deprecated and must be replaced with DEPENDS.'
.endif

.if defined(PKG_PATH)
PKG_FAIL_REASON+='Please unset PKG_PATH before doing pkgsrc work!'
.endif

.if defined(MASTER_SITE_SUBDIR)
PKG_FAIL_REASON+='MASTER_SITE_SUBDIR is deprecated and must be replaced with MASTER_SITES.'
.endif

.if defined(PATCH_SITE_SUBDIR)
PKG_FAIL_REASON+='PATCH_SITE_SUBDIR is deprecated and must be replaced with PATCH_SITES.'
.endif

.if defined(ONLY_FOR_ARCHS) || defined(NOT_FOR_ARCHS) \
	|| defined(ONLY_FOR_OPSYS) || defined(NOT_FOR_OPSYS)
PKG_FAIL_REASON+='ONLY/NOT_FOR_ARCHS/OPSYS are deprecated and must be replaced with ONLY/NOT_FOR_PLATFORM.'
.endif

.if (${PKGSRC_LOCKTYPE} == "sleep" || ${PKGSRC_LOCKTYPE} == "once")
.  if !defined(OBJHOSTNAME)
PKG_FAIL_REASON+='PKGSRC_LOCKTYPE needs OBJHOSTNAME defined.'
.  elif !exists(${SHLOCK})
PKG_FAIL_REASON+='The ${SHLOCK} utility does not exist, and is necessary for locking.'
PKG_FAIL_REASON+='Please "${MAKE} install" in ../../pkgtools/shlock.'
.  endif
.endif

#
# Many ways to disable a package.
#
# Ignore packages that can't be resold if building for a CDROM.
#
# Don't build a package if it's restricted and we don't want to
# get into that.
#
# Don't build any package that utilizes strong cryptography, for
# when the law of the land forbids it.
#
# Don't attempt to build packages against X if we don't have X.
#
# Don't build a package if it's broken.
#

.if (defined(NO_BIN_ON_CDROM) && defined(FOR_CDROM))
PKG_FAIL_REASON+= "${PKGNAME} may not be placed in binary form on a CDROM:" \
         "    "${NO_BIN_ON_CDROM:Q}
.endif
.if (defined(NO_SRC_ON_CDROM) && defined(FOR_CDROM))
PKG_FAIL_REASON+= "${PKGNAME} may not be placed in source form on a CDROM:" \
         "    "${NO_SRC_ON_CDROM:Q}
.endif
.if (defined(RESTRICTED) && defined(NO_RESTRICTED))
PKG_FAIL_REASON+= "${PKGNAME} is restricted:" \
	 "    "${RESTRICTED:Q}
.endif
.if !(${MKCRYPTO} == "YES" || ${MKCRYPTO} == yes)
.  if defined(CRYPTO)
PKG_FAIL_REASON+= "${PKGNAME} may not be built, because it utilizes strong cryptography"
.  endif
.endif
.if defined(USE_X11) && !exists(${X11BASE})
PKG_FAIL_REASON+= "${PKGNAME} uses X11, but ${X11BASE} not found"
.endif
.if defined(BROKEN)
PKG_FAIL_REASON+= "${PKGNAME} is marked as broken:" ${BROKEN:Q}
.endif

.if defined(LICENSE)
.  ifdef ACCEPTABLE_LICENSES
.    for _lic in ${ACCEPTABLE_LICENSES}
.      if ${LICENSE} == "${_lic}"
_ACCEPTABLE=	yes
.      endif	# LICENSE == _lic
.    endfor	# _lic
.  endif	# ACCEPTABLE_LICENSES
.  ifndef _ACCEPTABLE
PKG_FAIL_REASON+= "${PKGNAME} has an unacceptable license: ${LICENSE}." \
	 "    To view the license, enter \"${MAKE} show-license\"." \
	 "    To indicate acceptance, add this line to your /etc/mk.conf:" \
	 "    ACCEPTABLE_LICENSES+=${LICENSE}"
.  endif	# _ACCEPTABLE
.endif		# LICENSE

# Define __PLATFORM_OK only if the OS matches the pkg's allowed list.
.if defined(ONLY_FOR_PLATFORM) && !empty(ONLY_FOR_PLATFORM)
.  for __tmp__ in ${ONLY_FOR_PLATFORM}
.    if ${MACHINE_PLATFORM:M${__tmp__}} != ""
__PLATFORM_OK?=	yes
.    endif	# MACHINE_PLATFORM
.  endfor	# __tmp__
.else		# !ONLY_FOR_PLATFORM
__PLATFORM_OK?=	yes
.endif		# ONLY_FOR_PLATFORM
.for __tmp__ in ${NOT_FOR_PLATFORM}
.  if ${MACHINE_PLATFORM:M${__tmp__}} != ""
.    undef __PLATFORM_OK
.  endif	# MACHINE_PLATFORM
.endfor		# __tmp__
.if !defined(__PLATFORM_OK)
PKG_SKIP_REASON+= "${PKGNAME} is not available for ${MACHINE_PLATFORM}"
.endif		# !__PLATFORM_OK

.if !defined(NO_SKIP)
.  if defined(PKG_FAIL_REASON) || defined(PKG_SKIP_REASON)
_PKG_SKIPPED=	# defined
.  endif
.endif

############################################################################
# Set up build environment
############################################################################

.if !defined(_PKG_SKIPPED)

# Allow variables to be set on a per-OS basis
OPSYSVARS+=	CFLAGS CPPFLAGS CXXFLAGS FFLAGS LDFLAGS LIBS
.  for var in ${OPSYSVARS:O}
.    if defined(${var}.${OPSYS})
${var}+=	${${var}.${OPSYS}}
.    elif defined(${var}.*)
${var}+=	${${var}.*}
.    endif
.  endfor

CPPFLAGS+=	${CPP_PRECOMP_FLAGS}

.if !empty(USE_BUILDLINK3:M[nN][oO])
LDFLAGS+=	${COMPILER_RPATH_FLAG}${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

ALL_ENV+=	CC=${CC:Q}
ALL_ENV+=	CFLAGS=${CFLAGS:Q}
ALL_ENV+=	CPPFLAGS=${CPPFLAGS:Q}
ALL_ENV+=	CXX=${CXX:Q}
ALL_ENV+=	CXXFLAGS=${CXXFLAGS:Q}
ALL_ENV+=	COMPILER_RPATH_FLAG=${COMPILER_RPATH_FLAG:Q}
ALL_ENV+=	F77=${F77:Q}
ALL_ENV+=	FC=${FC:Q}
ALL_ENV+=	FFLAGS=${FFLAGS:Q}
ALL_ENV+=	LDFLAGS=${LDFLAGS:Q}
ALL_ENV+=	LINKER_RPATH_FLAG=${LINKER_RPATH_FLAG:Q}
ALL_ENV+=	PATH=${PATH:Q}:${LOCALBASE}/bin:${X11BASE}/bin
ALL_ENV+=	PREFIX=${PREFIX}

MAKE_ENV+=	${ALL_ENV}
MAKE_ENV+=	${NO_EXPORT_CPP:D:UCPP=${CPP:Q}}
MAKE_ENV+=	LINK_ALL_LIBGCC_HACK=${LINK_ALL_LIBGCC_HACK:Q}
MAKE_ENV+=	LOCALBASE=${LOCALBASE}
MAKE_ENV+=	NO_WHOLE_ARCHIVE_FLAG=${NO_WHOLE_ARCHIVE_FLAG:Q}
MAKE_ENV+=	WHOLE_ARCHIVE_FLAG=${WHOLE_ARCHIVE_FLAG:Q}
MAKE_ENV+=	X11BASE=${X11BASE}
MAKE_ENV+=	X11PREFIX=${X11PREFIX}

# Constants to provide a consistent environment for packages using
# BSD-style Makefiles.
MAKE_ENV+=	MAKECONF=${PKGMAKECONF:U/dev/null}
MAKE_ENV+=	OBJECT_FMT=${OBJECT_FMT:Q}
MAKE_ENV+=	${USETOOLS:DUSETOOLS=${USETOOLS:Q}}

SCRIPTS_ENV+=	${ALL_ENV}
SCRIPTS_ENV+=	_PKGSRCDIR=${_PKGSRCDIR}
SCRIPTS_ENV+=	${BATCH:DBATCH=yes}
SCRIPTS_ENV+=	CURDIR=${.CURDIR}
SCRIPTS_ENV+=	DEPENDS=${DEPENDS:Q}
SCRIPTS_ENV+=	DISTDIR=${DISTDIR}
SCRIPTS_ENV+=	FILESDIR=${FILESDIR}
SCRIPTS_ENV+=	LOCALBASE=${LOCALBASE}
SCRIPTS_ENV+=	PATCHDIR=${PATCHDIR}
SCRIPTS_ENV+=	PKGSRCDIR=${PKGSRCDIR}
SCRIPTS_ENV+=	SCRIPTDIR=${SCRIPTDIR}
SCRIPTS_ENV+=	VIEWBASE=${VIEWBASE}
SCRIPTS_ENV+=	WRKDIR=${WRKDIR}
SCRIPTS_ENV+=	WRKSRC=${WRKSRC}
SCRIPTS_ENV+=	X11BASE=${X11BASE}

# Set PLIST_SUBST to substitute "${variable}" to "value" in PLIST
PLIST_SUBST+=	CHGRP=${CHGRP:Q}
PLIST_SUBST+=	CHMOD=${CHMOD:Q}
PLIST_SUBST+=	CHOWN=${CHOWN:Q}
PLIST_SUBST+=	LN=${LN:Q}
PLIST_SUBST+=	LOCALBASE=${LOCALBASE}
PLIST_SUBST+=	LOWER_VENDOR=${LOWER_VENDOR}
PLIST_SUBST+=	LOWER_OPSYS=${LOWER_OPSYS}
PLIST_SUBST+=	LOWER_OS_VERSION=${LOWER_OS_VERSION}
PLIST_SUBST+=	MACHINE_ARCH=${MACHINE_ARCH}
PLIST_SUBST+=	MACHINE_GNU_ARCH=${MACHINE_GNU_ARCH}
PLIST_SUBST+=	MACHINE_GNU_PLATFORM=${MACHINE_GNU_PLATFORM}
PLIST_SUBST+=	MKDIR=${MKDIR:Q}
PLIST_SUBST+=	OPSYS=${OPSYS}
PLIST_SUBST+=	OS_VERSION=${OS_VERSION}
PLIST_SUBST+=	PKGBASE=${PKGBASE}
PLIST_SUBST+=	PKGNAME=${PKGNAME_NOREV}
PLIST_SUBST+=	PKGLOCALEDIR=${PKGLOCALEDIR}
PLIST_SUBST+=	PKGVERSION=${PKGVERSION:C/nb[0-9]*$//}
PLIST_SUBST+=	QMAILDIR=${QMAILDIR} # XXXTV is this used?
PLIST_SUBST+=	RM=${RM:Q}
PLIST_SUBST+=	RMDIR=${RMDIR:Q}
PLIST_SUBST+=	SVR4_PKGNAME=${SVR4_PKGNAME}
PLIST_SUBST+=	TRUE=${TRUE:Q}
PLIST_SUBST+=	VIEWBASE=${VIEWBASE}
PLIST_SUBST+=	X11BASE=${X11BASE}
PLIST_SUBST+=	X11PREFIX=${X11PREFIX}

# Automatically increase process limit where necessary for building.
.  if defined(UNLIMIT_RESOURCES)
.    for res in ${UNLIMIT_RESOURCES}
_ULIMIT_CMD+=	${ULIMIT_CMD_${res}:D${ULIMIT_CMD_${res}} ; }
.    endfor
.  endif

# if automatic manual page compression is done by the package according
# to MANZ's value, set MANCOMPRESSED if MANZ is set
.  if defined(MANCOMPRESSED_IF_MANZ) && defined(MANZ)
MANCOMPRESSED=	yes
MAKE_ENV+=	MANZ=${MANZ}
.  endif

# CONF_DEPENDS notes a dependency where the config directory for the
# package matches the dependency's config directory.  CONF_DEPENDS is
# only meaningful if ${PKG_INSTALLATION_TYPE} == "pkgviews".
#
CONF_DEPENDS?=		# empty
.  if !empty(CONF_DEPENDS)
USE_PKGINSTALL=		YES
.  endif

.endif	# !_PKG_SKIPPED

############################################################################
# Debug support
############################################################################

# Debugging levels for this file, dependent on PKG_DEBUG_LEVEL definition
# 0 == normal, default, quiet operation
# 1 == all shell commands echoed before invocation
# 2 == shell "set -x" operation
PKG_DEBUG_LEVEL?=	0
_PKG_SILENT=		@
_PKG_DEBUG=		# empty
_PKG_DEBUG_SCRIPT=	# empty

.if ${PKG_DEBUG_LEVEL} > 0
_PKG_SILENT=		# empty
.endif

.if ${PKG_DEBUG_LEVEL} > 1
_PKG_DEBUG=		set -x;
_PKG_DEBUG_SCRIPT=	${SH} -x
.endif

############################################################################
# External tools
############################################################################

# top part not skipped by _PKG_SKIPPED

# Used to print all the '===>' style prompts - override this to turn them off.
ECHO_MSG?=		${ECHO}

# Define SMART_MESSAGES in /etc/mk.conf for messages giving the tree
# of dependencies for building, and the current target.
.ifdef SMART_MESSAGES
_PKGSRC_IN?=		===> ${.TARGET} [${PKGNAME}${_PKGSRC_DEPS}] ===
.endif
_PKGSRC_IN?=		===

DO_NADA?=		${TRUE} # deprecated; for compatibility only
SHCOMMENT?=		${ECHO_MSG} >/dev/null '***'
TOUCH_FLAGS?=		-f

FETCH_BEFORE_ARGS+=	${PASSIVE_FETCH:D-p}

.if !defined(_PKG_SKIPPED)

INSTALL_DATA?= 		${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE}
INSTALL_DATA_DIR?= 	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${PKGDIRMODE}
INSTALL_GAME?=		${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${GAMEOWN} -g ${GAMEGRP} -m ${GAMEMODE}
INSTALL_GAME_DATA?= 	${INSTALL} ${COPY} -o ${GAMEOWN} -g ${GAMEGRP} -m ${GAMEDATAMODE}
INSTALL_LIB?= 		${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_LIB_DIR?= 	${INSTALL_PROGRAM_DIR}
INSTALL_MAN?= 		${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m ${MANMODE}
INSTALL_MAN_DIR?= 	${INSTALL} -d -o ${MANOWN} -g ${MANGRP} -m ${PKGDIRMODE}
INSTALL_PROGRAM?= 	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_PROGRAM_DIR?= 	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${PKGDIRMODE}
INSTALL_SCRIPT?= 	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_SCRIPT_DIR?= 	${INSTALL_PROGRAM_DIR}

_INSTALL_MACROS=	BSD_INSTALL=${INSTALL:Q}
.  for mac in DATA GAME LIB MAN PROGRAM SCRIPT
_INSTALL_MACROS+=	BSD_INSTALL_${mac}=${INSTALL_${mac}:Q}
_INSTALL_MACROS+=	BSD_INSTALL_${mac}_DIR=${INSTALL_${mac}_DIR:Q}
CONFIGURE_ENV+=		INSTALL_${mac}=${INSTALL_${mac}:Q}
CONFIGURE_ENV+=		INSTALL_${mac}_DIR=${INSTALL_${mac}_DIR:Q}
.  endfor
MAKE_ENV+=		${_INSTALL_MACROS}
SCRIPTS_ENV+=		${_INSTALL_MACROS}

.  if defined(USE_GNU_TOOLS) && !empty(USE_GNU_TOOLS:Mmake)
MAKE_PROGRAM=		${GMAKE}
.  elif defined(USE_IMAKE)
.    if ${_IMAKE_MAKE} == ${GMAKE}
USE_GNU_TOOLS+=		make
.    endif
MAKE_PROGRAM=		${_IMAKE_MAKE}
.  endif
MAKE_PROGRAM?=		${MAKE}

MTREE_ARGS?=		-U -f ${MTREE_FILE} -d -e -p
MTREE_FILE?=		${PKGSRCDIR}/mk/${OPSYS}.pkg.dist

PKG_ARGS_COMMON=	-v -c -${COMMENT:Q}" " -d ${DESCR} -f ${PLIST}
PKG_ARGS_COMMON+=	-l -b ${BUILD_VERSION_FILE} -B ${BUILD_INFO_FILE}
PKG_ARGS_COMMON+=	-s ${SIZE_PKG_FILE} -S ${SIZE_ALL_FILE}
PKG_ARGS_COMMON+=	-P "`${MAKE} ${MAKEFLAGS} run-depends-list | ${SORT} -u`"
PKG_ARGS_COMMON+=	${INSTALL_FILE:D-i ${INSTALL_FILE}}
PKG_ARGS_COMMON+=	${DEINSTALL_FILE:D-k ${DEINSTALL_FILE}}
PKG_ARGS_COMMON+=	${MESSAGE:D-D ${MESSAGE}}
PKG_ARGS_COMMON+=	${NO_MTREE:D:U-m ${MTREE_FILE}}
PKG_ARGS_COMMON+=	${PKG_PRESERVE:D-n ${PRESERVE_FILE}}
.  if ${PKG_INSTALLATION_TYPE} == "overwrite"
PKG_ARGS_COMMON+=	${CONFLICTS:D-C "${CONFLICTS}"}
.  endif

PKG_ARGS_INSTALL=	-p ${PREFIX} ${PKG_ARGS_COMMON}
PKG_ARGS_BINPKG=	-p ${PREFIX:S/^${DESTDIR}//} -L ${PREFIX} ${PKG_ARGS_COMMON}

.endif	# !_PKG_SKIPPED

############################################################################
# External bsd.pkg.mk fragments needing to perform overrides
############################################################################

.if !defined(_PKG_SKIPPED)

USE_PKGINSTALL?=	NO
.  if !empty(USE_PKGINSTALL:M[yY][eE][sS])
.    include "../../mk/bsd.pkg.install.mk"
.  endif

.endif	# !_PKG_SKIPPED

############################################################################
# Transform package Makefile variables (overridable by external fragments)
############################################################################

.if !defined(_PKG_SKIPPED)

# Set INSTALL_FILE to be the name of any INSTALL file
.  if !defined(INSTALL_FILE) && exists(${PKGDIR}/INSTALL)
INSTALL_FILE=		${PKGDIR}/INSTALL
.  endif

# Set DEINSTALL_FILE to be the name of any DEINSTALL file
.  if !defined(DEINSTALL_FILE) && exists(${PKGDIR}/DEINSTALL)
DEINSTALL_FILE=		${PKGDIR}/DEINSTALL
.  endif

# If MESSAGE hasn't been defined, then set MESSAGE_SRC to be a space-separated
# list of files to be concatenated together to generate the MESSAGE file.
#
.  if !defined(MESSAGE_SRC) && !defined(MESSAGE)
.    if exists(${PKGDIR}/MESSAGE)
MESSAGE_SRC=		${PKGDIR}/MESSAGE
.    else
.      if exists(${PKGDIR}/MESSAGE.common)
MESSAGE_SRC=		${PKGDIR}/MESSAGE.common
.      endif
.      if exists(${PKGDIR}/MESSAGE.${OPSYS})
MESSAGE_SRC+=		${PKGDIR}/MESSAGE.${OPSYS}
.      endif
.      if exists(${PKGDIR}/MESSAGE.${MACHINE_ARCH:C/i[3-6]86/i386/g})
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.${MACHINE_ARCH:C/i[3-6]86/i386/g}
.      endif
.      if exists(${PKGDIR}/MESSAGE.${OPSYS}-${MACHINE_ARCH:C/i[3-6]86/i386/g})
MESSAGE_SRC+=	${PKGDIR}/MESSAGE.${OPSYS}-${MACHINE_ARCH:C/i[3-6]86/i386/g}
.      endif
.    endif
.  endif

.  if defined(MESSAGE_SRC)
MESSAGE=		${WRKDIR}/.MESSAGE

# Set MESSAGE_SUBST to substitute "${variable}" to "value" in MESSAGE
MESSAGE_SUBST+=	LOCALBASE=${LOCALBASE}
MESSAGE_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=	PKGNAME=${PKGNAME}
MESSAGE_SUBST+=	PREFIX=${PREFIX}
MESSAGE_SUBST+=	QMAILDIR=${QMAILDIR} # XXXTV is this used?
MESSAGE_SUBST+=	ROOT_GROUP=${ROOT_GROUP}
MESSAGE_SUBST+=	ROOT_USER=${ROOT_USER}
MESSAGE_SUBST+=	VIEWBASE=${VIEWBASE}
MESSAGE_SUBST+=	X11BASE=${X11BASE}
MESSAGE_SUBST+=	X11PREFIX=${X11PREFIX}

MESSAGE_SUBST_SED=	${MESSAGE_SUBST:S/=/}!/:S/$/!g/:S/^/ -e s!\\\${/}
.  endif

##### Config file related settings - see doc/guide

PKG_SYSCONFVAR?=	${PKGBASE}
PKG_SYSCONFSUBDIR?=	# empty
.  if ${PKG_INSTALLATION_TYPE} == "overwrite"
PKG_SYSCONFDEPOTBASE=	# empty
PKG_SYSCONFBASEDIR=	${PKG_SYSCONFBASE}
.  else
.    if !empty(PKG_SYSCONFBASE:M${PREFIX}) || \
        !empty(PKG_SYSCONFBASE:M${PREFIX}/*)
PKG_SYSCONFDEPOTBASE=	# empty
PKG_SYSCONFBASEDIR=	${PKG_SYSCONFBASE}
.      if !empty(CONF_DEPENDS)
_PLIST_IGNORE_FILES+=	${PKG_SYSCONFDIR:S,^${PREFIX}/,,}
.      endif
.    else
PKG_SYSCONFDEPOTBASE=	${PKG_SYSCONFBASE}/${DEPOT_SUBDIR}
PKG_SYSCONFBASEDIR=	${PKG_SYSCONFDEPOTBASE}/${PKGNAME}
.    endif
.  endif
.  if empty(PKG_SYSCONFSUBDIR)
DFLT_PKG_SYSCONFDIR:=	${PKG_SYSCONFBASEDIR}
.  else
DFLT_PKG_SYSCONFDIR:=	${PKG_SYSCONFBASEDIR}/${PKG_SYSCONFSUBDIR}
.  endif
PKG_SYSCONFDIR=		${DFLT_PKG_SYSCONFDIR}
.  if defined(PKG_SYSCONFDIR.${PKG_SYSCONFVAR})
PKG_SYSCONFDIR=		${PKG_SYSCONFDIR.${PKG_SYSCONFVAR}}
PKG_SYSCONFBASEDIR=	${PKG_SYSCONFDIR.${PKG_SYSCONFVAR}}
PKG_SYSCONFDEPOTBASE=	# empty
.  endif

ALL_ENV+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
BUILD_DEFS_FIXED+=	PKG_SYSCONFBASEDIR PKG_SYSCONFDIR

.endif	# !_PKG_SKIPPED

##### Checksum and other file handling support
# not skipped by _PKG_SKIPPED

ALLFILES?=	${DISTFILES} ${PATCHFILES}
CKSUMFILES?=	${ALLFILES}
.for __tmp__ in ${IGNOREFILES}
CKSUMFILES:=	${CKSUMFILES:N${__tmp__}}
.endfor

# List of all files, with ${DIST_SUBDIR} in front.  Used for fetch and checksum.
.if defined(DIST_SUBDIR)
.  if ${CKSUMFILES} != ""
_CKSUMFILES?=	${CKSUMFILES:S/^/${DIST_SUBDIR}\//}
.  endif
.  if !empty(DISTFILES)
_DISTFILES?=	${DISTFILES:S/^/${DIST_SUBDIR}\//}
.  else
_DISTFILES?=	# empty
.  endif
.  if defined(IGNOREFILES) && !empty(IGNOREFILES)
_IGNOREFILES?=	${IGNOREFILES:S/^/${DIST_SUBDIR}\//}
.  endif
.  if defined(PATCHFILES) && !empty(PATCHFILES)
_PATCHFILES?=	${PATCHFILES:S/^/${DIST_SUBDIR}\//}
.  else
_PATCHFILES?=	# empty
.  endif
.else
_CKSUMFILES?=	${CKSUMFILES}
_DISTFILES?=	${DISTFILES}
_IGNOREFILES?=	${IGNOREFILES}
_PATCHFILES?=	${PATCHFILES}
.endif
_ALLFILES?=	${_DISTFILES} ${_PATCHFILES}

############################################################################
# Phase `fetch'
############################################################################

.if !empty(PKG_PHASES:Mfetch) && !defined(_PKG_SKIPPED)

##### Master site selection

.  include "../../mk/bsd.sites.mk"

.  if defined(DIST_SUBDIR)
_MASTER_SITE_BACKUP:=	${MASTER_SITE_BACKUP:=${DIST_SUBDIR}/}
.    if defined(MASTER_SITE_OVERRIDE)
_MASTER_SITE_OVERRIDE:=	${MASTER_SITE_OVERRIDE:=${DIST_SUBDIR}/}
.    endif # MASTER_SITE_OVERRIDE
.  else  # !DIST_SUBDIR
_MASTER_SITE_BACKUP:=	${MASTER_SITE_BACKUP}
.    if defined(MASTER_SITE_OVERRIDE)
_MASTER_SITE_OVERRIDE:= ${MASTER_SITE_OVERRIDE}
.    endif # MASTER_SITE_OVERRIDE
.  endif # DIST_SUBDIR

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?=	${MASTER_SITE_BACKUP:=LOCAL_PORTS/}

##### Make subtargets for "fetch".

#===> check-vulnerable:  Check for any vulnerabilities in the package
_CHECK_VULNERABLE=							\
	${SETENV} PKGNAME="${PKGNAME}"					\
		  PKGBASE="${PKGBASE}"					\
		${AWK} '/^$$/ { next }					\
			/^\#.*/ { next }				\
			$$1 !~ ENVIRON["PKGBASE"] { next }		\
			{ s = sprintf("${PKG_ADMIN} pmatch \"%s\" %s && ${ECHO} \"*** WARNING - %s vulnerability in %s - see %s for more information ***\"", $$1, ENVIRON["PKGNAME"], $$2, ENVIRON["PKGNAME"], $$3); system(s); } \
		' < ${PKGVULNDIR}/pkg-vulnerabilities || ${ECHO} 'could not check pkg-vulnerabilities file'

_REAL_TARGETS.fetch+=		check-vulnerable
.PHONY: check-vulnerable
check-vulnerable:
.  if !defined(ALLOW_VULNERABLE_PACKAGES) && !exists(${extract_COOKIE})
.    if exists(${PKGVULNDIR}/pkg-vulnerabilities)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "${_PKGSRC_IN}> Checking for vulnerabilities in ${PKGNAME}"; \
	vul=`${_CHECK_VULNERABLE}`;					\
	case "$$vul" in							\
	"")	;;							\
	*)	${ECHO} "$$vul";					\
		${ECHO} "or define ALLOW_VULNERABLE_PACKAGES if this package is absolutely essential"; \
		${FALSE} ;;						\
	esac
.    else
	@${ECHO_MSG} "${_PKGSRC_IN}> *** No ${PKGVULNDIR}/pkg-vulnerabilities file found,"
	@${ECHO_MSG} "${_PKGSRC_IN}> *** skipping vulnerability checks. To fix, install"
	@${ECHO_MSG} "${_PKGSRC_IN}> *** the pkgsrc/security/audit-packages package and run"
	@${ECHO_MSG} "${_PKGSRC_IN}> *** '${LOCALBASE}/sbin/download-vulnerability-list'."
.    endif
.  endif

#===> "pre-fetch"

_REAL_TARGETS.fetch+=		pre-fetch
.PHONY: pre-fetch
pre-fetch: .OPTIONAL

#===> "do-fetch"

_REAL_TARGETS.fetch+=		do-fetch
.PHONY: do-fetch
#do-fetch:

#===> "post-fetch"

_REAL_TARGETS.fetch+=		post-fetch
.PHONY: post-fetch
post-fetch: .OPTIONAL

.endif	# !empty(PKG_PHASES:Mfetch) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `checksum'
############################################################################

# not skipped by _PKG_SKIPPED

#===> uptodate-digest:  Install "digest" if needed.
# this is also used by `patch' and `make*sum'
.PHONY: uptodate-digest
uptodate-digest:
.if !empty(USE_DIGEST:M[yY][eE][sS])
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -f ${DISTINFO_FILE} -a \( ! -f ${DIGEST} -o ${DIGEST_VERSION} -lt ${DIGEST_REQD} \) ]; then \
		{ cd ${PKGSRCDIR}/pkgtools/digest;			\
		${MAKE} clean;						\
		if [ -f ${DIGEST} ]; then				\
			${MAKE} ${MAKEFLAGS} deinstall;			\
		fi;							\
		${MAKE} ${MAKEFLAGS} test;				\
		if [ -f ${DIGEST} ]; then				\
			${MAKE} ${MAKEFLAGS} deinstall;			\
		fi;							\
		${MAKE} ${MAKEFLAGS} ${DEPENDS_TARGET};			\
		${MAKE} ${MAKEFLAGS} clean; } 				\
	fi
.endif

.if !empty(PKG_PHASES:Mchecksum) && !defined(_PKG_SKIPPED)

#===> do-checksum

_REAL_TARGETS.checksum+=	do-checksum
.PHONY: do-checksum
do-checksum: .OPTIONAL
.  if !defined(NO_CHECKSUM) && !exists(${extract_COOKIE})
do-checksum: uptodate-digest
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${DISTINFO_FILE} ]; then				\
		${ECHO_MSG} "=> No checksum file.";			\
	else								\
		(cd ${DISTDIR}; OK="true";				\
		  for file in "" ${_CKSUMFILES}; do			\
		  	if [ "X$$file" = X"" ]; then continue; fi; 	\
			alg=`${AWK} 'NF == 4 && $$2 == "('$$file')" && $$3 == "=" {print $$1;}' ${DISTINFO_FILE}`; \
			if [ "X$$alg" = "X" ]; then			\
				${ECHO_MSG} "=> No checksum recorded for $$file."; \
				OK="false";				\
			else						\
				CKSUM=`${DIGEST} $$alg < $$file`;	\
				CKSUM2=`${AWK} '$$1 == "'$$alg'" && $$2 == "('$$file')"{print $$4;}' ${DISTINFO_FILE}`; \
				if [ "$$CKSUM2" = "IGNORE" ]; then	\
					${ECHO_MSG} "=> Checksum for $$file is set to IGNORE in checksum file even though"; \
					${ECHO_MSG} "   the file is not in the "'$$'"{IGNOREFILES} list."; \
					OK="false";			\
				elif [ "$$CKSUM" = "$$CKSUM2" ]; then	\
					${ECHO_MSG} "=> Checksum OK for $$file."; \
				else					\
					${ECHO_MSG} "=> Checksum mismatch for $$file."; \
					OK="false";			\
				fi;					\
			fi;						\
		  done;							\
		  for file in "" ${_IGNOREFILES}; do			\
		  	if [ "X$$file" = X"" ]; then continue; fi; 	\
			CKSUM2=`${AWK} 'NF == 4 && $$3 == "=" && $$2 == "('$$file')"{print $$4;}' ${DISTINFO_FILE}`; \
			if [ "$$CKSUM2" = "" ]; then			\
				${ECHO_MSG} "=> No checksum recorded for $$file, file is in "'$$'"{IGNOREFILES} list."; \
				OK="false";				\
			elif [ "$$CKSUM2" != "IGNORE" ]; then		\
				${ECHO_MSG} "=> Checksum for $$file is not set to IGNORE in checksum file even though"; \
				${ECHO_MSG} "   the file is in the "'$$'"{IGNOREFILES} list."; \
				OK="false";				\
			fi;						\
		  done;							\
		  if [ "$$OK" != "true" ]; then				\
			${ECHO_MSG} "Make sure the Makefile and checksum file (${DISTINFO_FILE})"; \
			${ECHO_MSG} "are up to date.  If you want to override this check, type"; \
			${ECHO_MSG} "\"${MAKE} NO_CHECKSUM=yes [other args]\"."; \
			exit 1;						\
		  fi) ;							\
	fi
.  endif

.endif	# !empty(PKG_PHASES:Mchecksum) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `depends'
############################################################################

.if !empty(PKG_PHASES:Mdepends) && !defined(_PKG_SKIPPED)

.  if defined(RECOMMENDED)
.    if !empty(IGNORE_RECOMMENDED:M[nN][oO])
DEPENDS+=		${RECOMMENDED}
.    else
BUILD_DEFS_FIXED+=	IGNORE_RECOMMENDED
.    endif
.  endif

.  include "../../mk/tools.mk"

# If NO_BUILD is defined, default to not needing a compiler.
.  if defined(NO_BUILD)
USE_LANGUAGES?=		# empty
.  endif
.  include "../../mk/compiler.mk"

# USE_BUILDLINK3 == "no" implies NO_BUILDLINK
.  if !empty(USE_BUILDLINK3:M[nN][oO])
NO_BUILDLINK=		yes
.  endif
.  if !defined(NO_BUILDLINK)
.    include "../../mk/buildlink3/bsd.buildlink3.mk"
.  endif

##### "depends" target implementation

# Remove some redundant dependencies from the DEPENDS list.
.  include "../../mk/reduce-depends.mk"

_REAL_TARGETS.depends+=		depends-message

#===> "do-depends"

_REAL_TARGETS.depends+=		do-depends
.PHONY: do-depends

.endif	# !empty(PKG_PHASES:Mdepends) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `extract'
############################################################################

.if !empty(PKG_PHASES:Mextract) && !defined(_PKG_SKIPPED)

_REAL_TARGETS.extract+=		extract-message

#===> "build-defs-message"
# if BUILD_DEFS is non-empty, show a notice the the builder

.  if !empty(PKGSRC_SHOW_BUILD_DEFS:M[yY][eE][sS])
_REAL_TARGETS.extract+=		build-defs-message
.PHONY: build-defs-message
build-defs-message:
.    if !empty(BUILD_DEFS)
	@${ECHO} "=========================================================================="
	@${ECHO} "The following variables will affect the build process of this package,"
	@${ECHO} "${PKGNAME}.  Their current value is shown below:"
	@${ECHO} ""
.      for var in ${BUILD_DEFS}
.        if !defined(${var})
	@${ECHO} "        * ${var} (not defined)"
.        elif defined(${var}) && empty(${var})
	@${ECHO} "        * ${var} (defined)"
.        else
	@${ECHO} "        * ${var} = ${${var}}"
.        endif
.      endfor
	@${ECHO} ""
	@${ECHO} "You may want to abort the process now with CTRL-C and change their value"
	@${ECHO} "before continuing.  Be sure to run \`${MAKE} clean' after"
	@${ECHO} "the changes."
	@${ECHO} "=========================================================================="
.    endif
.  endif

#===> "pre-extract"

_REAL_TARGETS.extract+=		pre-extract
.PHONY: pre-extract
pre-extract: .OPTIONAL

#===> "do-extract"

_REAL_TARGETS.extract+=		do-extract
.PHONY: do-extract
#do-extract:

#===> "post-extract"

_REAL_TARGETS.extract+=		post-extract
.PHONY: post-extract
post-extract: .OPTIONAL

.endif	# !empty(PKG_PHASES:Mextract) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `patch'
############################################################################

.if !empty(PKG_PHASES:Mpatch) && !defined(_PKG_SKIPPED)

# determine if we need a working patch(1).
.  if defined(PATCHFILES)
_NEED_PATCH=		YES
.  elif defined(_OPSYS_GPATCH_REQD) && !empty(_OPSYS_GPATCH_REQD:M[yY][eE][sS])
_NEED_PATCH=		YES
.  else
_NEED_PATCH!=		if [ -d ${PATCHDIR} ]; then \
				if [ "`${ECHO} ${PATCHDIR}/patch-*`" != "${PATCHDIR}/patch-*" ]; then \
					${ECHO} YES; \
				else \
					${ECHO} NO; \
				fi \
			else \
				${ECHO} NO; \
			fi
.  endif

.  if ${_NEED_PATCH} == "YES"
USE_GNU_TOOLS+=		patch
.  endif

.  if defined(PATCH_DEBUG) || defined(PKG_VERBOSE)
PATCH_DEBUG_TMP=	yes
.  endif
PATCH_DEBUG_TMP?=	no

PATCH_STRIP?=		-p0
.  if ${PATCH_DEBUG_TMP} == "yes"
PATCH_ARGS?=		-d ${WRKSRC} -E ${PATCH_STRIP}
.  endif
PATCH_ARGS?=		-d ${WRKSRC} --forward --quiet -E ${PATCH_STRIP}

PATCH_ARGS+=		${BATCH:D--batch}
.  if defined(_PATCH_CAN_BACKUP) && (${_PATCH_CAN_BACKUP} == "yes")
PATCH_ARGS+=		${_PATCH_BACKUP_ARG} .orig
.  endif
PATCH_FUZZ_FACTOR?=	-F0	# Default to zero fuzz

# The following variables control how "distribution" patches are extracted
# and applied to the package sources.
#
# PATCH_DIST_STRIP is a patch option that sets the pathname strip count.
# PATCH_DIST_ARGS is the list of arguments to pass to the patch command.
# PATCH_DIST_CAT is the command that outputs the patch to stdout.
#
# For each of these variables, there is a patch-specific variant that
# may be set, i.e. PATCH_DIST_STRIP.<patch>, PATCH_DIST_ARGS.<patch>,
# PATCH_DIST_CAT.<patch>.
#
PATCH_DIST_STRIP?=		-p0
.  for i in ${PATCHFILES}
PATCH_DIST_STRIP.${i:S/=/--/}?=	${PATCH_DIST_STRIP}
.    if defined(PATCH_DIST_ARGS)
PATCH_DIST_ARGS.${i:S/=/--/}?=	${PATCH_DIST_ARGS}
.    elif ${PATCH_DEBUG_TMP} == "yes"
PATCH_DIST_ARGS.${i:S/=/--/}?=	-d ${WRKSRC} -E ${PATCH_DIST_STRIP.${i:S/=/--/}}
.    else
PATCH_DIST_ARGS.${i:S/=/--/}?=	-d ${WRKSRC} --forward --quiet -E ${PATCH_DIST_STRIP.${i:S/=/--/}}
.    endif
.  endfor
.  if defined(BATCH)
PATCH_DIST_ARGS+=		--batch
.    for i in ${PATCHFILES}
PATCH_DIST_ARGS.${i:S/=/--/}+=	--batch
.    endfor
.  endif
.  if defined(_PATCH_CAN_BACKUP) && (${_PATCH_CAN_BACKUP} == "yes")
PATCH_DIST_ARGS+=		${_PATCH_BACKUP_ARG} .orig_dist
.    for i in ${PATCHFILES}
PATCH_DIST_ARGS.${i:S/=/--/}+=	${_PATCH_BACKUP_ARG} .orig_dist
.    endfor
.  endif
PATCH_DIST_CAT?=	{ case $$patchfile in				\
			  *.Z|*.gz) ${GZCAT} $$patchfile ;;		\
			  *.bz2)    ${BZCAT} $$patchfile ;;		\
			  *)	    ${CAT} $$patchfile ;;		\
			  esac; }
.  for i in ${PATCHFILES}
PATCH_DIST_CAT.${i:S/=/--/}?=	{ patchfile=${i}; ${PATCH_DIST_CAT}; }
.  endfor

.  if !empty(PKGSRC_SHOW_PATCH_ERRORMSG:M[yY][eE][sS])
PKGSRC_PATCH_FAIL=							\
if [ -n "${PKG_OPTIONS}" ] || [ -n "${_LOCALPATCHFILES}" ]; then	\
	${ECHO} "=========================================================================="; \
	${ECHO};							\
	${ECHO} "Some of the selected build options and/or local patches may be incompatible."; \
	${ECHO} "Please try building with fewer options or patches.";	\
	${ECHO};							\
	${ECHO} "=========================================================================="; \
fi; exit 1
.  endif
PKGSRC_PATCH_FAIL?=	exit 1

_REAL_TARGETS.patch+=	patch-message pre-patch do-patch post-patch

.endif	# !empty(PKG_PHASES:Mpatch) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `tools'
############################################################################

do-tools: .OPTIONAL
.if !empty(PKG_PHASES:Mtools) && !defined(_PKG_SKIPPED)

_REAL_TARGETS.tools+=	tools-message pre-tools do-tools post-tools

.endif	# !empty(PKG_PHASES:Mtools) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `wrapper'
############################################################################

do-wrapper: .OPTIONAL
.if !empty(PKG_PHASES:Mwrapper) && !defined(_PKG_SKIPPED)

.  include "../../mk/wrapper/bsd.wrapper.mk"

_REAL_TARGETS.wrapper+=	wrapper-message pre-wrapper do-wrapper post-wrapper

.endif	# !empty(PKG_PHASES:Mwrapper) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `configure'
############################################################################

.if !empty(PKG_PHASES:Mconfigure) && !defined(_PKG_SKIPPED)

CONFIGURE_ENV+=		${ALL_ENV}
CONFIGURE_ENV+=		ac_given_INSTALL="`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'` -c -o ${BINOWN} -g ${BINGRP}"
CONFIGURE_ENV+=		AWK=${AWK:Q}
CONFIGURE_ENV+=		INSTALL="`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'` -c -o ${BINOWN} -g ${BINGRP}"
CONFIGURE_ENV+=		MAKE=${MAKE_PROGRAM:T:Q}
CONFIGURE_ENV+=		M4=${M4:Q}
CONFIGURE_ENV+=		YACC=${YACC:Q}

.  if defined(GNU_CONFIGURE)
#
# If GNU_CONFIGURE is defined, then pass LIBS to the GNU configure script.
# also pass in a CONFIG_SHELL to avoid picking up bash
#
CONFIG_SHELL?=		${SH}
CONFIGURE_ENV+=		CONFIG_SHELL=${CONFIG_SHELL}
CONFIGURE_ENV+=		install_sh=${INSTALL:Q}
CONFIGURE_ENV+=		LIBS=${LIBS:Q}
CONFIGURE_ENV+=		${USE_LIBTOOL:Dlt_cv_sys_max_cmd_len=${_OPSYS_MAX_CMDLEN}}
#
# GNU_CONFIGURE_PREFIX is the argument to the --prefix option passed to the
# GNU configure script.
#
GNU_CONFIGURE_PREFIX?=	${PREFIX}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${GNU_CONFIGURE_PREFIX}
HAS_CONFIGURE=		yes
.    if defined(USE_X11)
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=        --x-libraries=${X11BASE}/lib${LIBABISUFFIX}
.    endif
CONFIGURE_HAS_INFODIR?=	yes
.    if !empty(INFO_FILES) && !empty(CONFIGURE_HAS_INFODIR:M[yY][eE][sS])
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${INFO_DIR}
.    endif
#
# By default, override config.guess and config.sub for GNU configure
# packages. pkgsrc's updated versions of these scripts allows GNU
# configure to recognise NetBSD ports such as shark.
#
CONFIG_GUESS_OVERRIDE?=		\
	config.guess */config.guess */*/config.guess
CONFIG_SUB_OVERRIDE?=		\
	config.sub */config.sub */*/config.sub
CONFIG_RPATH_OVERRIDE?=		# set by platform file as needed
#
# By default, override config.status for GNU configure packages.  We
# never want it to execute after the configure phase has ended as it
# might overwrite any post-configure changes we might have made to the
# generated files.
#
CONFIG_STATUS_OVERRIDE?=	\
	config.status */config.status */*/config.status
.  endif

_REAL_TARGETS.configure+=configure-message pre-configure pre-configure-override do-configure post-configure

.endif	# !empty(PKG_PHASES:Mconfigure) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `build'
############################################################################

.if !empty(PKG_PHASES:Mbuild) && !defined(_PKG_SKIPPED)

_REAL_TARGETS.build+=	build-message pre-build do-build post-build

.endif	# !empty(PKG_PHASES:Mbuild) && !defined(_PKG_SKIPPED)

############################################################################
# Phase `test'
############################################################################

.if !empty(PKG_PHASES:Mtest)

_REAL_TARGETS.test+=	test-message pre-test do-test post-test

.endif	# !empty(PKG_PHASES:Mtest)

############################################################################
# Phase `install'
############################################################################

.if !empty(PKG_PHASES:Minstall)

##### PLIST manipulation

.  include "../../mk/plist.mk"

##### Make subtargets for non-su portion of "install".

#===> "install-check-pkgname"

_REAL_TARGETS.install+=		install-check-pkgname
.PHONY: install-check-pkgname
install-check-pkgname:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extractname=`${CAT} ${extract_COOKIE}`;				\
	case "$$extractname" in						\
	"")	${ECHO_MSG} "*** Warning: ${WRKDIR} may contain an older version of ${PKGBASE}" ;; \
	"${PKGNAME}")	;;						\
	*)	${ECHO_MSG} "*** Warning: Package version $$extractname in ${WRKDIR}"; \
		${ECHO_MSG} "*** Current version ${PKGNAME} in pkgsrc directory"; \
		${ECHO_MSG} "*** Cleaning and rebuilding the newer version of the package..."; \
		${MAKE} clean && ${MAKE} build ;;			\
	esac

#===> "do-su-install"
# su to root, then run real-su-install

_REAL_TARGETS.install+=		do-su-install

##### Make subtargets for su portion of "install".

#===> "message"
# generate ${MESSAGE} from ${MESSAGE_SRC} by substituting
# for MESSAGE_SUBST entries

_REAL_TARGETS.su-install+=	message
.PHONY: message
message: ${MESSAGE}
.  if defined(MESSAGE)
${MESSAGE}: ${MESSAGE_SRC}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -z "${MESSAGE_SRC}" ]; then				\
		${ECHO} "${MESSAGE_SRC} not found.";			\
		${ECHO} "Please set MESSAGE_SRC correctly.";		\
	else								\
		${CAT} ${MESSAGE_SRC} |					\
			${SED} ${MESSAGE_SUBST_SED}			\
			> ${MESSAGE};					\
	fi
.  endif

#===> "init-install"
# check for conflicts and create install directories

_REAL_TARGETS.su-install+=	init-install
.PHONY: init-install
init-install:
.  if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER) &&	\
    (${PKG_INSTALLATION_TYPE} == "overwrite")
.    if defined(CONFLICTS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${WRKDIR}/.CONFLICTS
.      for conflict in ${CONFLICTS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_BEST_EXISTS} \"${conflict}\" || ${TRUE}`";	\
	if [ X"$$found" != X"" ]; then					\
		${ECHO} "$$found" >> ${WRKDIR}/.CONFLICTS;		\
	fi
.      endfor
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -s ${WRKDIR}/.CONFLICTS ]; then				\
		found=`${SED} -e s'|${_PKG_DBDIR}/||g' ${WRKDIR}/.CONFLICTS | tr '\012' ' '`; \
		${ECHO_MSG} "${_PKGSRC_IN}> ${PKGNAME} conflicts with installed package(s): $$found found."; \
		${ECHO_MSG} "*** They install the same files into the same place."; \
		${ECHO_MSG} "*** Please remove $$found first with pkg_delete(1)."; \
		${RM} -f ${WRKDIR}/.CONFLICTS;				\
		exit 1;							\
	fi
.    endif	# CONFLICTS
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_BEST_EXISTS} \"${PKGWILDCARD}\" || ${TRUE}`";	\
	if [ "$$found" != "" ]; then					\
		${ECHO_MSG} "${_PKGSRC_IN}> $$found is already installed - perhaps an older version?"; \
		${ECHO_MSG} "*** If so, you may use either of:"; \
		${ECHO_MSG} "***  - \"pkg_delete $$found\" and \"${MAKE} reinstall\" to upgrade properly"; \
		${ECHO_MSG} "***  - \"${MAKE} update\" to rebuild the package and all of its dependencies"; \
		${ECHO_MSG} "***  - \"${MAKE} replace\" to replace only the package without re-linking"; \
		${ECHO_MSG} "***    dependencies, risking various problems."; \
		exit 1;							\
	fi
.  endif # !NO_PKG_REGISTER && !NO_FORCE_REGISTER && overwrite
.  if ${PKG_INSTALLATION_TYPE} == "pkgviews"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_INFO} -e ${PKGNAME} || ${TRUE}`";			\
	if [ "$$found" != "" ]; then					\
		${ECHO_MSG} "${_PKGSRC_IN}>  $$found is already installed."; \
		exit 1;							\
	fi
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}if [ `${SH} -c umask` -ne ${DEF_UMASK} ]; then \
		${ECHO_MSG} "${_PKGSRC_IN}>  Warning: your umask is \"`${SH} -c umask`"\".; \
		${ECHO_MSG} "If this is not desired, set it to an appropriate value (${DEF_UMASK})"; \
		${ECHO_MSG} "and install this package again by \`\`${MAKE} deinstall reinstall''."; \
	fi
.  if defined(PKG_DEVELOPER) && (${CHECK_FILES} == "YES")
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG} "${_PKGSRC_IN}> Generating pre-install file lists"
	${_PKG_SILENT}${_PKG_DEBUG}${FIND} ${PREFIX} -type f -or -type l \
		2>/dev/null ${CHECK_FILES_SKIP_CMD} >${WRKDIR}/.prefix.pre \
		|| ${TRUE}
.    if ${CHECK_FILES_STRICT} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}${FIND} ${PKG_SYSCONFDIR} \
		2>/dev/null ${CHECK_FILES_SKIP_CMD} >${WRKDIR}/.sysconfdir.pre \
		|| ${TRUE}
	${_PKG_SILENT}${_PKG_DEBUG}${FIND} ${VARBASE} \
		2>/dev/null ${CHECK_FILES_SKIP_CMD} >${WRKDIR}/.varbase.pre \
		|| ${TRUE}
.    endif
.  endif
.  if defined(INSTALLATION_DIRS) && !empty(INSTALLATION_DIRS)
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG} "${_PKGSRC_IN}> Creating installation directories"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in ${INSTALLATION_DIRS}; do				\
		case $$dir in						\
		/*)	;;						\
		*bin|*bin/*|*libexec|*libexec/*)			\
			${INSTALL_PROGRAM_DIR} ${PREFIX}/$$dir ;;	\
		*man/*)							\
			${INSTALL_MAN_DIR} ${PREFIX}/$$dir ;;		\
		*)							\
			${INSTALL_DATA_DIR} ${PREFIX}/$$dir ;;		\
		esac;							\
	done
.  endif	# INSTALLATION_DIRS
.  if !defined(NO_MTREE)
	${_PKG_SILENT}${_PKG_DEBUG}if [ `${ID} -u` = `${ID} -u ${ROOT_USER}` ]; then		\
		if [ ! -f ${MTREE_FILE} ]; then				\
			${ECHO_MSG} "Error: mtree file \"${MTREE_FILE}\" is missing."; \
			exit 1;						\
		else							\
			if [ ! -d ${PREFIX} ]; then			\
				${MKDIR} ${PREFIX};			\
			fi;						\
			${MTREE} ${MTREE_ARGS} ${PREFIX}/;		\
		fi;							\
	else								\
		${ECHO_MSG} "Warning: not superuser, can't run mtree."; \
		${ECHO_MSG} "Become ${ROOT_USER} and try again to ensure correct permissions."; \
	fi
.  else
	${_PKG_SILENT}${_PKG_DEBUG}[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}
.  endif # !NO_MTREE

#===> "pre-install-script"

_REAL_TARGETS.su-install+=	pre-install-script
.PHONY: pre-install-script
pre-install-script: .OPTIONAL

#===> "pre-install"

_REAL_TARGETS.su-install+=	pre-install
.PHONY: pre-install
pre-install: .OPTIONAL

#===> "do-install"

_REAL_TARGETS.su-install+=	do-install
.PHONY: do-install
.if !target(do-install)
do-install:
.  for DIR in ${INSTALL_DIRS}
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${DIR} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}
.  endfor
.endif

#===> "post-install"

_REAL_TARGETS.su-install+=	post-install
.PHONY: post-install
post-install: .OPTIONAL

#===> "plist"
#
# PLIST must be generated at this late point (instead of
# depending on it somewhere earlier), because it needs
# to be created _after_ the {pre,do,post}-install
# targets are run.
#
# We generate _before_ post-install-script is run so
# that the real config files and rc.d scripts aren't
# listed in the PLIST.
#
_REAL_TARGETS.su-install+=	plist
.PHONY: plist
plist: ${PLIST}

#===> "post-install-check-files"

.if defined(PKG_DEVELOPER) && (${CHECK_FILES} == "YES")
_REAL_TARGETS.su-install+=	post-install-check-files
.PHONY: post-install-check-files
post-install-check-files:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG} "${_PKGSRC_IN}> Generating post-install file lists"
	${_PKG_SILENT}${_PKG_DEBUG}${FIND} ${PREFIX} -type f -or -type l \
		2>/dev/null ${CHECK_FILES_SKIP_CMD} >${WRKDIR}/.prefix.post \
		|| ${TRUE}
.  if ${CHECK_FILES_STRICT} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}${FIND} ${PKG_SYSCONFDIR} \
		2>/dev/null ${CHECK_FILES_SKIP_CMD} >${WRKDIR}/.sysconfdir.post\
		|| ${TRUE}
	${_PKG_SILENT}${_PKG_DEBUG}${FIND} ${VARBASE} \
		2>/dev/null ${CHECK_FILES_SKIP_CMD} >${WRKDIR}/.varbase.post \
		|| ${TRUE}
.  endif
.endif

#===> "post-install-script"

_REAL_TARGETS.su-install+=	post-install-script
.PHONY: post-install-script
post-install-script: .OPTIONAL

#===> "post-install-man"
# fixup manpages to match actual installed files

_REAL_TARGETS.su-install+=	post-install-man
.PHONY: post-install-man
post-install-man:
	${_PKG_SILENT}${_PKG_DEBUG}newmanpages=`${EGREP} -h		\
		'^([^@/]*/)*man/([^/]*/)?(man[1-9ln]/.*\.[1-9ln]|cat[1-9ln]/.*\.0)(\.gz)?$$' \
		${PLIST} 2>/dev/null || ${TRUE}`;			\
	if [ X"${MANCOMPRESSED}" != X"" -a X"${MANZ}" = X"" ]; then	\
		${ECHO_MSG} "${_PKGSRC_IN}> [Automatic manual page handling]";	\
		${ECHO_MSG} "${_PKGSRC_IN}> Decompressing manual pages for ${PKGNAME}";	\
		for manpage in $$newmanpages; do			\
			manpage=`${ECHO} $$manpage | ${SED} -e 's|\.gz$$||'`; \
			if [ -h ${PREFIX}/$$manpage.gz ]; then		\
				set - `${LS} -l ${PREFIX}/$$manpage.gz | ${SED} -e 's|\.gz$$||'`; \
				shift `expr $$# - 1`;			\
				${RM} -f ${PREFIX}/$$manpage;		\
				${LN} -s $${1} ${PREFIX}/$$manpage;	\
				${RM} ${PREFIX}/$$manpage.gz;		\
			else						\
				${GUNZIP_CMD} ${PREFIX}/$$manpage.gz;	\
			fi;						\
			if [ X"${PKG_VERBOSE}" != X"" ]; then		\
				${ECHO_MSG} "$$manpage";		\
			fi;						\
		done;							\
	fi;								\
	if [ X"${MANCOMPRESSED}" = X"" -a X"${MANZ}" != X"" ]; then	\
		${ECHO_MSG} "${_PKGSRC_IN}> [Automatic manual page handling]";	\
		${ECHO_MSG} "${_PKGSRC_IN}> Compressing manual pages for ${PKGNAME}"; \
		for manpage in $$newmanpages; do			\
			manpage=`${ECHO} $$manpage | ${SED} -e 's|\.gz$$||'`; \
			if [ -h ${PREFIX}/$$manpage ]; then		\
				set - `${LS} -l ${PREFIX}/$$manpage`;	\
				shift `expr $$# - 1`;			\
				${RM} -f ${PREFIX}/$$manpage.gz; 	\
				${LN} -s $${1}.gz ${PREFIX}/$$manpage.gz; \
				${RM} ${PREFIX}/$$manpage;		\
			else						\
				${GZIP_CMD} ${PREFIX}/$$manpage;	\
			fi;						\
			if [ X"${PKG_VERBOSE}" != X"" ]; then		\
				${ECHO_MSG} "$$manpage";		\
			fi;						\
		done;							\
	fi

#===> "post-install-shlib"

.  if ${_DO_SHLIB_CHECKS} == "yes"
.    if ${PKG_INSTALLATION_TYPE} == "overwrite"
_REAL_TARGETS.su-install+=	post-install-shlib
.PHONY: post-install-shlib
post-install-shlib:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${MAKE} ${MAKEFLAGS} do-shlib-handling SHLIB_PLIST_MODE=0
.    endif
.  endif

#===> "post-install-message"
# display MESSAGE, if specified

.  ifdef MESSAGE
_REAL_TARGETS.su-install+=	post-install-message
.PHONY: post-install-message
post-install-message:
	@${ECHO_MSG} "${_PKGSRC_IN}> Please note the following:"
	@${ECHO_MSG} ""
	@${CAT} ${MESSAGE}
	@${ECHO_MSG} ""
.    if !empty(PKGSRC_MESSAGE_RECIPIENTS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	(${ECHO} "The ${PKGNAME} package was installed on `${HOSTNAME_CMD}` at `date`"; \
	${ECHO} "";							\
	${ECHO} "Please note the following:";				\
	${ECHO} "";							\
	${CAT} ${MESSAGE};						\
	${ECHO} "") |							\
	${MAIL_CMD} -s"Package ${PKGNAME} installed on `${HOSTNAME_CMD}`" ${PKGSRC_MESSAGE_RECIPIENTS}
.    endif
.  endif

#===> "fake-pkg"

_REAL_TARGETS.su-install+=	fake-pkg

#===> "check-shlibs"

.  if defined(PKG_DEVELOPER) && (${CHECK_SHLIBS} == "YES")
_REAL_TARGETS.su-install+=	check-shlibs
.  endif

#===> "check-files"

.  if defined(PKG_DEVELOPER) && (${CHECK_FILES} == "YES")
_REAL_TARGETS.su-install+=	check-files
.  endif

.endif	# !empty(PKG_PHASES:Minstall)

############################################################################
# Special install phase `replace'
############################################################################

_REAL_TARGETS.replace+=	do-su-replace

_REAL_TARGETS.su-replace+=

_REAL_TARGETS.undo-replace+= do-su-undo-replace

############################################################################
# Phase `package'
############################################################################

.PHONY: descr
descr: ${DESCR}
${DESCR}: ${DESCR_SRC}
	@${CAT} ${DESCR_SRC} 	 >${DESCR}
.if defined(HOMEPAGE)
	@\
	${ECHO}			>>${DESCR} ; \
	${ECHO} "Homepage:"	>>${DESCR} ; \
	${ECHO} '${HOMEPAGE}'	>>${DESCR}	
.endif

_REAL_TARGETS.package+=	do-su-package

_REAL_TARGETS.su-package+=

############################################################################
# Variables calculated after all the above, and recursion support
############################################################################

# explicit "-f Makefile" here to work around problems with the MAKEFILE var
# and case-insensitive filesystems (see PR pkg/28392)
#
.for targ in ${_PKG_PHASES_ALL}
.PHONY: recurse-${targ}
recurse-${targ}:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${PKGDIR} && ${MAKE} -f Makefile ${targ}
.endfor

# convenience target, to display make variables from command line
# i.e. "make show-var VARNAME=var", will print var's value
.PHONY: show-var show-var-noeval
show-var show-var-noeval:
	@${ECHO} ${${VARNAME}:Q}

# enhanced version of target above, to display multiple variables
.PHONY: show-vars show-vars-noeval
show-vars show-vars-noeval:
.for VARNAME in ${VARNAMES}
	@${ECHO} ${${VARNAME}:Q}
.endfor

# Find out the PREFIX of dependencies where the PREFIX is needed at build time.
.if defined(EVAL_PREFIX)
.  for def in ${EVAL_PREFIX}
.    if !defined(${def:C/=.*$//})
${def:C/=.*$//}_DEFAULT?=${LOCALBASE}
_${def:C/=.*$//}_CMD=	${PKG_INFO} -qp ${def:C/^.*=//} 2>/dev/null | ${AWK} '{ print $$2; exit }' | grep '' || ${ECHO} ${${def:C/=.*$//}_DEFAULT}
${def:C/=.*$//}=	${_${def:C/=.*$//}_CMD:sh}
.    endif
.  endfor
.endif

PREPEND_PATH?=		# empty
.if !empty(PREPEND_PATH)
# This is very Special.  Because PREPEND_PATH is set with += in reverse order,
# the awk expression reverses the order again (since bootstrap bmake doesn't
# yet support the :[-1..1] construct).
_PATH_CMD=		${ECHO} `${ECHO} ${PREPEND_PATH:Q} | ${AWK} '{for (i=NF;i>0;i--) print $$i}'`:${_PATH_ORIG} | ${TR} ' ' :
PATH=			${_PATH_CMD:sh} # DOES NOT use :=, to defer evaluation
.endif

############################################################################
# User-visible make targets
############################################################################

# Catch-all targets.
# Without anything specified, assume "all".  Also allow "dependall" to be
# specified for those in the habit of using that in NetBSD main source.
# Recurses to ensure that .if make() conditionals work as expected.

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
# only invoke "test" if requested; makes SMART_MESSAGES look nicer
_PKG_ALL_TARGET=	test
.endif

.PHONY: all dependall
.MAIN: all
all dependall: recurse-${_PKG_ALL_TARGET:Ubuild}

# Depend is generally meaningless for arbitrary packages, but if someone wants
# one they can override this.  This is just to catch people who've gotten into
# the habit of typing `${MAKE} depend all install' as a matter of course.

.PHONY: depend
depend: .OPTIONAL

# Same goes for tags
.PHONY: tags
tags: .OPTIONAL

##### If this package will be skipped, use placebo targets.

.if defined(_PKG_SKIPPED)

.  for targ in ${_PKG_PHASES_ALL} \
		replace undo-replace \
		update
${targ}:
.    if !defined(SKIP_SILENT)
	@for str in ${PKG_FAIL_REASON} ${PKG_SKIP_REASON}; do		\
		${ECHO} "${_PKGSRC_IN}> $$str";				\
	done
.    endif
.    if defined(PKG_FAIL_REASON)
	@${FALSE}
.    endif
.  endfor

.else	# !defined(_PKG_SKIPPED)

##### Real targets.  These don't have any commands attached; they simply defer
##### to other implementation targets below.

.PHONY: ${_PKG_PHASES_ALL} replace undo-replace
fetch: real-fetch
checksum: fetch real-checksum
depends: checksum ${WRKDIR} acquire-depends-lock ${depends_COOKIE} release-depends-lock
extract: depends acquire-extract-lock ${extract_COOKIE} release-extract-lock
patch: extract acquire-patch-lock ${patch_COOKIE} release-patch-lock
tools: patch acquire-tools-lock ${tools_COOKIE} release-tools-lock
wrapper: tools acquire-wrapper-lock ${wrapper_COOKIE} release-wrapper-lock
configure: wrapper acquire-configure-lock ${configure_COOKIE} release-configure-lock
build: configure acquire-build-lock ${build_COOKIE} release-build-lock
test: build acquire-test-lock ${test_COOKIE} release-test-lock
install: test acquire-install-lock ${install_COOKIE} release-install-lock
package: install acquire-package-lock ${package_COOKIE} release-package-lock
replace: build real-replace
undo-replace: real-undo-replace

##### *_COOKIE to real-* layer for targets which use cookies.

.  for targ in ${_PKG_PHASES_WRKDIR}
${${targ}_COOKIE}: real-${targ}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f $@ && ${ECHO} ${PKGNAME} >$@
.  endfor

# mark a stage as complete if its cookie (and all parent cookies) exist
.  if exists(${depends_COOKIE})
${depends_COOKIE}: .MADE
.    if exists(${extract_COOKIE})
${extract_COOKIE}: .MADE
.      if exists(${patch_COOKIE})
${patch_COOKIE}: .MADE
.        if exists(${tools_COOKIE})
${tools_COOKIE}: .MADE
.          if exists(${wrapper_COOKIE})
${wrapper_COOKIE}: .MADE
.            if exists(${configure_COOKIE})
${configure_COOKIE}: .MADE
.              if exists(${build_COOKIE})
${build_COOKIE}: .MADE
.                if exists(${test_COOKIE})
${test_COOKIE}: .MADE
.                  if exists(${install_COOKIE})
${install_COOKIE}: .MADE
.                    if exists(${package_COOKIE})
${package_COOKIE}: .MADE
.                    endif
.                  endif
.                endif
.              endif
.            endif
.          endif
.        endif
.      endif
.    endif
.  endif

##### NO_* for skipping phases

.  if defined(NO_DEPENDS) || (empty(DEPENDS) && empty(BUILD_DEPENDS))
${depends_COOKIE}: .MADE
.  endif
.  if defined(NO_TOOLS)
${tools_COOKIE}: .MADE
.  endif
.  if defined(NO_WRAPPER)
${wrapper_COOKIE}: .MADE
.  endif
.  if defined(NO_CONFIGURE)
${configure_COOKIE}: .MADE
.  endif
.  if defined(NO_BUILD)
${build_COOKIE}: .MADE
.  endif
.  if empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
real-test: .MADE
.  endif
.  if defined(NO_INSTALL)
${install_COOKIE}: .MADE
.  endif

.  if defined(NO_PACKAGE) && !defined(FORCE_PACKAGE)
_REAL_TARGETS.package:=	no-package
no-package:
.    if !defined(SKIP_SILENT)
	@${ECHO_MSG} "${_PKGSRC_IN}> ${PKGNAME} may not be packaged: ${NO_PACKAGE}."
.    endif
.  endif

.  for targ in extract configure build install
.    if !empty(INTERACTIVE_STAGE:M${targ}) && defined(BATCH)
_REAL_TARGETS.${targ}:=	${targ}-is-interactive
${targ}-is-interactive:
	@${ECHO} "*** The ${targ} stage of this package requires user interaction"
	@${ECHO} "*** Please ${targ} manually with \"cd ${PKGDIR} && ${MAKE} ${targ}\""
	@${FALSE}
.    endif
.  endfor

##### User-visible messages for most targets

_PHASE_MSG.depends=	Verifying dependencies
_PHASE_MSG.extract=	Extracting
_PHASE_MSG.patch=	Patching
_PHASE_MSG.tools=	Overriding tools
_PHASE_MSG.wrapper=	Creating toolchain wrappers
_PHASE_MSG.configure=	Configuring
_PHASE_MSG.build=	Building
_PHASE_MSG.test=	Testing
_PHASE_MSG.install=	Installing
_PHASE_MSG.package=	Packaging

.  for targ in ${_PKG_PHASES_WRKDIR}
.PHONY: ${targ}-message
${targ}-message:
	@${ECHO_MSG} "${_PKGSRC_IN}> ${_PHASE_MSG.${targ}} for ${PKGNAME}"
.  endfor

##### real-* to actual component target layer

# Simple dependencies are not used, deliberately, so that it is possible
# to invoke a single subtarget by hand while working on a new package.
#
# Please note that the order of the targets in _REAL_TARGETS.<phase> is
# important, and should not be modified (.ORDER is not recognized by
# make(1) in a serial make; i.e., without "-j n").

.  for targ in ${_PKG_PHASES_ALL} replace undo-replace su-install
.PHONY: real-${targ}
.ORDER: ${_REAL_TARGETS.${targ}}
real-${targ}: ${_REAL_TARGETS.${targ}}
.  endfor

.endif	# !defined(_PKG_SKIPPED)

##### su target support

.for targ in install package replace undo-replace deinstall
.PHONY: do-su-${targ}
do-su-${targ}:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ `${ID} -u` = `${ID} -u ${ROOT_USER}` ]; then		\
		${MAKE} ${MAKEFLAGS} $$realtarget;			\
	elif [ "X${BATCH}" != X"" ]; then				\
		${ECHO_MSG} "Warning: Batch mode, not superuser, can't run $$action for ${PKGNAME}."; \
		${ECHO_MSG} "Become ${ROOT_USER} and try again to ensure correct permissions."; \
	else								\
		args="DEINSTALLDEPENDS=${DEINSTALLDEPENDS}";		\
		if [ "X${FORCE_PKG_REGISTER}" != X"" ]; then		\
			args="$$args FORCE_PKG_REGISTER=1";		\
		fi;							\
		if [ "X${PKG_DEBUG_LEVEL}" != X"" ]; then		\
			args="$$args PKG_DEBUG_LEVEL=${PKG_DEBUG_LEVEL}"; \
		fi;							\
		if [ "X${PRE_ROOT_CMD}" != "X${TRUE}" ]; then		\
			${ECHO} "*** WARNING *** Running: ${PRE_ROOT_CMD}"; \
			${PRE_ROOT_CMD};				\
		fi;                                             	\
		${ECHO_MSG} "${_PKGSRC_IN}> Becoming ${ROOT_USER}@`${HOSTNAME_CMD}` to ${targ} ${PKGBASE}."; \
		${ECHO_N} "`${ECHO} ${SU_CMD} | ${AWK} '{ print $$1 }'` ";\
		${SU_CMD} "cd ${.CURDIR}; ${SETENV} PATH=$${PATH}:${SU_CMD_PATH_APPEND} ${MAKE} $$args ${MAKEFLAGS} real-su-${targ} $$realflags"; \
	fi
.endfor

############################################################################
# Package maintenance targets
############################################################################

# Checksumming utilities

.PHONY: makesum
makesum: recurse-fetch uptodate-digest
	${_PKG_SILENT}${_PKG_DEBUG}					\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if [ -f ${DISTINFO_FILE} ]; then				\
		${GREP} '^.NetBSD' ${DISTINFO_FILE} > $$newfile ||	\
			(${ECHO_N} "$$" > $$newfile &&			\
			 ${ECHO_N} "NetBSD" >> $$newfile && 		\
			 ${ECHO} "$$" >> $$newfile)			\
	else								\
		${ECHO_N} "$$" > $$newfile;				\
		${ECHO_N} "NetBSD" >> $$newfile; 			\
		${ECHO} "$$" >> $$newfile;				\
	fi;								\
	${ECHO} "" >> $$newfile;					\
	cd ${DISTDIR};							\
	for sumfile in "" ${_CKSUMFILES}; do				\
		if [ "X$$sumfile" = "X" ]; then continue; fi;		\
		${DIGEST} ${DIGEST_ALGORITHM} $$sumfile >> $$newfile;	\
		${WC} -c $$sumfile | ${AWK} '{ print "Size (" $$2 ") = " $$1 " bytes" }' >> $$newfile; \
	done;								\
	for ignore in "" ${_IGNOREFILES}; do				\
		if [ "X$$ignore" = "X" ]; then continue; fi;		\
		${ECHO} "${DIGEST_ALGORITHM} ($$ignore) = IGNORE" >> $$newfile; \
	done;								\
	if [ -f ${DISTINFO_FILE} ]; then				\
		${AWK} '$$2 ~ /\(patch-[a-z0-9]+\)/ { print $$0 }' < ${DISTINFO_FILE} >> $$newfile; \
	fi;								\
	if ${CMP} -s $$newfile ${DISTINFO_FILE}; then			\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: distfiles part unchanged.";	\
	else								\
		${MV} $$newfile ${DISTINFO_FILE};			\
	fi

.PHONY: makepatchsum mps
makepatchsum mps: uptodate-digest
	${_PKG_SILENT}${_PKG_DEBUG}					\
	newfile=${DISTINFO_FILE}.$$$$;					\
	if [ -f ${DISTINFO_FILE} ]; then				\
		${AWK} '$$2 !~ /\(patch-[a-z0-9]+\)/ { print $$0 }' < ${DISTINFO_FILE} >> $$newfile; \
	else \
		${ECHO_N} "$$" > $$newfile;				\
		${ECHO_N} "NetBSD" >> $$newfile; 			\
		${ECHO} "$$" >> $$newfile;				\
		${ECHO} "" >> $$newfile;				\
	fi;								\
	if [ -d ${PATCHDIR} ]; then					\
		(cd ${PATCHDIR};					\
		for sumfile in "" patch-*; do				\
			if [ "X$$sumfile" = "X" ]; then continue; fi;	\
			if [ "X$$sumfile" = "Xpatch-*" ]; then break; fi; \
			case $$sumfile in				\
				patch-local-*) ;;			\
				*.orig|*.rej|*~) continue ;;		\
				*)	${ECHO} "${DIGEST_ALGORITHM} ($$sumfile) = `${SED} -e '/\$$NetBSD.*/d' $$sumfile | ${DIGEST} ${DIGEST_ALGORITHM}`" >> $$newfile;; \
			esac;						\
		done);							\
	fi;								\
	if ${CMP} -s $$newfile ${DISTINFO_FILE}; then			\
		${RM} -f $$newfile;					\
		${ECHO_MSG} "=> distinfo: patches part unchanged.";	\
	else								\
		${MV} $$newfile ${DISTINFO_FILE};			\
	fi

makedistinfo mdi distinfo: makesum makepatchsum

############################################################################
# XXXTV CUT
############################################################################

UPDATE_RUNNING?=	NO

#
# _RESUME_TRANSFER:
#
# Macro to resume a previous transfer, needs to have defined
# the following options in mk.conf:
#
# PKG_RESUME_TRANSFERS
# FETCH_RESUME_ARGS (if FETCH_CMD != default)
# FETCH_OUTPUT_ARGS (if FETCH_CMD != default)
#
# For example if you want to use wget (pkgsrc/net/wget):
#
# FETCH_CMD=wget
# FETCH_RESUME_ARGS=-c
# FETCH_OUTPUT_ARGS=-O
#
# How does it work?
#
# FETCH_CMD downloads the file and saves it temporally into $$bfile.temp
# if the checksum match the correct one, $$bfile.temp is renamed to
# the original name.
#

_RESUME_TRANSFER=							\
	tsize=`${AWK} '/^Size/ && $$2 == '"\"($$file)\""' { print $$4 }' ${DISTINFO_FILE}` || ${TRUE}; \
	if [ ! -f "${DISTDIR}/${DIST_SUBDIR}/$$bfile.temp" ]; then	\
		${CP} ${DISTDIR}/${DIST_SUBDIR}/$$bfile ${DISTDIR}/${DIST_SUBDIR}/$$bfile.temp; \
	fi;								\
	dsize=`${WC} -c < ${DISTDIR}/${DIST_SUBDIR}/$$bfile.temp`;	\
	if [ "$$dsize" -eq "$$tsize" -a -f "${DISTDIR}/${DIST_SUBDIR}/$$bfile.temp" ]; then \
		${MV} ${DISTDIR}/${DIST_SUBDIR}/$$bfile.temp ${DISTDIR}/${DIST_SUBDIR}/$$bfile;	\
	fi;								\
	case "$$tsize" in						\
	"")	${ECHO_MSG} "No size in distinfo file (${DISTINFO_FILE})"; \
		break ;;						\
	esac;								\
	if [ -n "$$ftp_proxy" -o -n "$$http_proxy" ]; then		\
		${ECHO_MSG} "===> Resume is not supported by ftp(1) using http/ftp proxies.";	\
		break;							\
	else								\
		if [ "$$dsize" -lt "$$tsize" ]; then			\
			if [ "${FETCH_CMD:T}" != "ftp" -a -z "${FETCH_RESUME_ARGS}" ]; then \
				${ECHO_MSG} "=> Resume transfers are not supported, FETCH_RESUME_ARGS is empty."; \
				break;					\
			else						\
				for res_site in $$sites; do		\
					if [ -z "${FETCH_OUTPUT_ARGS}" ]; then \
						${ECHO_MSG} "=> FETCH_OUTPUT_ARGS has to be defined."; \
						break;			\
					fi;				\
					${ECHO_MSG} "=> $$bfile not completed, resuming:"; \
					${ECHO_MSG} "=> Downloaded: $$dsize Total: $$tsize."; \
					${ECHO_MSG};			\
					cd ${_DISTDIR};			\
					${FETCH_CMD} ${FETCH_BEFORE_ARGS} ${FETCH_RESUME_ARGS} \
						${FETCH_OUTPUT_ARGS} $${bfile}.temp $${res_site}$${bfile}; \
					if [ $$? -eq 0 ]; then		\
						ndsize=`${WC} -c < ${DISTDIR}/${DIST_SUBDIR}/$$bfile.temp`; \
						if [ "$$tsize" -eq "$$ndsize" ]; then \
							${MV} ${DISTDIR}/${DIST_SUBDIR}/$$bfile.temp ${DISTDIR}/${DIST_SUBDIR}/$$bfile; \
						fi;			\
						break;			\
					fi;				\
				done;					\
			fi;						\
		elif [ "$$dsize" -gt "$$tsize" ]; then			\
			${ECHO_MSG} "==> Downloaded file larger than the recorded size."; \
			break;						\
		fi;							\
	fi

#
# Define the elementary fetch macros.
#
_FETCH_FILE=								\
	if [ ! -f $$file -a ! -f $$bfile -a ! -h $$bfile ]; then	\
		${ECHO_MSG} "=> $$bfile doesn't seem to exist on this system."; \
		if [ ! -w ${_DISTDIR}/. ]; then 			\
			${ECHO_MSG} "=> Can't download to ${_DISTDIR} (permission denied?)."; \
			exit 1; 					\
		fi; 							\
		for site in $$sites; do					\
			${ECHO_MSG} "=> Attempting to fetch $$bfile from $${site}."; \
			if [ -f ${DISTINFO_FILE} ]; then		\
				${AWK} 'NF == 5 && $$1 == "Size" && $$2 == "('$$bfile')" { printf("=> [%s %s]\n", $$4, $$5) }' ${DISTINFO_FILE}; \
			fi;						\
			if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${bfile} ${FETCH_AFTER_ARGS}; then \
				if [ -n "${FAILOVER_FETCH}" -a -f ${DISTINFO_FILE} -a -f ${_DISTDIR}/$$bfile ]; then \
					alg=`${AWK} 'NF == 4 && $$2 == "('$$file')" && $$3 == "=" {print $$1;}' ${DISTINFO_FILE}`; \
					if [ -z "$$alg" ]; then		\
						alg=${DIGEST_ALGORITHM};\
					fi;				\
					CKSUM=`${DIGEST} $$alg < ${_DISTDIR}/$$bfile`; \
					CKSUM2=`${AWK} '$$1 == "'$$alg'" && $$2 == "('$$file')" {print $$4;}' <${DISTINFO_FILE}`; \
					if [ "$$CKSUM" = "$$CKSUM2" -o "$$CKSUM2" = "IGNORE" ]; then \
						break;			\
					else				\
						${ECHO_MSG} "=> Checksum failure - trying next site."; \
					fi;				\
				elif [ ! -f ${_DISTDIR}/$$bfile ]; then \
					${ECHO_MSG} "=> FTP didn't fetch expected file, trying next site." ; \
				else					\
					break;				\
				fi;					\
			fi						\
		done;							\
		if [ ! -f ${_DISTDIR}/$$bfile ]; then			\
			${ECHO_MSG} "=> Couldn't fetch $$bfile - please try to retrieve this";\
			${ECHO_MSG} "=> file manually into ${_DISTDIR} and try again."; \
			exit 1;						\
		fi;							\
	fi

_CHECK_DIST_PATH=							\
	if [ "X${DIST_PATH}" != "X" ]; then				\
		for d in "" ${DIST_PATH:S/:/ /g}; do			\
			if [ "X$$d" = "X" -o "X$$d" = "X${DISTDIR}" ]; then continue; fi; \
			if [ -f $$d/${DIST_SUBDIR}/$$bfile ]; then	\
				${ECHO} "Using $$d/${DIST_SUBDIR}/$$bfile"; \
				${RM} -f $$bfile;			\
				${LN} -s $$d/${DIST_SUBDIR}/$$bfile $$bfile; \
				break;					\
			fi;						\
		done;							\
	fi

#
# Set up ORDERED_SITES to work out the exact list of sites for every file,
# using the dynamic sites script, or sorting according to the master site
# list or the patterns in MASTER_SORT or MASTER_SORT_REGEX as appropriate.
# No actual sorting is done until ORDERED_SITES is expanded.
#
.if defined(MASTER_SORT) || defined(MASTER_SORT_REGEX)
MASTER_SORT?=
MASTER_SORT_REGEX?=
MASTER_SORT_REGEX+= ${MASTER_SORT:S/./\\./g:C/.*/:\/\/[^\/]*&\//}

MASTER_SORT_AWK= BEGIN { RS = " "; ORS = " "; IGNORECASE = 1 ; gl = "${MASTER_SORT_REGEX:S/\\/\\\\/g}"; }
.  for srt in ${MASTER_SORT_REGEX}
MASTER_SORT_AWK+= /${srt:C/\//\\\//g}/ { good["${srt:S/\\/\\\\/g}"] = good["${srt:S/\\/\\\\/g}"] " " $$0 ; next; }
.  endfor
MASTER_SORT_AWK+= { rest = rest " " $$0; } END { n=split(gl, gla); for(i=1;i<=n;i++) { print good[gla[i]]; } print rest; }

SORT_SITES_CMD= ${ECHO} $$unsorted_sites | ${AWK} '${MASTER_SORT_AWK}'
ORDERED_SITES= ${_MASTER_SITE_OVERRIDE} `${SORT_SITES_CMD:S/\\/\\\\/g:C/"/\"/g}`
.else
ORDERED_SITES= ${_MASTER_SITE_OVERRIDE} $$unsorted_sites
.endif

#
# Associate each file to fetch with the correct site(s).
#
.if defined(DYNAMIC_MASTER_SITES)
.  for fetchfile in ${_ALLFILES}
SITES_${fetchfile:T:S/=/--/}?= `${SH} ${FILESDIR}/getsite.sh ${fetchfile:T}`
.  endfor
.endif
.if !empty(_DISTFILES)
.  for fetchfile in ${_DISTFILES}
SITES_${fetchfile:T:S/=/--/}?= ${MASTER_SITES}
.  endfor
.endif
.if !empty(_PATCHFILES)
.  for fetchfile in ${_PATCHFILES}
SITES_${fetchfile:T:S/=/--/}?= ${PATCH_SITES}
.  endfor
.endif

# This code is only called in a batch case, to check for the presence of
# the distfiles
.PHONY: batch-check-distfiles
batch-check-distfiles:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	gotfiles=yes;							\
	for file in "" ${_ALLFILES}; do					\
		case "$$file" in					\
		"")	continue ;;					\
		*)	if [ ! -f ${DISTDIR}/$$file ]; then		\
				gotfiles=no;				\
			fi ;;						\
		esac;							\
	done;								\
	case "$$gotfiles" in						\
	no)	${ECHO} "*** This package requires user intervention to download the distfiles"; \
		${ECHO} "*** Please fetch the distfiles manually and place them in"; \
		${ECHO} "*** ${DISTDIR}";				\
		[ ! -z "${MASTER_SITES}" ] &&				\
			${ECHO} "*** The distfiles are available from ${MASTER_SITES}";	\
		[ ! -z "${HOMEPAGE}" ] && 				\
			${ECHO} "*** See ${HOMEPAGE} for more details";	\
		${ECHO};						\
		${FALSE} ;;						\
	esac

.PHONY: do-fetch
.if !target(do-fetch)
do-fetch:
.  if !empty(_ALLFILES)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${TEST} -d ${_DISTDIR} || ${MKDIR} ${_DISTDIR}
.    if ${INTERACTIVE_STAGE:Mfetch} == "fetch" && defined(BATCH)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${MAKE} ${MAKEFLAGS} batch-check-distfiles
.    else
.      for fetchfile in ${_ALLFILES}
.        if defined(_FETCH_MESSAGE)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	file="${fetchfile}";						\
	if [ ! -f ${DISTDIR}/$$file ]; then				\
		${_FETCH_MESSAGE};					\
	fi
.        else
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${_DISTDIR};							\
	file="${fetchfile}";						\
	bfile="${fetchfile:T}";						\
	unsorted_sites="${SITES_${fetchfile:T:S/=/--/}} ${_MASTER_SITE_BACKUP}"; \
	sites="${ORDERED_SITES}";					\
	${_CHECK_DIST_PATH};						\
	 if ${TEST} "${PKG_RESUME_TRANSFERS:M[Yy][Ee][Ss]}" ; then	\
	 	${_FETCH_FILE}; ${_RESUME_TRANSFER};			\
	 else								\
	 	${_FETCH_FILE};						\
	 fi
.        endif # defined(_FETCH_MESSAGE)
.      endfor
.    endif # INTERACTIVE_STAGE == fetch
.  endif # !empty(_ALLFILES)
.endif

# Extract

${WRKDIR}:
.if !defined(KEEP_WRKDIR)
.  if ${PKGSRC_LOCKTYPE} == "sleep" || ${PKGSRC_LOCKTYPE} == "once"
.    if !exists(${LOCKFILE})
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -rf ${WRKDIR}
.    endif
.  endif
.endif
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} ${WRKDIR}
.ifdef WRKOBJDIR
.  if ${PKGSRC_LOCKTYPE} == "sleep" || ${PKGSRC_LOCKTYPE} == "once"
.    if !exists(${LOCKFILE})
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${WRKDIR_BASENAME} || ${TRUE}
.    endif
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if ${LN} -s ${WRKDIR} ${WRKDIR_BASENAME} 2>/dev/null; then	\
		${ECHO} "${WRKDIR_BASENAME} -> ${WRKDIR}";		\
	fi
.endif # WRKOBJDIR

_EXTRACT_SUFFIXES=	.tar.gz .tgz .tar.bz2 .tbz .tar.Z .tar _tar.gz
_EXTRACT_SUFFIXES+=	.shar.gz .shar.bz2 .shar.Z .shar
_EXTRACT_SUFFIXES+=	.zip
_EXTRACT_SUFFIXES+=	.lha .lzh
_EXTRACT_SUFFIXES+=	.Z .bz2 .gz
_EXTRACT_SUFFIXES+=	.zoo
_EXTRACT_SUFFIXES+=	.bin
_EXTRACT_SUFFIXES+=	.rar

.if (defined(PATCHFILES) && !empty(PATCHFILES:M*.bz2)) || \
    !empty(EXTRACT_ONLY:M*.bz2) || !empty(EXTRACT_ONLY:M*.tbz) || \
    !empty(EXTRACT_SUFX:M*.bz2) || !empty(EXTRACT_SUFX:M*.tbz)
.  if exists(/usr/bin/bzcat)
BZCAT=			/usr/bin/bzcat <
.  else
BUILD_DEPENDS+=		bzip2>=0.9.0b:../../archivers/bzip2
BZCAT=			${LOCALBASE}/bin/bzcat
.  endif
.endif
.if !empty(EXTRACT_ONLY:M*.zip) || !empty(EXTRACT_SUFX:M*.zip)
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
.endif
.if !empty(EXTRACT_ONLY:M*.lzh) || !empty(EXTRACT_ONLY:M*.lha) || \
    !empty(EXTRACT_SUFX:M*.lzh) || !empty(EXTRACT_SUFX:M*.lha)
BUILD_DEPENDS+=		lha>=114.9:../../archivers/lha
.endif
.if !defined(GZCAT)
.  if (defined(PATCHFILES) && !empty(PATCHFILES:M*.gz)) || \
.     !empty(EXTRACT_ONLY:M*.gz) || !empty(EXTRACT_ONLY:M*.tgz) || \
      !empty(EXTRACT_SUFX:M*.gz) || !empty(EXTRACT_SUFX:M*.tgz)
BUILD_DEPENDS+=         gzip-base>=1.2.4b:../../archivers/gzip-base
GZCAT=                  ${LOCALBASE}/bin/zcat
.  endif
.endif
.if !empty(EXTRACT_ONLY:M*.zoo) || !empty(EXTRACT_SUFX:M*.zoo)
BUILD_DEPENDS+=		unzoo-[0-9]*:../../archivers/unzoo
.endif
.if !empty(EXTRACT_ONLY:M*.rar) || !empty(EXTRACT_SUFX:M*.rar)
BUILD_DEPENDS+=		unrar>=3.3.4:../../archivers/unrar
.endif

DECOMPRESS_CMD.tar.gz?=		${GZCAT}
DECOMPRESS_CMD.tgz?=		${DECOMPRESS_CMD.tar.gz}
DECOMPRESS_CMD.tar.bz2?=	${BZCAT}
DECOMPRESS_CMD.tbz?=		${DECOMPRESS_CMD.tar.bz2}
DECOMPRESS_CMD.tar.Z?=		${GZCAT}
DECOMPRESS_CMD.tar?=		${CAT}

DECOMPRESS_CMD.shar.gz?=	${GZCAT}
DECOMPRESS_CMD.shar.bz2?=	${BZCAT}
DECOMPRESS_CMD.shar.Z?=		${GZCAT}
DECOMPRESS_CMD.shar?=		${CAT}

DECOMPRESS_CMD.Z?=		${GZCAT}
DECOMPRESS_CMD.bz2?=		${BZCAT}
DECOMPRESS_CMD.gz?=		${GZCAT}

DECOMPRESS_CMD?=		${GZCAT}
.for __suffix__ in ${_EXTRACT_SUFFIXES}
.  if !defined(DECOMPRESS_CMD${__suffix__})
DECOMPRESS_CMD${__suffix__}?=	${DECOMPRESS_CMD}
.  endif
.endfor

# If this is empty, then everything gets extracted.
EXTRACT_ELEMENTS?=	# empty

DOWNLOADED_DISTFILE=	$${extract_file}

EXTRACT_CMD.zip?=	${LOCALBASE}/bin/unzip ${EXTRACT_CMD_OPTS.zip} $${extract_file}
EXTRACT_CMD_OPTS.zip?=	-Laqo
EXTRACT_CMD.lha?=	${LOCALBASE}/bin/lha ${EXTRACT_CMD_OPTS.lha} $${extract_file}
EXTRACT_CMD_OPTS.lha?=	xq
EXTRACT_CMD.lzh?=	${EXTRACT_CMD.lha}
EXTRACT_CMD_OPTS.lzh?=	${EXTRACT_CMD_OPTS.lha}
EXTRACT_CMD.zoo?=	${LOCALBASE}/bin/unzoo ${EXTRACT_CMD_OPTS.zoo} $${extract_file}
EXTRACT_CMD_OPTS.zoo?=	-x
EXTRACT_CMD.rar?=	${LOCALBASE}/bin/unrar ${EXTRACT_CMD_OPTS.rar} $${extract_file}
EXTRACT_CMD_OPTS.rar?=	x -inul
EXTRACT_ENV.bin?=	# empty
EXTRACT_CMD.bin?=	${ECHO} yes | ${SETENV} ${EXTRACT_ENV.bin} $${extract_file} ${EXTRACT_CMD_OPTS.bin} >/dev/null

.for __suffix__ in .gz .bz2 .Z
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} > `${BASENAME} $${extract_file} ${__suffix__}`
.endfor

.for __suffix__ in .shar.gz .shar.bz2 .shar.Z .shar
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${SH}
.endfor

# If EXTRACT_USING_PAX is defined, use pax in preference to (GNU) tar.
#
.if defined(EXTRACT_USING_PAX)
_DFLT_EXTRACT_CMD?=	${DECOMPRESS_CMD} $${extract_file} | ${PAX} -O -r ${EXTRACT_ELEMENTS}
.else
_DFLT_EXTRACT_CMD?=	${DECOMPRESS_CMD} $${extract_file} | ${GTAR} -xf - ${EXTRACT_ELEMENTS}
.endif

.for __suffix__ in ${_EXTRACT_SUFFIXES}
.  if !defined(EXTRACT_CMD${__suffix__})
.    if defined(EXTRACT_USING_PAX)
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${PAX} -O -r ${EXTRACT_ELEMENTS}
.  else
EXTRACT_CMD${__suffix__}?=	${DECOMPRESS_CMD${__suffix__}} $${extract_file} | ${GTAR} -xf - ${EXTRACT_ELEMENTS}
.    endif
.  endif
.endfor

# _SHELL_EXTRACT is a "subroutine" for extracting an archive.  It extracts
# the contents of archive named by the shell variable "extract_file" based
# on the file extension of the archive.
#
_SHELL_EXTRACT=		case $${extract_file} in
.for __suffix__ in ${_EXTRACT_SUFFIXES}
_SHELL_EXTRACT+=	*${__suffix__})	${EXTRACT_CMD${__suffix__}} ;;
.endfor
_SHELL_EXTRACT+=	*)		${_DFLT_EXTRACT_CMD} ;;
_SHELL_EXTRACT+=	esac

EXTRACT_CMD?=		${_SHELL_EXTRACT}

.PHONY: do-extract
.if !target(do-extract)
do-extract: ${WRKDIR}
.  for __file__ in ${EXTRACT_ONLY}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	extract_file="${_DISTDIR}/${__file__}";	export extract_file;	\
	cd ${WRKDIR}; ${EXTRACT_CMD}
.  endfor
.endif

# Patch

# LOCALPATCHES contains the location of local patches to packages
#	that are maintained in a directory tree reflecting the same
#	hierarchy as the pkgsrc tree, i.e. local patches for www/apache
#	would be found as ${LOCALPATCHES}/www/apache/*.
#
.if defined(LOCALPATCHES)
_DFLT_LOCALPATCHFILES=	${LOCALPATCHES}/${PKGPATH}/*
_LOCALPATCHFILES=	${_DFLT_LOCALPATCHFILES}
.endif

.PHONY: do-patch
.if !target(do-patch)
do-patch: uptodate-digest
.  if defined(PATCHFILES)
	@${ECHO_MSG} "${_PKGSRC_IN}> Applying distribution patches for ${PKGNAME}"
.    for i in ${PATCHFILES}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${_DISTDIR};			\
	if [ ${PATCH_DEBUG_TMP} = yes ]; then				\
		${ECHO_MSG} "${_PKGSRC_IN}> Applying distribution patch ${i}"; \
	fi;								\
	${PATCH_DIST_CAT.${i:S/=/--/}} |				\
	${PATCH} ${PATCH_DIST_ARGS.${i:S/=/--/}}			\
		|| { ${ECHO} "Patch ${i} failed"; ${PKGSRC_PATCH_FAIL}; }
.    endfor
.  endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	patchlist="";							\
	if [ -d ${PATCHDIR} ]; then					\
		if [ "`${ECHO} ${PATCHDIR}/patch-*`" = "${PATCHDIR}/patch-*" ]; then \
			${ECHO_MSG} "${_PKGSRC_IN}> Ignoring empty patch directory"; \
			if [ -d ${PATCHDIR}/CVS ]; then			\
				${ECHO_MSG} "${_PKGSRC_IN}> Perhaps you forgot the -P flag to 'cvs checkout' or 'cvs update'?"; \
			fi;						\
		else							\
			patchlist=`${ECHO} ${PATCHDIR}/patch-*`;	\
		fi;							\
	fi;								\
	if [ "X${_LOCALPATCHFILES}" = "X${_DFLT_LOCALPATCHFILES}" ]; then \
		localpatchfiles="`${ECHO} ${_LOCALPATCHFILES}`";	\
		if [ "$${localpatchfiles}" != "${_LOCALPATCHFILES}" ]; then \
			patchlist="$${patchlist} $${localpatchfiles}";	\
		fi;							\
	else								\
		patchlist=`${ECHO} $${patchlist} ${_LOCALPATCHFILES}`;	\
	fi;								\
	if [ -n "$${patchlist}" ]; then					\
		${ECHO_MSG} "${_PKGSRC_IN}> Applying pkgsrc patches for ${PKGNAME}" ; \
		fail="";						\
		for i in $${patchlist}; do				\
			if [ ! -f "$$i" ]; then				\
				${ECHO_MSG} "${_PKGSRC_IN}> $$i is not a valid patch file - skipping"; \
				continue; 				\
			fi;						\
			case $$i in					\
			*.orig|*.rej|*~)				\
				${ECHO_MSG} "${_PKGSRC_IN}> Ignoring patchfile $$i"; \
				continue;				\
				;;					\
			${PATCHDIR}/patch-local-*) 			\
				;;					\
			${PATCHDIR}/patch-*)	 			\
				if [ -f ${DISTINFO_FILE} ]; then	\
					filename=`expr $$i : '.*/\(.*\)'`; \
					algsum=`${AWK} 'NF == 4 && $$2 == "('$$filename')" && $$3 == "=" {print $$1 " " $$4}' ${DISTINFO_FILE} || ${TRUE}`; \
					if [ "X$$algsum" != "X" ]; then	\
						alg=`${ECHO} $$algsum | ${AWK} '{ print $$1 }'`; \
						recorded=`${ECHO} $$algsum | ${AWK} '{ print $$2 }'`; \
						calcsum=`${SED} -e '/\$$NetBSD.*/d' $$i | ${DIGEST} $$alg`; \
						if [ ${PATCH_DEBUG_TMP} = yes ]; then \
							${ECHO_MSG} "=> Verifying $$filename (using digest algorithm $$alg)"; \
						fi;			\
					fi;				\
					if [ "X$$algsum" = "X" -o "X$$recorded" = "X" ]; then \
						${ECHO_MSG} "**************************************"; \
						${ECHO_MSG} "Ignoring unknown patch file: $$i"; \
						${ECHO_MSG} "**************************************"; \
						continue;		\
					fi;				\
					if [ "X$$calcsum" != "X$$recorded" ]; then \
						${ECHO_MSG} "**************************************"; \
						${ECHO_MSG} "Patch file $$i has been modified"; \
						${ECHO_MSG} "**************************************"; \
						fail="$$fail $$filename"; \
						continue;		\
					fi;				\
				else					\
					${ECHO_MSG} "**************************************"; \
					${ECHO_MSG} "Ignoring unknown patch file: $$i"; \
					${ECHO_MSG} "**************************************"; \
					continue;			\
				fi;					\
				;;					\
			esac;						\
			if [ ${PATCH_DEBUG_TMP} = yes ]; then		\
				${ECHO_MSG} "${_PKGSRC_IN}> Applying pkgsrc patch $$i" ; \
			fi;						\
			fuzz="";					\
			${PATCH} -v > /dev/null 2>&1 && fuzz="${PATCH_FUZZ_FACTOR}"; \
			${PATCH} $$fuzz ${PATCH_ARGS} < $$i ||		\
				{ ${ECHO} Patch $$i failed ; ${PKGSRC_PATCH_FAIL}; }; \
		done;							\
		if [ "X$$fail" != "X" ]; then				\
			${ECHO_MSG} "Patching failed due to modified patch file(s): $$fail"; \
			${PKGSRC_PATCH_FAIL};				\
		fi;							\
	fi
.endif

# Configure

# _CONFIGURE_PREREQ is a list of targets to run after pre-configure but before
#	do-configure.  These targets typically edit the files used by the
#	do-configure target.  The targets are run as dependencies of
#	pre-configure-override.
#
# _CONFIGURE_POSTREQ is a list of targets to run after do-configure but before
#	post-configure.  These targets typically edit the files generated by
#	the do-configure target that are used during the build phase.

.if defined(USE_PKGLOCALEDIR)
_PKGLOCALEDIR=			${PREFIX}/${PKGLOCALEDIR}/locale
REPLACE_LOCALEDIR_PATTERNS?=	# empty
_REPLACE_LOCALEDIR_PATTERNS=	${REPLACE_LOCALEDIR_PATTERNS}
.  if defined(HAS_CONFIGURE) || defined(GNU_CONFIGURE)
_REPLACE_LOCALEDIR_PATTERNS+=	[Mm]akefile.in*
.  else
_REPLACE_LOCALEDIR_PATTERNS+=	[Mm]akefile*
.  endif
_REPLACE_LOCALEDIR_PATTERNS_FIND= \
	\( ${_REPLACE_LOCALEDIR_PATTERNS:S/$/!/:S/^/-o -name !/:S/!/"/g:S/-o//1} \)
REPLACE_LOCALEDIR?=		# empty
_REPLACE_LOCALEDIR=		\
	${REPLACE_LOCALEDIR}	\
	`${FIND} . ${_REPLACE_LOCALEDIR_PATTERNS_FIND} -print | ${SED} -e 's|^\./||' | ${GREP} -v '\.orig' | ${SORT} -u`

_CONFIGURE_PREREQ+=		subst-pkglocaledir
.  if empty(USE_PKGLOCALEDIR:M[nN][oO])
SUBST_CLASSES+=			pkglocaledir
.  endif
SUBST_MESSAGE.pkglocaledir=	"Fixing locale directory references."
SUBST_FILES.pkglocaledir=	${_REPLACE_LOCALEDIR}
SUBST_SED.pkglocaledir=		\
	-e 's|^\(localedir[ 	:]*=\).*|\1 ${_PKGLOCALEDIR}|'		\
	-e 's|^\(gnulocaledir[ 	:]*=\).*|\1 ${_PKGLOCALEDIR}|'		\
	-e 's|\(-DLOCALEDIR[ 	]*=\)[^ 	]*\(\.\*\)|\1"\\"${_PKGLOCALEDIR}\\""\2|'
.endif

.if defined(REPLACE_PERL)
REPLACE_INTERPRETER+=	perl
_REPLACE.perl.old=	.*/bin/perl
_REPLACE.perl.new=	${PERL5}
_REPLACE_FILES.perl=	${REPLACE_PERL}
.endif

.if defined(REPLACE_INTERPRETER)
_CONFIGURE_PREREQ+=	replace-interpreter
.PHONY: replace-interpreter
replace-interpreter:
.  for lang in ${REPLACE_INTERPRETER}
.    for pattern in ${_REPLACE_FILES.${lang}}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cd ${WRKSRC};							\
	for f in ${pattern}; do						\
	    if [ -f $${f} ]; then					\
		    ${SED} -e '1s|^#!${_REPLACE.${lang}.old}|#!${_REPLACE.${lang}.new}|' \
			    $${f} > $${f}.new;				\
		    if [ -x $${f} ]; then				\
			    ${CHMOD} a+x $${f}.new;			\
		    fi;							\
		    ${MV} -f $${f}.new $${f};				\
	    fi;								\
	done
.    endfor
.  endfor
.endif

.if defined(USE_LIBTOOL) && defined(LTCONFIG_OVERRIDE)
_CONFIGURE_PREREQ+=	do-ltconfig-override
.PHONY: do-ltconfig-override
do-ltconfig-override:
.  for ltconfig in ${LTCONFIG_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -f ${ltconfig} ]; then					\
		${RM} -f ${ltconfig};					\
		${ECHO} "${RM} -f libtool; ${LN} -s ${_LIBTOOL} libtool" \
			> ${ltconfig};					\
		${CHMOD} +x ${ltconfig};				\
	fi
.  endfor
.endif

_CONFIGURE_PREREQ+=	do-config-star-override
.PHONY: do-config-star-override
do-config-star-override:
.if defined(GNU_CONFIGURE)
.  if !empty(CONFIG_GUESS_OVERRIDE)
.    for _pattern_ in ${CONFIG_GUESS_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	for file in ${_pattern_}; do					\
		if [ -f "$$file" ]; then				\
			${RM} -f $$file;				\
			${LN} -s ${PKGSRCDIR}/mk/gnu-config/config.guess \
				$$file;					\
		fi;							\
	done
.    endfor
.  endif
.  if !empty(CONFIG_SUB_OVERRIDE)
.    for _pattern_ in ${CONFIG_SUB_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	for file in ${_pattern_}; do					\
		if [ -f "$$file" ]; then				\
			${RM} -f $$file;				\
			${LN} -s ${PKGSRCDIR}/mk/gnu-config/config.sub	\
				$$file;					\
		fi;							\
	done
.    endfor
.  endif
.  if !empty(CONFIG_RPATH_OVERRIDE)
.    for _pattern_ in ${CONFIG_RPATH_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	for file in ${_pattern_}; do					\
		if [ -f "$$file" ]; then				\
			${RM} -f $$file;				\
			${LN} -s ${PKGSRCDIR}/mk/gnu-config/config.rpath \
				$$file;					\
		fi;							\
	done
.    endfor
.  endif
.endif

PKGCONFIG_OVERRIDE_SED= \
	'/^Libs:.*[ 	]/s|-L\([ 	]*[^ 	]*\)|${COMPILER_RPATH_FLAG}\1 -L\1|g'
PKGCONFIG_OVERRIDE_STAGE?=	pre-configure

.if defined(PKGCONFIG_OVERRIDE) && !empty(PKGCONFIG_OVERRIDE)
.  if ${PKGCONFIG_OVERRIDE_STAGE} == "pre-configure"
_CONFIGURE_PREREQ+=		subst-pkgconfig
.  elif ${PKGCONFIG_OVERRIDE_STAGE} == "post-configure"
_CONFIGURE_POSTREQ+=		subst-pkgconfig
.  else
SUBST_STAGE.pkgconfig=		${PKGCONFIG_OVERRIDE_STAGE}
.  endif
SUBST_CLASSES+=			pkgconfig
SUBST_MESSAGE.pkgconfig=	"Adding rpaths to pkgconfig files."
SUBST_FILES.pkgconfig=		${PKGCONFIG_OVERRIDE:S/^${WRKSRC}\///}
SUBST_SED.pkgconfig=		${PKGCONFIG_OVERRIDE_SED}
.endif

# By adding this target, it makes sure the above PREREQ's work.
.PHONY: pre-configure-override
pre-configure-override: ${_CONFIGURE_PREREQ}

.PHONY: do-configure
.if !target(do-configure)
do-configure:
.  if defined(HAS_CONFIGURE)
.    for DIR in ${CONFIGURE_DIRS}
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${DIR} && ${SETENV} \
	    ${CONFIGURE_ENV} ${CONFIG_SHELL} \
	    ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
.    endfor
.  endif
.  if defined(USE_IMAKE)
.    for DIR in ${CONFIGURE_DIRS}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${DIR} && ${SETENV} ${SCRIPTS_ENV} XPROJECTROOT=${X11BASE} ${XMKMF}
.    endfor
.  endif
.endif

.if defined(USE_LIBTOOL) && \
    (defined(LIBTOOL_OVERRIDE) || defined(SHLIBTOOL_OVERRIDE))
_CONFIGURE_POSTREQ+=	do-libtool-override
.PHONY: do-libtool-override
do-libtool-override:
.  if defined(LIBTOOL_OVERRIDE)
.    for _pattern_ in ${LIBTOOL_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	for file in ${_pattern_}; do					\
		if [ -f "$$file" ]; then				\
			${RM} -f $$file;				\
			(${ECHO} '#!${CONFIG_SHELL}';			\
		 	 ${ECHO} 'exec ${_LIBTOOL} "$$@"';		\
			) > $$file;					\
			${CHMOD} +x $$file;				\
		fi;							\
	done
.    endfor
.  endif
.  if defined(SHLIBTOOL_OVERRIDE)
.    for _pattern_ in ${SHLIBTOOL_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	for file in ${_pattern_}; do					\
		if [ -f "$$file" ]; then				\
			${RM} -f $$file;				\
			(${ECHO} '#!${CONFIG_SHELL}';			\
		 	 ${ECHO} 'exec ${_SHLIBTOOL} "$$@"';		\
			) > $$file;					\
			${CHMOD} +x $$file;				\
		fi;							\
	done
.    endfor
.  endif
.endif

.if defined(CONFIG_STATUS_OVERRIDE)
_CONFIGURE_POSTREQ+=	do-config-status-override
.PHONY: do-config-status-override
do-config-status-override:
.  for _pattern_ in ${CONFIG_STATUS_OVERRIDE}
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC};			\
	for file in ${_pattern_}; do					\
		if [ -f "$$file" ]; then				\
			${MV} -f $$file $$file.overridden;		\
			${AWK} '/ *-recheck *\| *--recheck.*\)/ {	\
					print;				\
					print "    exit 0";		\
					next;				\
				}					\
				{ print }				\
			       ' $$file.overridden > $$file;		\
			${CHMOD} +x $$file;				\
		fi;							\
	done
.  endfor
.endif

.PHONY: post-configure
post-configure: ${_CONFIGURE_POSTREQ}

# Build

BUILD_DIRS?=		${WRKSRC}
BUILD_MAKE_FLAGS?=	${MAKE_FLAGS}

.PHONY: do-build
.if !target(do-build)
do-build:
.  for DIR in ${BUILD_DIRS}
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${DIR} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} -f ${MAKEFILE} ${BUILD_TARGET}
.  endfor
.endif

#Test

TEST_DIRS?=		${BUILD_DIRS}
TEST_ENV+=		${MAKE_ENV}
TEST_MAKE_FLAGS?=	${MAKE_FLAGS}

.PHONY: do-test
.if !target(do-test)
do-test:
.  if defined(TEST_TARGET) && !empty(TEST_TARGET)
.    for DIR in ${TEST_DIRS}
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${DIR} && ${SETENV} ${TEST_ENV} ${MAKE_PROGRAM} ${TEST_MAKE_FLAGS} -f ${MAKEFILE} ${TEST_TARGET}
.    endfor
.  endif
.endif

# Package

.PHONY: real-su-package
real-su-package: ${PLIST} ${DESCR}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "${_PKGSRC_IN}> Building binary package for ${PKGNAME}"; \
	if ${PKG_INFO} -qe ${PKGNAME}; then				\
		: The package is installed. ;				\
	else								\
		${ECHO_MSG} "=> ${PKGNAME} is not installed.";		\
		exit 1;							\
	fi;								\
	if [ ! -d ${PKGREPOSITORY} ]; then				\
		${MKDIR} ${PKGREPOSITORY};				\
		if [ $$? -ne 0 ]; then					\
			${ECHO_MSG} "=> Can't create directory ${PKGREPOSITORY}."; \
			exit 1;						\
		fi;							\
	fi;								\
	if ${PKG_CREATE} ${PKG_ARGS_BINPKG} ${PKGFILE}; then		\
		${MAKE} ${MAKEFLAGS} package-links;			\
	else								\
		${MAKE} ${MAKEFLAGS} delete-package;			\
		exit 1;							\
	fi
.if defined(NO_BIN_ON_CDROM)
	@${ECHO_MSG} "${_PKGSRC_IN}> Warning: ${PKGNAME} may not be put on a CD-ROM:"
	@${ECHO_MSG} "${_PKGSRC_IN}>         " ${NO_BIN_ON_CDROM:Q}
.endif
.if defined(NO_BIN_ON_FTP)
	@${ECHO_MSG} "${_PKGSRC_IN}> Warning: ${PKGNAME} may not be made available through FTP:"
	@${ECHO_MSG} "${_PKGSRC_IN}>         " ${NO_BIN_ON_FTP:Q}
.endif
.if defined(RECOMMENDED) && !empty(IGNORE_RECOMMENDED:M[yY][eE][sS])
	@${ECHO_MSG} "${_PKGSRC_IN}> Warning: dependency recommendations are being ignored!"
	@${ECHO_MSG} "${_PKGSRC_IN}>          ${PKGNAME} should not be uploaded nor"
	@${ECHO_MSG} "${_PKGSRC_IN}>          otherwise be used as a binary package!"
.endif

# Some support rules for real-su-package

.PHONY: package-links
package-links: delete-package-links
	${_PKG_SILENT}${_PKG_DEBUG}for cat in ${CATEGORIES}; do		\
		if [ ! -d ${PACKAGES}/$$cat ]; then			\
			${MKDIR} ${PACKAGES}/$$cat;			\
			if [ $$? -ne 0 ]; then				\
				${ECHO_MSG} "=> Can't create directory ${PACKAGES}/$$cat."; \
				exit 1;					\
			fi;						\
		fi;							\
		${RM} -f ${PACKAGES}/$$cat/${PKGNAME}${PKG_SUFX};	\
		${LN} -s ../${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PACKAGES}/$$cat; \
	done;

.PHONY: delete-package-links
delete-package-links:
	${_PKG_SILENT}${_PKG_DEBUG}\
	${FIND} ${PACKAGES} -type l -name ${PKGNAME}${PKG_SUFX} -print | ${XARGS} ${RM} -f

.PHONY: delete-package
delete-package: delete-package-links
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${PKGFILE}

# Check if all binaries and shlibs find their needed libs
# Must be run after "make install", so that files are installed, and
# ${PLIST} exists.
#
.PHONY: check-shlibs
check-shlibs:
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	bins=`${PKG_INFO} -qL ${PKGNAME} | { ${EGREP} -h '/(bin|sbin|libexec)/' || ${TRUE}; }`; \
	if [ "${OBJECT_FMT}" = "ELF" ]; then				\
		shlibs=`${PKG_INFO} -qL ${PKGNAME} | { ${EGREP} -h '/lib/lib.*.so' || ${TRUE}; }`; \
	elif [ "${OBJECT_FMT}" = "Mach-O" ]; then			\
		shlibs=`${PKG_INFO} -qL ${PKGNAME} | { ${EGREP} -h '/lib/lib.*.dylib' || ${TRUE}; }`; \
	else								\
		shlibs="";						\
	fi;								\
	if [ "X${LDD}" = X ]; then					\
		ldd=`${TYPE} ldd 2>/dev/null | ${AWK} '{ print $$NF }'`;\
	else								\
		ldd="${LDD}";						\
	fi;								\
	if [ -x "$$ldd" ]; then						\
		for i in $${bins} $${shlibs}; do			\
			err=`{ $$ldd $$i 2>&1 || ${TRUE}; } | { ${GREP} "not found" || ${TRUE}; }`; \
			if [ "${PKG_VERBOSE}" != "" ]; then		\
				${ECHO} "$$ldd $$i";			\
			fi;						\
			if [ "$$err" != "" ]; then			\
				${ECHO} "$$i: $$err";			\
				error=1;				\
			fi;						\
		done;							\
	fi;								\
	if [ "$$error" = 1 ]; then					\
		${ECHO} "*** The above programs/libs will not find the listed shared libraries"; \
		${ECHO} "    at runtime. Please fix the package (add -Wl,-R.../lib in the right places)!"; \
		${SHCOMMENT} Might not error-out for non-pkg-developers; \
		exit 1;							\
	fi
.endif # NO_PKG_REGISTER

# CHECK_FILES_SKIP is a list of file names that will be skipped when
# analyzing file lists in the check-files target.  This is useful to
# avoid getting errors triggered by changes in directories not really
# handled by pkgsrc.
#
# We have to do this here, i.e., quite late in bsd.pkg.mk parsing, so
# that the variables used in them are defined.  Otherwise we may get
# problems with the 'for' expressions.
.if defined(INFO_DIR)
CHECK_FILES_SKIP+=	${PREFIX}/${INFO_DIR}/dir
.endif
CHECK_FILES_SKIP+=	${PREFIX}/emul/linux/proc

.for e c in ${CONF_FILES} ${SUPPORT_FILES}
CHECK_FILES_SKIP+=	${c}/.pkgsrc
.endfor
.for e c o g m in ${CONF_FILES_PERMS} ${SUPPORT_FILES_PERMS}
CHECK_FILES_SKIP+=	${c}/.pkgsrc
.endfor
.for d in ${MAKE_DIRS} ${OWN_DIRS}
CHECK_FILES_SKIP+=	${d}
.endfor
.for d o g m in ${MAKE_DIRS_PERMS} ${OWN_DIRS_PERMS}
CHECK_FILES_SKIP+=	${d}
.endfor
.undef e c d o g m

CHECK_FILES_SKIP_CMD=
.for name in ${CHECK_FILES_SKIP}
CHECK_FILES_SKIP_CMD+=	| ${GREP} -v ${name}
.endfor
.undef name

# Check if the generated PLIST matches the list of really installed files.
#
.PHONY: check-files
check-files:
.if !defined(NO_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	errors=0;							\
	diff -u ${WRKDIR}/.prefix.pre ${WRKDIR}/.prefix.post		\
		>${WRKDIR}/.files.diff || ${TRUE};			\
	${GREP} '^+/' ${WRKDIR}/.files.diff | ${SED} "s|^+||" | ${SORT}	\
		>${WRKDIR}/.files.added;				\
	${GREP} '^-/' ${WRKDIR}/.files.diff | ${SED} "s|^-||" | ${SORT}	\
		>${WRKDIR}/.files.deleted;				\
	if ${TEST} `${WC} -l ${WRKDIR}/.files.deleted | 		\
		${AWK} '{ print $$1; }'` -gt 0;				\
	then								\
		echo "*** The following files have been deleted from"	\
		     "${PREFIX}!";					\
		${SED} "s|^|        |" <${WRKDIR}/.files.deleted;	\
		errors=1;						\
	fi;								\
	${GREP} '^[A-Za-z]' ${PLIST} | ${SED} "s|^|${PREFIX}/|" |	\
		${SORT} >${WRKDIR}/.files.expected;			\
	if ! ${CMP} -s ${WRKDIR}/.files.expected ${WRKDIR}/.files.added; then \
		echo "*** The PLIST does not match installed files!";	\
		echo "    The following files were not expected in ${PREFIX}:";\
		diff -u ${WRKDIR}/.files.expected ${WRKDIR}/.files.added | \
			${GREP} '^+[^+]' | ${SED} "s|^+|        |";	\
		errors=1;						\
	fi;								\
	if [ ${CHECK_FILES_STRICT} = "YES" ] &&				\
	   ! ${CMP} -s ${WRKDIR}/.sysconfdir.pre ${WRKDIR}/.sysconfdir.post; \
	then								\
		echo "*** The package has modified ${PKG_SYSCONFDIR}"	\
		     "contents directly!";				\
		echo "    The offending files/directories are:";	\
		diff -u ${WRKDIR}/.sysconfdir.pre ${WRKDIR}/.sysconfdir.post | \
			${GREP} '^+[^+]' | ${SED} "s|^+|        |";	\
		errors=1;						\
	fi;								\
	if [ ${CHECK_FILES_STRICT} = "YES" ] &&				\
	   ! ${CMP} -s ${WRKDIR}/.varbase.pre ${WRKDIR}/.varbase.post; then \
		echo "*** The package has modified ${VARBASE} contents"	\
		     "directly!";					\
		echo "    The offending files/directories are:";	\
		diff -u ${WRKDIR}/.varbase.pre ${WRKDIR}/.varbase.post |\
			${GREP} '^+[^+]' | ${SED} "s|^+|        |";	\
		errors=1;						\
	fi;								\
	${RM} -f ${WRKDIR}/.files.added ${WRKDIR}/.files.deleted	\
	         ${WRKDIR}/.files.diff ${WRKDIR}/.files.expected;	\
	${TEST} $$errors -eq 0
.endif

LOCKFILE=	${WRKDIR}/.lockfile
.for targ in ${_PKG_PHASES_WRKDIR}
.PHONY: acquire-${targ}-lock release-${targ}-lock
acquire-${targ}-lock: .OPTIONAL
release-${targ}-lock: .OPTIONAL

.  if ${PKGSRC_LOCKTYPE} != "none"
acquire-${targ}-lock:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	ppid=`${PS} -p $$$$ -o ppid | ${AWK} 'NR == 2 { print $$1 }'`;	\
	if ${TEST} "$$ppid" = ""; then					\
		${ECHO} "No parent process ID found.";			\
		${FALSE};						\
	fi;								\
	while true; do							\
		if ${TEST} -f /var/run/dmesg.boot -a -f ${LOCKFILE} -a	\
		     /var/run/dmesg.boot -nt ${LOCKFILE}; then		\
			${ECHO} "=> Removing stale ${LOCKFILE}";	\
			${RM} ${LOCKFILE};				\
		fi;							\
		${SHLOCK} -f ${LOCKFILE} -p $$ppid && break;		\
		${ECHO} "=> Lock is held by pid `cat ${LOCKFILE}`";	\
		case "${PKGSRC_LOCKTYPE}" in				\
		once)	exit 1 ;;					\
		sleep)	sleep ${PKGSRC_SLEEPSECS} ;;			\
		esac							\
	done;								\
	if [ "${PKG_VERBOSE}" != "" ]; then				\
		${ECHO_MSG} "=> Lock acquired on behalf of process $$ppid"; \
	fi

release-${targ}-lock:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ "${PKG_VERBOSE}" != "" ]; then				\
		${ECHO_MSG} "=> Lock released on behalf of process `${CAT} ${LOCKFILE}`"; \
	fi;								\
	${RM} ${LOCKFILE}
.  endif # PKGSRC_LOCKTYPE
.endfor


# Empty pre-* and post-* targets

.for targ in fetch ${_PKG_PHASES_WRKDIR} install-script clean distclean
.PHONY: pre-${targ} post-${targ}
pre-${targ}: .OPTIONAL
post-${targ}: .OPTIONAL
.endfor

# Reinstall
#
# Special target to re-run install

.PHONY: reinstall
reinstall:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${install_COOKIE} ${package_COOKIE} ${PLIST}
	${_PKG_SILENT}${_PKG_DEBUG}DEPENDS_TARGET=${DEPENDS_TARGET:Q} ${MAKE} ${MAKEFLAGS} install

# Deinstall
#
# Special target to remove installation

.PHONY: deinstall
deinstall: do-su-deinstall

.if (${DEINSTALLDEPENDS} != "NO")
.  if (${DEINSTALLDEPENDS} != "ALL")
# used for removing stuff in bulk builds
real-su-deinstall-flags+=	-r -R
# used for "update" target
.  else
real-su-deinstall-flags+=	-r
.  endif
.endif
.ifdef PKG_VERBOSE
real-su-deinstall-flags+=	-v
.endif
.ifdef PKG_PRESERVE
.  if (${UPDATE_RUNNING} == "YES")
# used to update w/o removing any files
real-su-deinstall-flags+=	-N -f
.  endif
.endif

.PHONY: real-su-deinstall
real-su-deinstall:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_INFO} -e \"${PKGNAME}\" || ${TRUE}`";		\
	case "$$found" in						\
	"") found="`${PKG_BEST_EXISTS} \"${PKGWILDCARD}\" || ${TRUE}`" ;; \
	esac;								\
	if [ "$$found" != "" ]; then					\
		${ECHO} Running ${PKG_DELETE} ${real-su-deinstall-flags} $$found ; \
		${PKG_DELETE} ${real-su-deinstall-flags} $$found || ${TRUE} ; \
	fi
.if (${DEINSTALLDEPENDS} != "NO") && (${DEINSTALLDEPENDS} != "ALL")
	@${SHCOMMENT} Also remove BUILD_DEPENDS:
.  for pkg in ${BUILD_DEPENDS:C/:.*$//}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	found="`${PKG_BEST_EXISTS} \"${pkg}\" || ${TRUE}`";		\
	if [ "$$found" != "" ]; then					\
		${ECHO} Running ${PKG_DELETE} $$found;			\
		${PKG_DELETE} ${real-su-deinstall-flags} $$found || ${TRUE}; \
	fi
.  endfor
.endif # DEINSTALLDEPENDS
	@${RM} -f ${install_COOKIE} ${package_COOKIE}


################################################################
# Some more targets supplied for users' convenience
################################################################

# The 'update' target can be used to update a package and all
# currently installed packages that depend upon this package.

.PHONY: update
.if !target(update)
.if exists(${DDIR})
RESUMEUPDATE?=	YES
CLEAR_DIRLIST?=	NO

update:
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG}				\
		"${_PKGSRC_IN}> Resuming update for ${PKGNAME}"
.  if ${REINSTALL} != "NO" && ${UPDATE_TARGET} != "replace"
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} deinstall UPDATE_RUNNING=YES DEINSTALLDEPENDS=ALL
.  endif
.else
RESUMEUPDATE?=	NO
CLEAR_DIRLIST?=	YES

update:
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} ${DDIR}
.  if ${UPDATE_TARGET} != "replace"
	${_PKG_SILENT}${_PKG_DEBUG}if ${PKG_INFO} -qe ${PKGBASE}; then	\
		${MAKE} ${MAKEFLAGS} deinstall UPDATE_RUNNING=YES DEINSTALLDEPENDS=ALL \
		|| (${RM} ${DDIR} && ${FALSE});				\
	fi
.  endif
.endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} ${UPDATE_TARGET} KEEP_WRKDIR=YES	\
			DEPENDS_TARGET=${DEPENDS_TARGET:Q}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	[ ! -s ${DDIR} ] || for dep in `${CAT} ${DDIR}` ; do		\
		(if cd ../.. && cd "$${dep}" ; then			\
			${ECHO_MSG} "${_PKGSRC_IN}> Installing in $${dep}" && \
			if [ "(" "${RESUMEUPDATE}" = "NO" -o 		\
			     "${REINSTALL}" != "NO" ")" -a		\
			     "${UPDATE_TARGET}" != "replace" ] ; then	\
				${MAKE} ${MAKEFLAGS} deinstall UPDATE_RUNNING=YES; \
			fi &&						\
			${MAKE} ${MAKEFLAGS} ${UPDATE_TARGET}		\
				DEPENDS_TARGET=${DEPENDS_TARGET:Q} ;	\
		else							\
			${ECHO_MSG} "${_PKGSRC_IN}> Skipping removed directory $${dep}"; \
		fi) ;							\
	done
.if ${NOCLEAN} == "NO"
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} clean-update CLEAR_DIRLIST=YES
.endif


.PHONY: clean-update
clean-update:
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} ${DDIR}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -s ${DDIR} ] ; then					\
		for dep in `${CAT} ${DDIR}` ; do			\
			(if cd ../.. && cd "$${dep}" ; then		\
				${MAKE} ${MAKEFLAGS} clean ;		\
			else						\
				${ECHO_MSG} "${_PKGSRC_IN}> Skipping removed directory $${dep}";\
			fi) ;						\
		done ;							\
	fi
.if ${CLEAR_DIRLIST} != "NO"
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} clean
.else
	${_PKG_SILENT}${_PKG_DEBUG}					\
		${MAKE} ${MAKEFLAGS} clean update-dirlist		\
		DIRLIST="`${CAT} ${DDIR}`" PKGLIST="`${CAT} ${DLIST}`"
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO_MSG}				\
		"${_PKGSRC_IN}> Warning: preserved leftover directory list.  Your next";\
		${ECHO_MSG} "${_PKGSRC_IN}>          \`\`${MAKE} update'' may fail.  It is advised to use";\
		${ECHO_MSG} "${_PKGSRC_IN}>          \`\`${MAKE} update REINSTALL=YES'' instead!"
.endif

.endif	# !target(update)


.PHONY: update-dirlist
update-dirlist:
	${_PKG_SILENT}${_PKG_DEBUG}${MKDIR} -p ${WRKDIR}
.ifdef PKGLIST
.  for __tmp__ in ${PKGLIST}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} >>${DLIST} "${__tmp__}"
.  endfor
.endif
.ifdef DIRLIST
.  for __tmp__ in ${DIRLIST}
	${_PKG_SILENT}${_PKG_DEBUG}${ECHO} >>${DDIR} "${__tmp__}"
.  endfor
.endif


${DDIR}: ${DLIST}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	ddir=`${SED} 's:-[^-]*$$::' ${DLIST}`;				\
	${ECHO} >${DDIR};						\
	for pkg in $${ddir} ; do					\
		if ${PKG_INFO} -b "$${pkg}" >/dev/null 2>&1 ; then	\
			${PKG_INFO} -b "$${pkg}" | ${SED}	-ne	\
			    's,\([^/]*/[^/]*\)/Makefile:.*,\1,p' | 	\
			    ${HEAD} -1 >>${DDIR};			\
		fi ;							\
	done

${DLIST}: ${WRKDIR}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	{ ${PKG_DELETE} -n "${PKGWILDCARD}" 2>&1 | 			\
		${GREP} '^	' |					\
		${AWK} '{ l[NR]=$$0 } END { for (i=NR;i>0;--i) print l[i] }' \
	|| ${TRUE}; } > ${DLIST}

# Create a binary package from an install package using "pkg_tarup"
.PHONY: tarup
tarup:
.if ${PKG_INSTALLATION_TYPE} == "overwrite"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${RM} -f ${PACKAGES}/All/${PKGNAME}${PKG_SUFX};			\
	${SETENV} PKG_DBDIR=${_PKG_DBDIR} PKG_SUFX=${PKG_SUFX}		\
		PKGREPOSITORY=${PACKAGES}/All				\
		${LOCALBASE}/bin/pkg_tarup ${PKGNAME};			\
	for CATEGORY in ${CATEGORIES}; do				\
		${MKDIR} ${PACKAGES}/$$CATEGORY;			\
		cd ${PACKAGES}/$$CATEGORY;				\
		${RM} -f ${PKGNAME}${PKG_SUFX};				\
		${LN} -s ../All/${PKGNAME}${PKG_SUFX};			\
	done
.endif

# shared code for replace and undo-replace
_REPLACE=								\
	if [ -f ${_PKG_DBDIR}/$$oldpkgname/+REQUIRED_BY ]; then		\
		${MV} ${_PKG_DBDIR}/$$oldpkgname/+REQUIRED_BY ${WRKDIR}/.req; \
	fi;								\
	${MAKE} deinstall UPDATE_RUNNING=YES;				\
	$$replace_action;						\
	if [ -f ${WRKDIR}/.req ]; then					\
		${MV} ${WRKDIR}/.req ${_PKG_DBDIR}/$$newpkgname/+REQUIRED_BY; \
		for pkg in `${CAT} ${_PKG_DBDIR}/$$newpkgname/+REQUIRED_BY`; do \
			${SETENV} NEWPKGNAME=$$newpkgname		\
				${AWK} '/^@pkgdep '$$oldpkgname'/ { print "@pkgdep " ENVIRON["NEWPKGNAME"]; next } { print }' \
				< ${_PKG_DBDIR}/$$pkg/+CONTENTS > ${_PKG_DBDIR}/$$pkg/+CONTENTS.$$$$ && \
			${MV} ${_PKG_DBDIR}/$$pkg/+CONTENTS.$$$$ ${_PKG_DBDIR}/$$pkg/+CONTENTS; \
		done;							\
	fi

# replace a package in place - not for the faint-hearted
.PHONY: real-su-replace
real-su-replace:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "*** WARNING - experimental target - data loss may be experienced ***"; \
	if [ -x ${LOCALBASE}/bin/pkg_tarup ]; then			\
		${SETENV} PKGREPOSITORY=${WRKDIR} ${LOCALBASE}/bin/pkg_tarup ${PKGBASE}; \
	else								\
		${ECHO} "No ${LOCALBASE}/bin/pkg_tarup binary - can't pkg_tarup ${PKGBASE}"; \
		exit 1;							\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}					\
	oldpkgname=`${PKG_BEST_EXISTS} "${PKGWILDCARD}"`;		\
	newpkgname=${PKGNAME};						\
	${ECHO} "$$oldpkgname" > ${WRKDIR}/.replace;			\
	replace_action="${MAKE} install";				\
	${_REPLACE}

# undo the replacement of a package - not for the faint-hearted either
.PHONY: real-su-undo-replace
real-su-undo-replace:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${WRKDIR}/.replace ]; then				\
		${ECHO_MSG} "No replacement to undo";			\
		exit 1;							\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO_MSG} "*** WARNING - experimental target - data loss may be experienced ***"; \
	oldpkgname=${PKGNAME};						\
	newpkgname=`${CAT} ${WRKDIR}/.replace`;				\
	replace_action="${SETENV} ${PKG_ADD} ${WRKDIR}/$$newpkgname${PKG_SUFX}"; \
	${_REPLACE};							\
	${RM} ${WRKDIR}/.replace

# This is for the use of sites which store distfiles which others may
# fetch - only fetch the distfile if it is allowed to be
# re-distributed freely
.PHONY: mirror-distfiles
mirror-distfiles:
.if !defined(NO_SRC_ON_FTP)
	@${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} fetch NO_SKIP=yes
.endif


# Cleaning up

.PHONY: clean
clean: pre-clean
.if (${CLEANDEPENDS} != "NO") && (!empty(BUILD_DEPENDS) || !empty(DEPENDS))
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} clean-depends
.endif
	@${ECHO_MSG} "${_PKGSRC_IN}> Cleaning for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ -d ${WRKDIR} ]; then					\
		if [ -w ${WRKDIR} ]; then				\
			${RM} -rf ${WRKDIR};				\
		else							\
			${ECHO_MSG} "${_PKGSRC_IN}> ${WRKDIR} not writable, skipping"; \
		fi;							\
	fi
.ifdef WRKOBJDIR
	-${_PKG_SILENT}${_PKG_DEBUG}					\
	${RMDIR} ${BUILD_DIR} 2>/dev/null;				\
	${RM} -f ${WRKDIR_BASENAME}
.endif


.PHONY: clean-depends
clean-depends:
.if !empty(BUILD_DEPENDS) || !empty(DEPENDS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for i in `${_SHOW_ALL_DEPENDS_DIRS_EXCL}`; do			\
		cd ${.CURDIR}/../../$$i &&				\
		${MAKE} ${MAKEFLAGS} CLEANDEPENDS=NO clean;		\
	done
.endif


.PHONY: cleandir
cleandir: clean


.PHONY: distclean
distclean: pre-distclean clean
	${_PKG_SILENT}${ECHO_MSG} "${_PKGSRC_IN}> Dist cleaning for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}if [ -d ${_DISTDIR} ]; then		\
		cd ${_DISTDIR} &&					\
		${TEST} -z "${DISTFILES}" || ${RM} -f ${DISTFILES};	\
		${TEST} -z "${PATCHFILES}" || ${RM} -f ${PATCHFILES};	\
	fi
.if defined(DIST_SUBDIR) && exists(DIST_SUBDIR)
	-${_PKG_SILENT}${_PKG_DEBUG}${RMDIR} ${_DISTDIR}
.endif
	-${_PKG_SILENT}${_PKG_DEBUG}${RM} -f README.html

# List of sites carrying binary pkgs. Variables "rel" and "arch" are
# replaced with OS release ("1.5", ...) and architecture ("mipsel", ...)
BINPKG_SITES?= \
	ftp://ftp.NetBSD.org/pub/NetBSD/packages/$${rel}/$${arch}

# List of flags to pass to pkg_add(1) for bin-install:

BIN_INSTALL_FLAGS?= 	# -v
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
PKG_ARGS_ADD=		-W ${LOCALBASE} -w ${DEFAULT_VIEW}
.endif
_BIN_INSTALL_FLAGS=	${BIN_INSTALL_FLAGS}
_BIN_INSTALL_FLAGS+=	${PKG_ARGS_ADD}

# Install binary pkg, without strict uptodate-check first
.PHONY: real-su-bin-install
real-su-bin-install:
	@found="`${PKG_BEST_EXISTS} \"${PKGWILDCARD}\" || ${TRUE}`";	\
	if [ "$$found" != "" ]; then					\
		${ECHO_MSG} "${_PKGSRC_IN}> $$found is already installed - perhaps an older version?"; \
		${ECHO_MSG} "*** If so, you may wish to \`\`pkg_delete $$found'' and install"; \
		${ECHO_MSG} "*** this package again by \`\`${MAKE} bin-install'' to upgrade it properly."; \
		${SHCOMMENT} ${ECHO_MSG} "*** or use \`\`${MAKE} bin-update'' to upgrade it and all of its dependencies."; \
		exit 1;							\
	fi
	@if [ -f ${PKGFILE} ] ; then 					\
		${ECHO_MSG} "Installing from binary pkg ${PKGFILE}" ;	\
		${PKG_ADD} ${_BIN_INSTALL_FLAGS} ${PKGFILE} ;		\
	else 				 				\
		rel=`${UNAME} -r | ${SED} 's@\.\([0-9]*\)[\._].*@\.\1@'`; \
		arch=${MACHINE_ARCH}; 					\
		for site in ${BINPKG_SITES} ; do 			\
			${ECHO} Trying `eval ${ECHO} $$site`/All ; 	\
			${SHCOMMENT} ${ECHO} ${SETENV} PKG_PATH="`eval ${ECHO} $$site`/All" ${PKG_ADD} ${_BIN_INSTALL_FLAGS} ${PKGNAME}${PKG_SUFX} ; \
			if ${SETENV} PKG_PATH="`eval ${ECHO} $$site`/All" ${PKG_ADD} ${BIN_INSTALL_FLAGS} ${PKGNAME}${PKG_SUFX} ; then \
				${ECHO} "${PKGNAME} successfully installed."; \
				break ; 				\
			fi ; 						\
		done ; 							\
		if ! ${PKG_INFO} -qe "${PKGNAME}" ; then 		\
			${SHCOMMENT} Cycle through some FTP server here ;\
			${ECHO_MSG} "Installing from source" ;		\
			${MAKE} ${MAKEFLAGS} package 			\
				DEPENDS_TARGET=${DEPENDS_TARGET:Q} &&	\
			${MAKE} ${MAKEFLAGS} clean ;			\
		fi ; \
	fi

.PHONY: bin-install
bin-install:
	@${ECHO_MSG} "${_PKGSRC_IN}> Binary install for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	realtarget="real-su-bin-install";				\
	action="binary install";					\
	${_SU_TARGET}

################################################################
# The special package-building targets
# You probably won't need to touch these
################################################################

# Show (recursively) all the packages this package depends on.
# If PACKAGE_DEPENDS_WITH_PATTERNS is set, print as pattern (if possible)
PACKAGE_DEPENDS_WITH_PATTERNS?=true
.PHONY: run-depends-list
run-depends-list:
.for dep in ${DEPENDS}
	@pkg="${dep:C/:.*//}";						\
	dir="${dep:C/[^:]*://}";					\
	cd ${.CURDIR};							\
	if ${PACKAGE_DEPENDS_WITH_PATTERNS}; then			\
		${ECHO} "$$pkg";					\
	else								\
		if cd $$dir 2>/dev/null; then				\
			${MAKE} ${MAKEFLAGS} package-name PACKAGE_NAME_TYPE=${PACKAGE_NAME_TYPE}; \
		else 							\
			${ECHO_MSG} "Warning: \"$$dir\" non-existent -- @pkgdep registration incomplete" >&2; \
		fi;							\
	fi
.endfor

# Set to "html" by the README.html target to generate HTML code,
# or to "svr4" to print SVR4 (Solaris, ...) short package names, from
# SVR4_PKGNAME variable.
# This variable is passed down via build-depends-list and run-depends-list
PACKAGE_NAME_TYPE?=	name

# Nobody should want to override this unless PKGNAME is simply bogus.
HTML_PKGNAME=<a href="../../${PKGPATH:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g}/README.html">${PKGNAME:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g}</A>

.PHONY: package-name
package-name:
.if (${PACKAGE_NAME_TYPE} == "html")
	@${ECHO} '<a href="../../${PKGPATH:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g}/README.html">${PKGNAME:S/&/\&amp;/g:S/>/\&gt;/g:S/</\&lt;/g}</A>'
.elif (${PACKAGE_NAME_TYPE} == "svr4")
	@${ECHO} ${SVR4_PKGNAME}
.else
	@${ECHO} ${PKGNAME}
.endif # PACKAGE_NAME_TYPE

# Build a package but don't check the package cookie

.PHONY: repackage
repackage: pre-repackage package

.PHONY: pre-repackage
pre-repackage:
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${package_COOKIE}

# Build a package but don't check the cookie for installation, also don't
# install package cookie

.PHONY: package-noinstall
package-noinstall:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${.CURDIR} && ${MAKE} ${MAKEFLAGS} PACKAGE_NOINSTALL=yes real-package

################################################################
# Dependency checking
################################################################

# Tells whether to halt execution if the object formats differ
FATAL_OBJECT_FMT_SKEW?= yes
WARN_NO_OBJECT_FMT?= yes

do-depends:
.for dep in ${DEPENDS} ${BUILD_DEPENDS}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	pkg="${dep:C/:.*//}";						\
	dir="${dep:C/[^:]*://:C/:.*$//}";				\
	found=`${PKG_BEST_EXISTS} "$$pkg" || ${TRUE}`;			\
	if [ "X$$REBUILD_DOWNLEVEL_DEPENDS" != "X" ]; then		\
		pkgname=`cd $$dir ; ${MAKE} ${MAKEFLAGS} show-var-noeval VARNAME=PKGNAME`; \
		if [ "X$$found" != "X" -a "X$$found" != "X$${pkgname}" ]; then \
			${ECHO_MSG} "ignoring old installed package \"$$found\""; \
			found="";					\
		fi;							\
	fi;								\
	if [ "$$found" != "" ]; then					\
		instobjfmt=`${PKG_INFO} -B "$$found" | ${AWK} -F'=[ \t]*' '/^OBJECT_FMT/ {print $$2; exit}'`; \
		if [ "$$instobjfmt" = "" ]; then			\
			if [ "X${WARN_NO_OBJECT_FMT}" != "Xno" ]; then	\
				${ECHO} "WARNING: Unknown object format for installed package $$found - continuing"; \
			fi;						\
		elif [ "$$instobjfmt" != "${OBJECT_FMT}" ]; then	\
			${ECHO} "Installed package $$found is an $$instobjfmt package."; \
			${ECHO} "You are building an ${OBJECT_FMT} package, which will not inter-operate."; \
			${ECHO} "Please update the $$found package to ${OBJECT_FMT}"; \
			if [ "X${FATAL_OBJECT_FMT_SKEW}" != "Xno" ]; then \
				exit 1;					\
			fi;						\
		fi;							\
		${ECHO_MSG} "${_PKGSRC_IN}> Required installed package $$pkg: $${found} found"; \
	else								\
		${ECHO_MSG} "${_PKGSRC_IN}> Required package $$pkg: NOT found"; \
		target=${DEPENDS_TARGET:Q};				\
		${ECHO_MSG} "${_PKGSRC_IN}> Verifying $$target for $$dir"; 	\
		if [ ! -d $$dir ]; then					\
			${ECHO_MSG} "=> No directory for $$dir.  Skipping.."; \
		else							\
			cd $$dir ;					\
			${SETENV} _PKGSRC_DEPS=", ${PKGNAME}${_PKGSRC_DEPS}" ${MAKE} ${MAKEFLAGS} $$target PKGNAME_REQD=\'$$pkg\' || exit 1; \
			${ECHO_MSG} "${_PKGSRC_IN}> Returning to build of ${PKGNAME}"; \
		fi;							\
	fi
.endfor	# DEPENDS

.PHONY: build-depends-list
build-depends-list:
	@for dir in `${_SHOW_ALL_DEPENDS_DIRS_EXCL}`; do		\
		(cd ../../$$dir &&					\
		${MAKE} ${MAKEFLAGS} package-name)			\
	done

# Stat all the files of one pkg and sum the sizes up.
#
# XXX This is intended to be run before pkg_create is called, so the
# existence of ${PLIST} can be assumed.
.PHONY: print-pkg-size-this
print-pkg-size-this:
	@${SHCOMMENT} "This pkg's files" ;				\
	${AWK} 'BEGIN { base = "${PREFIX}/" }				\
		/^@cwd/ { base = $$2 "/" }				\
		/^@/ { next }						\
		{ print base $$0 }'					\
		<${PLIST} 						\
	| ${SORT} -u							\
	| ${SED} -e "s/'/'\\\\''/g" -e "s/.*/'&'/"			\
	| ${XARGS} -n 256 ${LS} -ld					\
	| ${AWK} 'BEGIN { print("0 "); }				\
		  { print($$5, " + "); }				\
		  END { print("p"); }'					\
	| ${DC}

# Sizes of required pkgs (only)
#
# XXX This is intended to be run before pkg_create is called, so the
# dependencies are all installed.
.PHONY: print-pkg-size-depends
print-pkg-size-depends:
	@pkglist=`${MAKE} ${MAKEFLAGS} run-depends-list`;		\
	if [ "X$${pkglist}" != "X" ]; then				\
		${ECHO} $${pkglist}					\
		| ${XARGS} -n 1 ${SETENV} ${PKG_BEST_EXISTS}		\
		| ${SORT} -u						\
		| ${XARGS} -n 256 ${SETENV} ${PKG_INFO} -qs		\
		| ${AWK} -- 'BEGIN { print("0 "); }			\
			/^[0-9]+$$/ { print($$1, " + "); }		\
			END { print("p"); }'				\
		| ${DC};						\
	else								\
		${ECHO} "0";						\
	fi

# By default, all packages attempt to link into the views.
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
BUILD_VIEWS?=	yes
.endif

# DEFAULT_VIEW.${PKGBASE}	default view for ${PKGBASE}
# VIEWBASE			base location of files at run-time
#
DEFAULT_VIEW.${PKGBASE}?=	${DEFAULT_VIEW}
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
.  if empty(DEFAULT_VIEW.${PKGBASE}:M"")
VIEWBASE=	${LOCALBASE}/${DEFAULT_VIEW.${PKGBASE}}
.  else
VIEWBASE=	${LOCALBASE}
.  endif
.elif ${PKG_INSTALLATION_TYPE} == "overwrite"
VIEWBASE=	${PREFIX}
.endif
MAKE_ENV+=	VIEWBASE=${VIEWBASE}

PKGVIEWS+=	${DEFAULT_VIEW.${PKGBASE}}

# Fake installation of package so that user can pkg_delete it later.
# Also, make sure that an installed package is recognized correctly in
# accordance to the @pkgdep directive in the packing lists.

.PHONY: fake-pkg
fake-pkg: ${PLIST} ${DESCR} ${MESSAGE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -f ${PLIST} -o ! -f ${DESCR} ]; then			\
		${ECHO} "** Missing package files for ${PKGNAME} - installation not recorded."; \
		exit 1;							\
	fi
	${_PKG_SILENT}${_PKG_DEBUG}					\
	if [ ! -d ${_PKG_DBDIR} ]; then					\
		${RM} -f ${_PKG_DBDIR};					\
		${MKDIR} ${_PKG_DBDIR};					\
	fi
.if defined(FORCE_PKG_REGISTER)
	${_PKG_SILENT}${_PKG_DEBUG}${PKG_ADMIN} delete ${PKGNAME}
.  if ${PKG_INSTALLATION_TYPE} == "overwrite"
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -rf ${_PKG_DBDIR}/${PKGNAME}
.  endif
.endif
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${BUILD_VERSION_FILE} ${BUILD_INFO_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${SIZE_PKG_FILE} ${SIZE_ALL_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}${RM} -f ${PRESERVE_FILE}
.if defined(PKG_PRESERVE)
	${_PKG_SILENT}${_PKG_DEBUG}${DATE} > ${PRESERVE_FILE}
.endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	files="";							\
	for f in ${.CURDIR}/Makefile ${FILESDIR}/* ${PKGDIR}/*; do	\
		if [ -f "$$f" ]; then					\
			files="$$files \"$$f\"";			\
		fi;							\
	done;								\
	if [ -f ${DISTINFO_FILE} ]; then				\
		for f in `${AWK} 'NF == 4 && $$3 == "=" { gsub("[()]", "", $$2); print $$2 }' < ${DISTINFO_FILE}`; do \
			if [ -f ${PATCHDIR}/$$f ]; then			\
				files="$$files \"${PATCHDIR}/$$f\"";	\
			fi;						\
		done;							\
	fi;								\
	if [ -d ${PATCHDIR} ]; then					\
		for f in ${PATCHDIR}/patch-*; do			\
			case $$f in					\
			*.orig|*.rej|*~) ;;				\
			${PATCHDIR}/patch-local-*)			\
				files="$$files \"$$f\"" ;;		\
			esac;						\
		done;							\
	fi;								\
	eval ${GREP} '\$$NetBSD' $$files | ${SED} -e 's|^${PKGSRCDIR}/||' > ${BUILD_VERSION_FILE}
.for def in ${BUILD_DEFS} ${BUILD_DEFS_FIXED}
	@${ECHO} ${def}=${${def}:Q} | ${SED} -e 's|^PATH=[^ 	]*|PATH=...|' >> ${BUILD_INFO_FILE}
.endfor
.if defined(USE_LANGUAGES) && !empty(USE_LANGUAGES)
	@${ECHO} "CC_VERSION=${CC_VERSION}" >> ${BUILD_INFO_FILE}
.endif
.if defined(USE_PERL5) && (${USE_PERL5} == "run")
	@${ECHO} "PERL=`${PERL5} --version 2>/dev/null | ${GREP} 'This is perl'`" >> ${BUILD_INFO_FILE}
.endif
.if !empty(USE_GNU_TOOLS:Mmake)
	@${ECHO} "GMAKE=`${GMAKE} --version | ${GREP} Make`" >> ${BUILD_INFO_FILE}
.endif
.if ${SHLIB_HANDLING} == "YES" && ${CHECK_SHLIBS} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	case "${LDD}" in						\
	"")	ldd=`${TYPE} ldd 2>/dev/null | ${AWK} '{ print $$NF }'`;; \
	*)	ldd="${LDD}";						\
	esac;								\
	case "${OBJECT_FMT}" in						\
	ELF)	bins=`${SETENV} PREFIX=${PREFIX} ${AWK} '/^(bin|sbin|libexec)\// { print ENVIRON["PREFIX"] "/" $$0 }' ${PLIST} || ${TRUE}`; \
		libs=`${SETENV} PREFIX=${PREFIX} ${AWK} '/^lib\/lib.*\.so\.[0-9]+$$/ { print ENVIRON["PREFIX"] "/" $$0 }' ${PLIST} || ${TRUE}`; \
		if ${TEST} "$$bins" != "" -o "$$libs" != ""; then 	\
			requires=`($$ldd $$bins $$libs 2>/dev/null || ${TRUE}) | ${AWK} 'NF == 3 { print $$3 }' | ${SORT} -u`; \
		fi;							\
		linklibs=`${SETENV} PREFIX=${PREFIX} ${AWK} '/^[^@].*\.so\.[0-9\.]+$$/ { print ENVIRON["PREFIX"] "/" $$0 }' ${PLIST} || ${TRUE}`; \
		for i in $${linklibs}; do				\
			if ${TEST} -r $$i -a ! -x $$i -a ! -h $$i; then	\
				${TEST} "${PKG_DEVELOPER:Uno}" = "no" || \
					${ECHO} "$$i: installed without execute permission; fixing (should use [BSD_]INSTALL_LIB)"; \
				${CHMOD} +x $$i;			\
			fi;						\
		done;							\
		;;							\
	Mach-O)	bins=`${SETENV} PREFIX=${PREFIX} ${AWK} '/^(bin|sbin|libexec)\// { print ENVIRON["PREFIX"] "/" $$0 }' ${PLIST} || ${TRUE}`; \
		libs=`${SETENV} PREFIX=${PREFIX} ${AWK} '/^lib\/lib.*\.dylib/ { print ENVIRON["PREFIX"] "/" $$0 }' ${PLIST} || ${TRUE}`; \
		if ${TEST} "$$bins" != "" -o "$$libs" != ""; then 	\
			requires=`($$ldd $$bins $$libs 2>/dev/null || ${TRUE}) | ${AWK} '/compatibility version/ { print $$1 }' | ${SORT} -u`; \
		fi;							\
		;;							\
	esac;								\
	for i in "" $$libs; do						\
		${TEST} "$$i" = "" && continue;				\
		${ECHO} "PROVIDES=$$i" >> ${BUILD_INFO_FILE};		\
	done;								\
	for req in "" $$requires; do					\
		${TEST} "$$req" = "" && continue;			\
		${ECHO} "REQUIRES=$$req" >> ${BUILD_INFO_FILE};		\
	done
.endif
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${ECHO} "_PKGTOOLS_VER=${PKGTOOLS_VERSION}" >> ${BUILD_INFO_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	size_this=`${MAKE} ${MAKEFLAGS} print-pkg-size-this`;		\
	size_depends=`${MAKE} ${MAKEFLAGS} print-pkg-size-depends`;	\
	${ECHO} $$size_this >${SIZE_PKG_FILE};				\
	${ECHO} $$size_this $$size_depends + p | ${DC} >${SIZE_ALL_FILE}
	${_PKG_SILENT}${_PKG_DEBUG}					\
	doit=yes;							\
	case ${PKG_INSTALLATION_TYPE} in				\
	overwrite)	if [ -d ${_PKG_DBDIR}/${PKGNAME} ]; then	\
				doit=no;				\
			fi ;;						\
	esac;								\
	case $$doit in							\
	yes)								\
		${ECHO_MSG} "${_PKGSRC_IN}> Registering installation for ${PKGNAME}"; \
		${MKDIR} ${_PKG_DBDIR}/${PKGNAME};			\
		${PKG_CREATE} ${PKG_ARGS_INSTALL} -O ${PKGFILE} > ${_PKG_DBDIR}/${PKGNAME}/+CONTENTS; \
		${CP} ${DESCR} ${_PKG_DBDIR}/${PKGNAME}/+DESC;	\
		${ECHO} ${COMMENT:Q} > ${_PKG_DBDIR}/${PKGNAME}/+COMMENT; \
		${CP} ${BUILD_VERSION_FILE} ${_PKG_DBDIR}/${PKGNAME}/+BUILD_VERSION; \
		${CP} ${BUILD_INFO_FILE} ${_PKG_DBDIR}/${PKGNAME}/+BUILD_INFO; \
		if ${TEST} -f ${SIZE_PKG_FILE}; then 			\
			${CP} ${SIZE_PKG_FILE} ${_PKG_DBDIR}/${PKGNAME}/+SIZE_PKG; \
		fi ; 							\
		if ${TEST} -f ${SIZE_ALL_FILE}; then 			\
			${CP} ${SIZE_ALL_FILE} ${_PKG_DBDIR}/${PKGNAME}/+SIZE_ALL; \
		fi ; 							\
		if ${TEST} -f ${PRESERVE_FILE}; then 			\
			${CP} ${PRESERVE_FILE} ${_PKG_DBDIR}/${PKGNAME}/+PRESERVE; \
		fi ; 							\
		if [ "${PKG_INSTALLATION_TYPE}" = "pkgviews" ]; then	\
			${TOUCH} ${_PKG_DBDIR}/${PKGNAME}/+VIEWS;	\
		fi ;							\
		if [ -n "${INSTALL_FILE}" ]; then			\
			if ${TEST} -f ${INSTALL_FILE}; then		\
				${CP} ${INSTALL_FILE} ${_PKG_DBDIR}/${PKGNAME}/+INSTALL; \
			fi;						\
		fi;							\
		if [ -n "${DEINSTALL_FILE}" ]; then			\
			if ${TEST} -f ${DEINSTALL_FILE}; then		\
				${CP} ${DEINSTALL_FILE} ${_PKG_DBDIR}/${PKGNAME}/+DEINSTALL; \
			fi;						\
		fi;							\
		if [ -n "${MESSAGE}" ]; then				\
			if ${TEST} -f ${MESSAGE}; then			\
				${CP} ${MESSAGE} ${_PKG_DBDIR}/${PKGNAME}/+DISPLAY; \
			fi;						\
		fi;							\
		list="`${MAKE} ${MAKEFLAGS} run-depends-list ECHO_MSG=${TRUE} | ${SORT} -u`" ; \
		for realdep in `${ECHO} $$list | ${XARGS} -n 1 ${SETENV} ${PKG_BEST_EXISTS} | ${SORT} -u`; do \
			if ${TEST} -z "$$realdep"; then			\
				${ECHO} "$$dep not installed - dependency NOT registered" ; \
			elif [ -d ${_PKG_DBDIR}/$$realdep ]; then	\
				if ${TEST} ! -f ${_PKG_DBDIR}/$$realdep/+REQUIRED_BY; then \
					${TOUCH} ${_PKG_DBDIR}/$$realdep/+REQUIRED_BY; \
				fi; 					\
				${AWK} 'BEGIN { found = 0; } 		\
					$$0 == "${PKGNAME}" { found = 1; } \
					{ print $$0; } 			\
					END { if (!found) { printf("%s\n", "${PKGNAME}"); }}' \
					< ${_PKG_DBDIR}/$$realdep/+REQUIRED_BY > ${_PKG_DBDIR}/$$realdep/reqby.$$$$; \
				${MV} ${_PKG_DBDIR}/$$realdep/reqby.$$$$ ${_PKG_DBDIR}/$$realdep/+REQUIRED_BY; \
				${ECHO} "${PKGNAME} requires installed package $$realdep"; \
			fi;						\
		done ;;							\
	esac
.if (${PKG_INSTALLATION_TYPE} == "pkgviews") && \
      !empty(BUILD_VIEWS:M[yY][eE][sS])
	${_PKG_SILENT}${_PKG_DEBUG}${MAKE} ${MAKEFLAGS} build-views
.endif	# pkgviews

.PHONY: build-views
build-views: do-su-build-views

.PHONY: do-su-build-views
do-su-build-views:
	@${ECHO_MSG} "${_PKGSRC_IN}> Building views for ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	realtarget="real-su-build-views";				\
	action="build-views";						\
	${_SU_TARGET}

.PHONY: real-su-build-views
real-su-build-views:
.if (${PKG_INSTALLATION_TYPE} == "pkgviews") && defined(PKGVIEWS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	${MKDIR} ${LOCALBASE};						\
	for v in ${PKGVIEWS}; do					\
		case "$$v" in						\
		"")	dbdir=${PKG_DBDIR}; viewname=standard ;;	\
		*)	dbdir=${LOCALBASE}/$$v/.dbdir; viewname=$$v ;;	\
		esac;							\
		${ECHO} "=> Performing package view clash check for ${PKGNAME} in $$viewname view"; \
		pkg=`${PKG_INFO_CMD} -K $$dbdir -e ${PKGBASE} || ${TRUE}`; \
		case "$$pkg" in						\
		"")	;;						\
		*)	${ECHO} "*** ${PKGBASE} exists in $$viewname view - package $$pkg ***"; \
			${ECHO} "*** Not hoisting ${PKGNAME} into $$viewname view"; \
			continue ;;					\
		esac;							\
		${ECHO} "=> Performing package view overwrite check for ${PKGNAME} in $$viewname view"; \
		dups=`${SETENV} PLIST_IGNORE_FILES="${_PLIST_IGNORE_FILES}" ${PKG_VIEW} --view=$$v check ${PKGNAME} || ${TRUE}`; \
		case "$$dups" in					\
		"")	;;						\
		*)	${ECHO} "***********************************************************"; \
			${ECHO} "**** The following symbolic links will be overwritten *****"; \
			for f in $$dups; do				\
				${LS} -l ${LOCALBASE}/$$v/$$f;		\
			done;						\
			${ECHO} "***********************************************************"; \
			;;						\
		esac;							\
		${ECHO} "=> Linking package into $$viewname view";	\
		${SETENV} PLIST_IGNORE_FILES="${_PLIST_IGNORE_FILES}" ${PKG_VIEW} --view=$$v add ${PKGNAME}; \
	done
.endif

.PHONY: remove-views
remove-views: do-su-remove-views

.PHONY: do-su-remove-views
do-su-remove-views:
	@${ECHO_MSG} "${_PKGSRC_IN}> Removing ${PKGNAME} from views"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	realtarget="real-su-remove-views";				\
	action="remove-views";						\
	${_SU_TARGET}

.PHONY: real-su-remove-views
real-su-remove-views:
.if (${PKG_INSTALLATION_TYPE} == "pkgviews") && defined(PKGVIEWS)
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for v in ${PKGVIEWS}; do					\
		case "$$v" in						\
		"")	dbdir=${PKG_DBDIR}; viewname=standard ;;	\
		*)	dbdir=${LOCALBASE}/$$v/.dbdir; viewname=$$v ;;	\
		esac;							\
		${ECHO} "=> Removing package from $$viewname view";	\
		${SETENV} PLIST_IGNORE_FILES="${_PLIST_IGNORE_FILES}" ${PKG_VIEW} --view=$$v delete ${PKGNAME}; \
	done
.endif

.include "../../mk/bsd.pkg.data.mk"
.include "../../mk/subst.mk"

#
# For bulk build targets (bulk-install, bulk-package), the
# BATCH variable must be set in /etc/mk.conf:
#
.if defined(BATCH)
.  include "../../mk/bulk/bsd.bulk-pkg.mk"
.endif
