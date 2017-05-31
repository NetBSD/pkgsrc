#	$NetBSD: bsd.pkg.mk,v 1.2024 2017/05/31 22:56:41 jlam Exp $
#
# This file is in the public domain.
#
# Please see the pkgsrc/doc/guide manual for details on the
# variables used in this make file template.
#
# Default sequence for "all" is:
#
#    bootstrap-depends
#    fetch
#    checksum
#    depends
#    tools
#    extract
#    patch
#    wrapper
#    configure
#    build
#

.include "misc/common.mk"

############################################################################
# Transform package Makefile variables and set defaults
# This is the early set used directly or indirectly in
# the phase variables.
############################################################################

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
PKGVERSION_NOREV=	${PKGNAME_NOREV:C/^.*-//}

# Fail-safe in the case of circular dependencies
.if defined(_PKGSRC_DEPS) && defined(PKGNAME) && !empty(_PKGSRC_DEPS:M${PKGNAME})
PKG_FAIL_REASON+=	"Circular dependency detected"
.endif

####

############################################################################
# Allow various phases to define the default variables
############################################################################
.if defined(EMUL_PLATFORMS) && !empty(EMUL_PLATFORMS)
.  include "emulator/emulator.mk"
.endif

.include "features/features.mk"

.include "pkgformat/bsd.pkgformat-vars.mk"
.include "check/bsd.check-vars.mk"
.include "depends/bsd.depends-vars.mk"
.include "fetch/bsd.fetch-vars.mk"
.include "checksum/bsd.checksum-vars.mk"
.include "extract/bsd.extract-vars.mk"
.include "patch/bsd.patch-vars.mk"
.include "configure/bsd.configure-vars.mk"
.include "build/bsd.build-vars.mk"
.include "install/bsd.install-vars.mk"

.include "bsd.pkg.error.mk"

.include "bsd.hacks.mk"

############################################################################
# Transform package Makefile variables and set defaults
############################################################################

MKCRYPTO?=		YES	# build crypto packages by default

##### Others

BUILD_DEPENDS?=		# empty
COMMENT?=		(no description)
DEPENDS?=		# empty
DESCR_SRC?=		${PKGDIR}/DESCR
INTERACTIVE_STAGE?=	none
.if defined(OWNER)
MAINTAINER=${OWNER}
.else
MAINTAINER?=		pkgsrc-users@NetBSD.org
.endif
PKGWILDCARD?=		${PKGBASE}-[0-9]*
TOOL_DEPENDS?=		# empty
.if defined(GITHUB_TAG)
WRKSRC?=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG:C/^v//}
.else
WRKSRC?=		${WRKDIR}/${DISTNAME:U${PKGNAME_NOREV}}
.endif

# Override for SU_CMD user check
_IS_ROOT_CMD?=		${TEST}	`${ID} -u` = `${ID} -u ${_SU_ROOT_USER}`
_SU_ROOT_USER?=		${ROOT_USER}
REAL_ROOT_USER?=	${ROOT_USER}
REAL_ROOT_GROUP?=	${ROOT_GROUP}

.if (defined(INSTALL_UNSTRIPPED) && !empty(INSTALL_UNSTRIPPED:M[yY][eE][sS]))
_INSTALL_UNSTRIPPED=	# set (flag used by platform/*.mk)
.endif

##### Transform USE_* into dependencies

.include "bsd.pkg.use.mk"

############################################################################
# Sanity checks
############################################################################

.if defined(BUILDLINK_DEPTH) || defined(BUILDLINK_PACKAGES) || \
    defined(BUILDLINK_DEPENDS) || defined(BUILDLINK_ORDER)
PKG_FAIL_REASON+=	"Out-dated buildlink3.mk detected, please update"
.endif

.if !defined(CATEGORIES)
PKG_FAIL_REASON+='CATEGORIES are mandatory.'
.endif

.if !defined(PKGNAME) && !defined(DISTNAME)
PKG_FAIL_REASON+='PKGNAME and/or DISTNAME are mandatory.'
.endif

.if defined(PKG_PATH)
PKG_FAIL_REASON+='Please unset PKG_PATH before doing pkgsrc work!'
.endif

# Allow variables to be set on a per-OS basis
OPSYSVARS+=	CFLAGS CXXFLAGS CPPFLAGS LDFLAGS LIBS
OPSYSVARS+=	CMAKE_ARGS CONFIGURE_ARGS CONFIGURE_ENV
OPSYSVARS+=	BUILDLINK_TRANSFORM SUBST_CLASSES
OPSYSVARS+=	BUILD_TARGET MAKE_ENV MAKE_FLAGS USE_TOOLS
.for _var_ in ${OPSYSVARS:O}
.  if defined(${_var_}.${OPSYS})
${_var_}+=	${${_var_}.${OPSYS}}
.  elif defined(${_var_}.*)
${_var_}+=	${${_var_}.*}
.  endif
.endfor

CPPFLAGS+=	${CPP_PRECOMP_FLAGS}

# To sanitise environment set PKGSRC_SETENV=${SETENV} -i
# This will however cause build failures (e.g. "www/firefox"). Settings
# like "ALLOW_VULNERABLE_PACKAGES" will also not be correctly passed
# to dependence builds.
PKGSRC_SETENV?=	${SETENV}

ALL_ENV+=	CC=${CC:Q}
ALL_ENV+=	CFLAGS=${CFLAGS:M*:Q}
ALL_ENV+=	CPPFLAGS=${CPPFLAGS:M*:Q}
ALL_ENV+=	CXX=${CXX:Q}
ALL_ENV+=	CXXFLAGS=${CXXFLAGS:M*:Q}
ALL_ENV+=	COMPILER_RPATH_FLAG=${COMPILER_RPATH_FLAG:Q}
ALL_ENV+=	F77=${FC:Q}
ALL_ENV+=	FC=${FC:Q}
ALL_ENV+=	FFLAGS=${FFLAGS:M*:Q}
ALL_ENV+=	LANG=C
ALL_ENV+=	LC_ALL=C
ALL_ENV+=	LC_COLLATE=C
ALL_ENV+=	LC_CTYPE=C
ALL_ENV+=	LC_MESSAGES=C
ALL_ENV+=	LC_MONETARY=C
ALL_ENV+=	LC_NUMERIC=C
ALL_ENV+=	LC_TIME=C
ALL_ENV+=	LDFLAGS=${LDFLAGS:M*:Q}
ALL_ENV+=	LINKER_RPATH_FLAG=${LINKER_RPATH_FLAG:Q}
ALL_ENV+=	PATH=${PATH:Q}:${LOCALBASE}/bin:${X11BASE}/bin
ALL_ENV+=	PREFIX=${PREFIX}
ALL_ENV+=	MAKELEVEL=0
ALL_ENV+=	CONFIG_SITE=

# This variable can be added to MAKE_ENV to ease installation of packages
# that use BSD-style Makefiles.
BSD_MAKE_ENV=	BINOWN=${BINOWN} BINGRP=${BINGRP}
BSD_MAKE_ENV+=	GAMEOWN=${GAMEOWN} GAMEGRP=${GAMEGRP}
BSD_MAKE_ENV+=	MANOWN=${MANOWN} MANGRP=${MANGRP}
BSD_MAKE_ENV+=	SHAREOWN=${SHAREOWN} SHAREGRP=${SHAREGRP}
BSD_MAKE_ENV+=	DOCOWN=${DOCOWN} DOCGRP=${DOCGRP}
BSD_MAKE_ENV+=	BINMODE=${BINMODE} NONBINMODE=${NONBINMODE}
BSD_MAKE_ENV+=	BINDIR=${PREFIX}/bin
BSD_MAKE_ENV+=	INCSDIR=${PREFIX}/include
BSD_MAKE_ENV+=	LIBDIR=${PREFIX}/lib
BSD_MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
BSD_MAKE_ENV+=	STRIPFLAG=${_STRIPFLAG_INSTALL:Q}
BSD_MAKE_ENV+=	MANINSTALL=${MANINSTALL:Q}
BSD_MAKE_ENV+=	MKCATPAGES=${MKCATPAGES:Q}
BSD_MAKE_ENV+=	MKHTML=no

_BUILD_DEFS=		${BUILD_DEFS}
_BUILD_DEFS+=		LOCALBASE
_BUILD_DEFS+=		PKGGNUDIR
_BUILD_DEFS+=		PKGINFODIR
_BUILD_DEFS+=		PKGMANDIR
_BUILD_DEFS+=		_USE_DESTDIR

# Store the result in the +BUILD_INFO file so we can query for the build
# options using "pkg_info -Q PKG_OPTIONS <pkg>".
#
.if defined(PKG_SUPPORTED_OPTIONS) && defined(PKG_OPTIONS)
_BUILD_DEFS+=            PKG_OPTIONS
.endif

# Store the build options for multi-packages, i.e. packages that can
# be built with multiple versions of Apache, Python, Ruby, PHP etc.
#
.if defined(MULTI)
_BUILD_DEFS+=            MULTI
.endif

# ZERO_FILESIZE_P exits with a successful return code if the given file
#	has zero length.
# NONZERO_FILESIZE_P exits with a successful return code if the given file
#	has nonzero length.
#
_ZERO_FILESIZE_P=	${AWK} 'END { exit (NR > 0) ? 1 : 0; }'
_NONZERO_FILESIZE_P=	${AWK} 'END { exit (NR > 0) ? 0 : 1; }'

# Automatically increase process limit where necessary for building.
_ULIMIT_CMD=		${UNLIMIT_RESOURCES:@_lim_@${ULIMIT_CMD_${_lim_}};@}

_NULL_COOKIE=		${WRKDIR}/.null

# Miscellaneous overridable commands:
SHCOMMENT?=		${ECHO_MSG} >/dev/null '***'

LIBABISUFFIX?=

TOUCH_FLAGS?=		-f

# A few aliases for *-install targets
INSTALL=		${TOOLS_INSTALL}	# XXX override sys.mk
INSTALL_PROGRAM?= 	\
	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_GAME?=		\
	${INSTALL} ${COPY} ${_STRIPFLAG_INSTALL} -o ${GAMEOWN} -g ${GAMEGRP} -m ${GAMEMODE}
INSTALL_SCRIPT?= 	\
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_LIB?= 		\
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_DATA?= 		\
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE}
INSTALL_GAME_DATA?= 	\
	${INSTALL} ${COPY} -o ${GAMEOWN} -g ${GAMEGRP} -m ${GAMEDATAMODE}
