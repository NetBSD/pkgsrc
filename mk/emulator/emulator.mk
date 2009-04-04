# $NetBSD: emulator.mk,v 1.11 2009/04/04 12:16:45 rillig Exp $
#
# This file is included by bsd.pkg.mk.
#
# Package-settable variables:
#
# EMUL_REQD
#	List of required versions for different emulation types, e.g
#	suse>=10.0, netbsd>=1.2, etc.
#
# EMUL_MODULES.${EMUL_OPSYS}
#	List of modules of ${EMUL_OPSYS} that are used by the package.
#
#	Default value: undefined
#
# EMUL_PKG_FMT
#	Binary emulation packaging format requested by the package.
#	Possible values: any format listed in ${_EMUL_PKG_FMTS}.
#
#	Default value: plain
#
# Variables defined by this file:
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
#	Path relative to ${PREFIX} where the files and directories
#	are located, e.g. emul/linux.
#
# OPSYS_EMULDIR
#	Path through which the platform expects to find a "chroot"
#	installation of the files and directories, e.g. /emul/linux.
#
# EMULSUBDIRSLASH
#	Expands to either ${EMULSUBDIR}/lib or just lib depending on
#	whether EMULSUBDIR is empty or not.  It is meant to be used
#	in PLISTs and files where one wants to avoid "//" artifacts,
#	e.g., ${EMULSUBDIRSLASH}lib.
#
# Public targets:
#
# emul-fetch
#	This is a public target that fetches the distfiles for all
#	supported EMUL_PLATFORMs.
#
# emul-distinfo
#	This is a public target that generates a new distinfo file
#	that contains checksums for all supported EMUL_PLATFORMs.
#	This target should be run after the successful completion
#	of the ``emul-fetch'' target.
#
# Keywords: emulator, emulation, emul
#

.if empty(EMUL_PLATFORMS:M${EMUL_PLATFORM})
PKG_FAIL_REASON+=	"${PKGNAME} is not available for ${MACHINE_PLATFORM}"
.endif

.if ${EMUL_PLATFORM} == "none"
EMUL_DISTRO?=		none
EMULSUBDIR?=		# empty
EMULDIR?=		${PREFIX}
OPSYS_EMULDIR?=		# empty
.else
#
# The ${EMUL_OPSYS}.mk file included here should define the following
# variables either directly or indirectly:
#
#	EMUL_DISTRO, EMULSUBDIR, EMULDIR, OPSYS_EMULDIR
#
.  include "${EMUL_OPSYS}.mk"
.endif

# If we're doing true binary emulation, then file paths found in the
# package's binaries, libraries and scripts won't necessarily match the
# actual paths on the file system, so skip some path checks that are
# likely to fail.
#
.if empty(EMUL_DISTRO:Mnative-*)
CHECK_SHLIBS_SUPPORTED?=	no
CHECK_INTERPRETER_SKIP=		*
.endif

# We're not concerned about "portability" problems if we're using
# a package that requires binary emulation.
#
CHECK_PORTABILITY_SKIP=		*

# _EMUL_RUN_LDCONFIG
#	This is YesNo variable that is modified by makefiles in the
#	emulator framework.  This is used as the default value of
#	RUN_LDCONFIG by any package that uses the emulator framework.
#
#	Default value: no
#
_EMUL_RUN_LDCONFIG?=	no
RUN_LDCONFIG?=		${_EMUL_RUN_LDCONFIG}

FILES_SUBST+=		EMUL_PLATFORM=${EMUL_PLATFORM:Q}
FILES_SUBST+=		EMUL_OPSYS=${EMUL_OPSYS:Q}
FILES_SUBST+=		EMUL_ARCH=${EMUL_ARCH:Q}

PLIST_SUBST+=		EMUL_PLATFORM=${EMUL_PLATFORM:Q}
PLIST_SUBST+=		EMUL_OPSYS=${EMUL_OPSYS:Q}
PLIST_SUBST+=		EMUL_ARCH=${EMUL_ARCH:Q}

FILES_SUBST+=		EMULDIR=${EMULDIR:Q}
FILES_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}
FILES_SUBST+=		OPSYS_EMULDIR=${OPSYS_EMULDIR:Q}

PLIST_SUBST+=		EMULDIR=${EMULDIR:Q}
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}
PLIST_SUBST+=		OPSYS_EMULDIR=${OPSYS_EMULDIR:Q}

EMULSUBDIRSLASH=	${EMULSUBDIR:S/$/\//:C/^\/$//}
FILES_SUBST+=		EMULSUBDIRSLASH=${EMULSUBDIRSLASH:Q}
PLIST_SUBST+=		EMULSUBDIRSLASH=${EMULSUBDIRSLASH:Q}

# Add dependencies for each "module" that the package requests in
# EMUL_MODULES.${EMUL_OPSYS}.
#
.for _mod_ in ${EMUL_MODULES.${EMUL_OPSYS}}
.  if !defined(DEPENDS_${EMUL_DISTRO}.${_mod_})
PKG_FAIL_REASON+=       "${EMUL_DISTRO}: unknown module ${_mod_}"
.  else
DEPENDS+=               ${DEPENDS_${EMUL_DISTRO}.${_mod_}}
.  endif
.endfor

# _EMUL_PKG_FMTS
#	List of recognized binary emulation packaging formats that
#	packages may request.
#
_EMUL_PKG_FMTS=		plain
_EMUL_PKG_FMTS+=	rpm

EMUL_PKG_FMT?=		plain

.include "pkg-${EMUL_PKG_FMT}.mk"

.PHONY: emul-fetch
emul-fetch:
.for _platform_ in ${EMUL_PLATFORMS}
	${RUN} ${MAKE} ${MAKEFLAGS} fetch NO_SKIP=yes			\
		_BOOTSTRAP_VERBOSE= EMUL_PLATFORM=${_platform_}
.endfor

.PHONY: emul-distinfo
emul-distinfo:
	${RUN} ${RM} -f ${DISTINFO_FILE}.emul
	${RUN} ( ${ECHO} "$$""NetBSD""$$"; ${ECHO} "" )			\
		>> ${DISTINFO_FILE}.emul
.for _platform_ in ${EMUL_PLATFORMS}
	${RUN}								\
	( ${MAKE} ${MAKEFLAGS} distinfo NO_SKIP=yes			\
		ECHO_MSG=: EMUL_PLATFORM=${_platform_} &&		\
	  ${SED} "1,2d" ${DISTINFO_FILE} &&				\
	  ${RM} -f ${DISTINFO_FILE} ) >> ${DISTINFO_FILE}.emul
.endfor
	${RUN} ${RM} -f ${DISTINFO_FILE}
	${RUN} ${AWK} -f ${PKGSRCDIR}/mk/emulator/merge-distinfo.awk	\
		${DISTINFO_FILE}.emul > ${DISTINFO_FILE}
	${RUN} ${RM} -f ${DISTINFO_FILE}.emul