INSTALL_MAN?= 		\
	${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m ${MANMODE}
INSTALL_PROGRAM_DIR?= 	\
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${PKGDIRMODE}
INSTALL_GAME_DIR?=		\
	${INSTALL} -d -o ${GAMEOWN} -g ${GAMEGRP} -m ${GAMEDIRMODE}
INSTALL_SCRIPT_DIR?= 	\
	${INSTALL_PROGRAM_DIR}
INSTALL_LIB_DIR?= 	\
	${INSTALL_PROGRAM_DIR}
INSTALL_DATA_DIR?= 	\
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${PKGDIRMODE}
INSTALL_MAN_DIR?= 	\
	${INSTALL} -d -o ${MANOWN} -g ${MANGRP} -m ${PKGDIRMODE}

INSTALL_MACROS=	BSD_INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}		\
		BSD_INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}			\
		BSD_INSTALL_LIB=${INSTALL_LIB:Q}			\
		BSD_INSTALL_DATA=${INSTALL_DATA:Q}			\
		BSD_INSTALL_MAN=${INSTALL_MAN:Q}			\
		BSD_INSTALL=${INSTALL:Q}				\
		BSD_INSTALL_PROGRAM_DIR=${INSTALL_PROGRAM_DIR:Q}	\
		BSD_INSTALL_SCRIPT_DIR=${INSTALL_SCRIPT_DIR:Q}		\
		BSD_INSTALL_LIB_DIR=${INSTALL_LIB_DIR:Q}		\
		BSD_INSTALL_DATA_DIR=${INSTALL_DATA_DIR:Q}		\
		BSD_INSTALL_MAN_DIR=${INSTALL_MAN_DIR:Q}		\
		BSD_INSTALL_GAME=${INSTALL_GAME:Q}			\
		BSD_INSTALL_GAME_DATA=${INSTALL_GAME_DATA:Q}		\
		BSD_INSTALL_GAME_DIR=${INSTALL_GAME_DIR:Q}
MAKE_ENV+=	${INSTALL_MACROS:M*}
SCRIPTS_ENV+=	${INSTALL_MACROS:M*}

# If pkgsrc is supposed to ensure that tests are run before installation
# of the package, then the build targets should be "build test", otherwise
# just "build" suffices.
#
.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
_PKGSRC_BUILD_TARGETS=	build test
.else
_PKGSRC_BUILD_TARGETS=	build
.endif

# OVERRIDE_DIRDEPTH represents the common directory depth under
#	${WRKSRC} up to which we find the files that need to be
#	overridden.  By default, we search two levels down, i.e.,
#	*/*/file.
#
OVERRIDE_DIRDEPTH?=	2

# Handle alternatives
#
.include "alternatives.mk"

# Handle alternative init systems
#
.if ${INIT_SYSTEM} == "smf"
.  include "smf.mk"
.endif

# Define SMART_MESSAGES in /etc/mk.conf for messages giving the tree
# of dependencies for building, and the current target.
_PKGSRC_IN?=		===${SMART_MESSAGES:D> ${.TARGET} [${PKGNAME}${_PKGSRC_DEPS}] ===}

# Used to print all the '===>' style prompts - override this to turn them off.
ECHO_MSG?=		${ECHO}
PHASE_MSG?=		${ECHO_MSG} ${_PKGSRC_IN:Q}\>
STEP_MSG?=		${ECHO_MSG} "=>"
INFO_MSG?=		${ECHO_MSG} "INFO:"
WARNING_MSG?=		${ECHO_MSG} 1>&2 "WARNING:"
ERROR_MSG?=		${ECHO_MSG} 1>&2 "ERROR:"
FAIL_MSG?=		${FAIL} ${ERROR_MSG}

WARNING_CAT?=		${SED} -e "s|^|WARNING: |" 1>&2
ERROR_CAT?=		${SED} -e "s|^|ERROR: |" 1>&2

# How to do nothing.  Override if you, for some strange reason, would rather
# do something.
DO_NADA?=		${TRUE}

# the FAIL command executes its arguments and then exits with a non-zero
# status.
FAIL?=			${SH} ${PKGSRCDIR}/mk/scripts/fail

#
# Config file related settings - see doc/pkgsrc.txt
#
PKG_SYSCONFVAR?=	${PKGBASE}
PKG_SYSCONFSUBDIR?=	# empty
PKG_SYSCONFBASEDIR=	${PKG_SYSCONFBASE}
.if empty(PKG_SYSCONFSUBDIR)
DFLT_PKG_SYSCONFDIR:=	${PKG_SYSCONFBASEDIR}
.else
DFLT_PKG_SYSCONFDIR:=	${PKG_SYSCONFBASEDIR}/${PKG_SYSCONFSUBDIR}
.endif
PKG_SYSCONFDIR=		${DFLT_PKG_SYSCONFDIR}
.if defined(PKG_SYSCONFDIR.${PKG_SYSCONFVAR})
PKG_SYSCONFDIR=		${PKG_SYSCONFDIR.${PKG_SYSCONFVAR}}
PKG_SYSCONFBASEDIR=	${PKG_SYSCONFDIR.${PKG_SYSCONFVAR}}
.endif
PKG_SYSCONFDIR_PERMS?=	${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755

ALL_ENV+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}
_BUILD_DEFS+=		PKG_SYSCONFBASEDIR PKG_SYSCONFDIR

# These are all of the tools use by pkgsrc Makefiles.  This should
# eventually be split up into lists of tools required by different
# phases of a pkgsrc build.
#
USE_TOOLS+=								\
	[ awk basename cat chgrp chmod chown cmp cp cut dirname echo	\
	egrep env false fgrep find grep head hostname id install ln ls	\
	mkdir mv printf pwd rm rmdir sed sh sort			\
	tail test touch tr true wc xargs

# bsd.wrapper.mk
USE_TOOLS+=	expr

# INSTALL/DEINSTALL script framework
.include "pkginstall/bsd.pkginstall.mk"

# Locking
.include "internal/locking.mk"

# Tools
.include "tools/bsd.tools.mk"

# Barrier
.include "bsd.pkg.barrier.mk"

# Unprivileged builds
.include "unprivileged.mk"

# If NO_BUILD is defined, default to not needing a compiler.
.if defined(NO_BUILD)
USE_LANGUAGES?=		# empty
.endif

# Get the proper dependencies and set the PATH to use the compiler
# named in PKGSRC_COMPILER.
#
.include "compiler.mk"

#Fake up a home directory
WRAPPER_TARGETS+=	fake-home
FAKEHOMEDIR=		${WRKDIR}/.home
ALL_ENV+=		HOME=${FAKEHOMEDIR}
.PHONY: fake-home
fake-home: ${FAKEHOMEDIR}
${FAKEHOMEDIR}:
	${RUN} ${MKDIR} ${.TARGET}

# Use C-based wrappers or legacy shell versions.
.if ${_USE_CWRAPPERS} == "yes"
.include "cwrappers.mk"
.else
.include "wrapper/bsd.wrapper.mk"
.endif

.if defined(ABI_DEPENDS) || defined(BUILD_ABI_DEPENDS)
.  if !empty(USE_ABI_DEPENDS:M[yY][eE][sS])
DEPENDS+=		${ABI_DEPENDS}
BUILD_DEPENDS+=		${BUILD_ABI_DEPENDS}
.  else
_BUILD_DEFS+=		USE_ABI_DEPENDS
.  endif
.endif

.if !defined(_PATH_ORIG)
_PATH_ORIG:=		${PATH}
MAKEFLAGS+=		_PATH_ORIG=${_PATH_ORIG:Q}
.endif

_PATH_COMPONENTS=	${PREPEND_PATH:[-1..1]} ${_PATH_ORIG:C,:, ,}
PATH=	${_PATH_COMPONENTS:ts:}

################################################################
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
################################################################
.if ${X11_TYPE} == "xorg"
PKG_FAIL_REASON+=	"Support for X11_TYPE=xorg was removed."
PKG_FAIL_REASON+=	"Please switch to X11_TYPE=modular."
X11_TYPE:=		native
X11BASE:=		/usr
.endif

.if !defined(NO_SKIP)
.  if (defined(NO_BIN_ON_CDROM) && defined(FOR_CDROM))
PKG_SKIP_REASON+= "${PKGNAME} may not be placed in binary form on a CDROM:" \
         "    "${NO_BIN_ON_CDROM:Q}
.  endif
.  if (defined(NO_SRC_ON_CDROM) && defined(FOR_CDROM))
PKG_SKIP_REASON+= "${PKGNAME} may not be placed in source form on a CDROM:" \
         "    "${NO_SRC_ON_CDROM:Q}
.  endif
.  if (defined(RESTRICTED) && defined(NO_RESTRICTED))
PKG_SKIP_REASON+= "${PKGNAME} is restricted:" \
	 "    "${RESTRICTED:Q}
.  endif
.  if !(${MKCRYPTO} == "YES" || ${MKCRYPTO} == yes)
.    if defined(CRYPTO)
PKG_SKIP_REASON+= "${PKGNAME} may not be built, because it utilizes strong cryptography"
.    endif
.  endif
.  if defined(USE_X11) && (${X11_TYPE} == "native") && !exists(${X11BASE})
PKG_FAIL_REASON+= "${PKGNAME} uses X11, but ${X11BASE} not found"
.  endif
.  if defined(BROKEN)
PKG_FAIL_REASON+= "${PKGNAME} is marked as broken:" ${BROKEN:Q}
.  endif

.include "license.mk"

#
# Check for packages broken or inappropriate on this platform.
# Set __PLATFORM_OK and __PLATFORM_WORKS only if the platform passes
# both the NOT_FOR/ONLY_FOR and BROKEN_ON lists (respectively).
#

# 1. BROKEN_EXCEPT_ON_PLATFORM
.  if defined(BROKEN_EXCEPT_ON_PLATFORM) && !empty(BROKEN_EXCEPT_ON_PLATFORM)
.    for __tmp__ in ${BROKEN_EXCEPT_ON_PLATFORM}
.      if ${MACHINE_PLATFORM:M${__tmp__}} != ""
__PLATFORM_WORKS?=	yes
.      endif	# MACHINE_PLATFORM
.    endfor	# __tmp__
.  else	# !BROKEN_EXCEPT_ON_PLATFORM
__PLATFORM_WORKS?=	yes
.  endif	# BROKEN_EXCEPT_ON_PLATFORM

# 2. ONLY_FOR_PLATFORM
.  if defined(ONLY_FOR_PLATFORM) && !empty(ONLY_FOR_PLATFORM)
.    for __tmp__ in ${ONLY_FOR_PLATFORM}
.      if ${MACHINE_PLATFORM:M${__tmp__}} != ""
__PLATFORM_OK?=	yes
.      endif	# MACHINE_PLATFORM
.    endfor	# __tmp__
.  else	# !ONLY_FOR_PLATFORM
__PLATFORM_OK?=	yes
.  endif	# ONLY_FOR_PLATFORM

# 3. BROKEN_ON_PLATFORM
.  for __tmp__ in ${BROKEN_ON_PLATFORM}
.    if ${MACHINE_PLATFORM:M${__tmp__}} != ""
.      undef __PLATFORM_WORKS
.    endif	# MACHINE_PLATFORM
.  endfor	# __tmp__

# 4. NOT_FOR_PLATFORM
.  for __tmp__ in ${NOT_FOR_PLATFORM}
.    if ${MACHINE_PLATFORM:M${__tmp__}} != ""
.      undef __PLATFORM_OK
.    endif	# MACHINE_PLATFORM
.  endfor	# __tmp__

# Check OK (NOT_FOR/ONLY_FOR) before WORKS (BROKEN_ON)
.  if !defined(__PLATFORM_OK)
PKG_SKIP_REASON+= "${PKGNAME} is not available for ${MACHINE_PLATFORM}"
.  endif	# !__PLATFORM_OK
.  if !defined(__PLATFORM_WORKS)
PKG_FAIL_REASON+= "${PKGNAME} is marked broken on ${MACHINE_PLATFORM}"
.  endif	# !__PLATFORM_WORKS

.endif # NO_SKIP

# Add these defs to the ones dumped into +BUILD_DEFS
_BUILD_DEFS+=	PKGPATH
_BUILD_DEFS+=	OPSYS OS_VERSION MACHINE_ARCH MACHINE_GNU_ARCH
_BUILD_DEFS+=	ABI
_BUILD_DEFS+=	CPPFLAGS CFLAGS FFLAGS LDFLAGS
_BUILD_DEFS+=	OBJECT_FMT LICENSE RESTRICTED
_BUILD_DEFS+=	NO_SRC_ON_FTP NO_SRC_ON_CDROM
_BUILD_DEFS+=	NO_BIN_ON_FTP NO_BIN_ON_CDROM

.if defined(OSVERSION_SPECIFIC)
_BUILD_DEFS+=	OSVERSION_SPECIFIC
DEPENDS+=	osabi-${OPSYS}-${OS_VERSION}:../../pkgtools/osabi
.endif # OSVERSION_SPECIFIC

.for _pkg_ in ${_BUILTIN_PKGS}
.  if defined(USE_BUILTIN.${_pkg_}) && \
      !empty(USE_BUILTIN.${_pkg_}:M[yY][eE][sS]) && \
      defined(BUILTIN_PKG.${_pkg_}) && !empty(BUILTIN_PKG.${_pkg_})
BUILTIN_PKGS+=	${BUILTIN_PKG.${_pkg_}}
.  endif
.endfor
.if defined(BUILTIN_PKGS)
_BUILD_DEFS+=	BUILTIN_PKGS
.endif

.if defined(GLIBC_VERSION)
_BUILD_DEFS+=	GLIBC_VERSION
.endif # GLIBC_VERSION

.PHONY: all
.if !target(all)
all: ${_PKGSRC_BUILD_TARGETS}
.endif

.PHONY: makedirs
makedirs: ${WRKDIR} ${FAKEHOMEDIR}

${WRKDIR}:
.if !defined(KEEP_WRKDIR)
.  if ${WRKDIR_LOCKTYPE} != "none"
	${RUN} ${TEST} -f ${_WRKDIR_LOCKFILE} || ${RM} -fr ${WRKDIR}
.  endif
.endif
	${RUN} umask 077 && ${MKDIR} ${WRKDIR}

# Create a symlink from ${WRKDIR} to the package directory if
# CREATE_WRKDIR_SYMLINK is "yes".
#
CREATE_WRKDIR_SYMLINK?=	no

.if defined(WRKOBJDIR) && !empty(CREATE_WRKDIR_SYMLINK:M[Yy][Ee][Ss])
makedirs: ${.CURDIR}/${WRKDIR_BASENAME}
${.CURDIR}/${WRKDIR_BASENAME}:
.  if ${WRKDIR_LOCKTYPE} != "none"
	${RUN} ${TEST} -f ${_WRKDIR_LOCKFILE} || ${RM} -f ${.TARGET}
.  endif
	${RUN} \
	if ${LN} -s ${WRKDIR} ${.TARGET} 2>/dev/null; then		\
		${ECHO_MSG} "${.TARGET:T} -> ${WRKDIR}";		\
	fi
.endif

.include "pkgformat/bsd.pkgformat.mk"

.include "depends/bsd.depends.mk"
.include "check/bsd.check.mk"
.include "fetch/bsd.fetch.mk"
.include "checksum/bsd.checksum.mk"
.include "extract/bsd.extract.mk"
.include "patch/bsd.patch.mk"
.include "configure/bsd.configure.mk"
.include "build/bsd.build.mk"
.include "install/bsd.install.mk"
.include "package/bsd.package.mk"

.include "bsd.pkg.clean.mk"
.include "bsd.pkg.update.mk"

# su-target is a macro target that does just-in-time su-to-root before
# reinvoking the make process as root.  It acquires root privileges and
# invokes a new make process with the target named "su-${.TARGET}".
#
# MAKEFLAGS.su-${.TARGET}
#	The additional flags that are passed to the make process.
#
# PRE_CMD.su-${.TARGET}
#	Shell command executed before running the command that requires
#	root privileges.  This may "exit 0" to short-circuit the command
#	list and skip executing the command that requires the root
#	privileges.
#

_ROOT_CMD=	cd ${.CURDIR} &&					\
		${PKGSRC_SETENV} ${PKGSRC_MAKE_ENV}				\
			PATH=${_PATH_ORIG:Q}:${SU_CMD_PATH_APPEND:Q}	\
		${MAKE} ${MAKEFLAGS} _PKGSRC_BARRIER=yes		\
			PKG_DEBUG_LEVEL=${PKG_DEBUG_LEVEL:Q}		\
			${USE_CROSS_COMPILE:DUSE_CROSS_COMPILE=${USE_CROSS_COMPILE:Q}}	\
			su-${.TARGET} ${MAKEFLAGS.su-${.TARGET}}

.PHONY: su-target
su-target: .USE
	${RUN}${PRE_CMD.su-${.TARGET}:U${TRUE}};			\
	if ${_IS_ROOT_CMD}; then					\
		${_ROOT_CMD};						\
	else								\
		case ${PRE_ROOT_CMD:Q}"" in				\
		${TRUE:Q}"")	;;					\
		*) ${WARNING_MSG} "Running: "${PRE_ROOT_CMD:Q} ;;	\
		esac;							\
		${PRE_ROOT_CMD};					\
		${STEP_MSG} "Becoming \`\`${_SU_ROOT_USER}'' to make su-${.TARGET} (`${ECHO} ${SU_CMD} | ${AWK} '{ print $$1 }'`)"; \
		${SU_CMD} ${_ROOT_CMD:Q};				\
		${STEP_MSG} "Dropping \`\`${_SU_ROOT_USER}'' privileges.";	\
	fi

################################################################
# Some more targets supplied for users' convenience
################################################################

# Run pkglint:
.PHONY: lint
lint:
	${RUN} ${LOCALBASE}/bin/pkglint

# List of flags to pass to pkg_add(1) for bin-install:

BIN_INSTALL_FLAGS?= 	# -v
_BIN_INSTALL_FLAGS=	${BIN_INSTALL_FLAGS}
.if defined(_AUTOMATIC) && !empty(_AUTOMATIC:M[Yy][Ee][Ss])
_BIN_INSTALL_FLAGS+=	-A
.endif
_BIN_INSTALL_FLAGS+=	${PKG_ARGS_ADD}

_SHORT_UNAME_R=	${:!${UNAME} -r!:C@\.([0-9]*)[_.-].*@.\1@} # n.n[_.]anything => n.n

.include "install/bin-install.mk"

# Handle PaX flags
#
.include "pax.mk"

.PHONY: show-pkgtools-version
.if !target(show-pkgtools-version)
show-pkgtools-version:
	@${ECHO} ${PKGTOOLS_VERSION}
.endif

# show-var:
# show-vars:
# show-subdir-var:
#	Convenience targets, to display make variables from the command
#	line. Examples:
#
#	make show-var VARNAME=PKGNAME
#	make show-vars VARNAMES="PKGNAME PKGVERSION PKGREVISION"
#	make show-subdir-var VARNAME=DISTFILES
#
#	In category directories, show-var and show-vars descend
#	recursively into each subdirectory, printing the variables of
#	the individual packages. To show a variable from the category
#	itself, use show-subdir-var.
.PHONY: show-var
show-var:
	@${ECHO} ${${VARNAME}:Q}

.PHONY: show-vars
show-vars:
.for VARNAME in ${VARNAMES}
	@${ECHO} ${${VARNAME}:Q}
.endfor

# displays multiple variables as shell expressions
# VARS is space separated list of VARNAME:shellvarname
.PHONY: show-vars-eval
show-vars-eval:
.for var in ${VARS}
	@${ECHO} ${var:C/^.*://}="${${var:C/:.*$//}:Q}"
.endfor

LICENSE_FILE?=		${PKGSRCDIR}/licenses/${LICENSE}

.if !target(show-license)
show-license show-licence: .PHONY
	@license=${LICENSE:Q};						\
	license_file=${LICENSE_FILE:Q};					\
	pager=${PAGER:Q};						\
	case "$$pager" in "") pager=${CAT:Q};; esac;			\
	case "$$license" in "") exit 0;; esac;				\
	if ${TEST} -f "$$license_file"; then				\
		$$pager "$$license_file";				\
	else								\
		${ECHO} "Generic $$license information not available";	\
		${ECHO} "See the package description (pkg_info -d ${PKGNAME}) for more information."; \
	fi
.endif

# This target is defined in bsd.options.mk for packages that use
# the options framework.
.if !target(show-options)
.PHONY: show-options
show-options:
	@${ECHO} This package does not use the options framework.
.endif

# Depend is generally meaningless for arbitrary packages, but if someone wants
# one they can override this.  This is just to catch people who've gotten into
# the habit of typing `${MAKE} depend all install' as a matter of course.
#
.PHONY: depend
.if !target(depend)
depend:
.endif

# Same goes for tags
.PHONY: tags
.if !target(tags)
tags:
.endif

.include "plist/bsd.plist.mk"

.include "bsd.utils.mk"

.include "subst.mk"

# README generation code.
.include "bsd.pkg.readme.mk"

# Create a PKG_ERROR_HANDLER shell command for each class listed in
# PKG_ERROR_CLASSES.  The error handler is meant to be invoked within
# a make target.
#
.for _class_ in ${PKG_ERROR_CLASSES}
PKG_ERROR_HANDLER.${_class_}?=	{					\
		ec=$$?;							\
		for str in ${PKG_ERROR_MSG.${_class_}}; do		\
			${PHASE_MSG} "$$str";				\
		done;							\
		exit $$ec;						\
	}
.endfor

# Cache variables listed in MAKEVARS in a phase-specific "makevars.mk"
# file.  These variables are effectively passed to sub-make processes
# that are invoked on the same Makefile.
#
.for _phase_ in ${_ALL_PHASES}
${_MAKEVARS_MK.${_phase_}}: ${WRKDIR}
	${RUN}${RM} -f ${.TARGET}.tmp
.  for _var_ in ${MAKEVARS:O:u}
.    if defined(${_var_})
	${RUN}					\
	${ECHO} ${_var_}"=	"${${_var_}:Q} >> ${.TARGET}.tmp
.    endif
.  endfor
	${RUN}					\
	if ${TEST} -f ${.TARGET}.tmp; then				\
		( ${ECHO} ".if !defined(_MAKEVARS_MK)";			\
		  ${ECHO} "_MAKEVARS_MK=	defined";		\
		  ${ECHO} "";						\
		  ${CAT} ${.TARGET}.tmp;				\
		  ${ECHO} "";						\
		  ${ECHO} ".endif # _MAKEVARS_MK";			\
		) > ${.TARGET};						\
		${RM} -f ${.TARGET}.tmp;				\
	fi
	${RUN}${TOUCH} ${TOUCH_FLAGS} ${.TARGET}
.endfor

.if make(pbulk-index) || make(pbulk-index-item) || make(pbulk-save-wrkdir)
.include "pbulk/pbulk-index.mk"
.endif

.if defined(_OPSYS_REQUIRE_UAC_MANIFEST) && !empty(_OPSYS_REQUIRE_UAC_MANIFEST:M[Yy][Ee][Ss])
.  if defined(UAC_REQD_EXECS) && !empty(UAC_REQD_EXECS)
.include "misc/uac-manifest.mk"
.  endif
.endif

.if ${PKG_DEVELOPER:Uno} != "no"
.  include "misc/developer.mk"
.endif
.include "misc/show.mk"
.if make(debug)
.  include "bsd.pkg.debug.mk"
.endif
.include "misc/warnings.mk"
.if make(import)
.include "misc/import.mk"
.endif
.include "misc/can-be-built-here.mk"
