# $NetBSD: haskell.mk,v 1.21 2020/06/21 22:21:02 rillig Exp $
#
# This Makefile fragment handles Haskell Cabal packages.
# See: http://www.haskell.org/cabal/
#
# Note to users:
#
#   * Users choose one favourite Haskell compiler. Though the only
#     compiler currently supported is GHC.
#
#   * You can't install a cabal package for more than one compilers
#     simultaneously. In the future, this limitation can possibly be
#     eliminated using the method used by
#     "../../lang/python/pyversion.mk".
#
# Note to package developers:
#
#   * This file must be included *before* "../../mk/bsd.pkg.mk", or
#     you'll get target-redefinition errors.
#
#   * PKGNAME will automatically be "hs-${DISTNAME}" unless you
#     explicitly declare it.
#
#   * If your package is on the HackageDB, MASTER_SITES and HOMEPAGE
#     can be omitted.
#
#   * Package configuration, building, installation, registration and
#     unregistration are fully automated. You usually don't need to do
#     anything special.
#
#   * When Haskell libraries depend on other Haskell libraries, they
#     MUST depend on, not build-depend on, such libraries. So if your
#     package installs a library, you MUST NOT set
#     BUILDLINK_DEPMETHOD.${PKG} to "build" in your buildlink3.mk
#     file. Reason:
#         1. Assume we have two libraries A and B, and B build-depends
#            on A.
#         2. We install package A.
#         3. We then install package B, which build-depends on A.
#         4. After that, a new upstream version of package A is
#            released. We therefore update package A to the new version.
#         5. Package B had a build-dependency on A, so pkgsrc assumes
#            that it's still safe to use package B without
#            recompilation of B. But in fact package B requires the
#            very version of package A which was available when
#            package B was compiled. So the installed package B is
#            completely broken at this time.
#
# Package-settable variables:
#
#   HASKELL_OPTIMIZATION_LEVEL
#       Description:
#           Optimization level for compilation.
#       Possible values:
#           0 1 2
#       Default value:
#           2
#
# User-settable variables:
#
#   HASKELL_COMPILER
#       Description:
#           The user's favourite Haskell compiler.
#       Possible values:
#           ghc
#       Default value:
#           ghc
#
#   HASKELL_ENABLE_SHARED_LIBRARY
#       Description:
#           Whether shared library should be built or not.
#       Possible values:
#           yes, no
#       Default value:
#           yes
#
#   HASKELL_ENABLE_LIBRARY_PROFILING
#       Description:
#           Whether profiling library should be built or not.
#       Possible values:
#           yes, no
#       Default value:
#           yes
#
#   HASKELL_ENABLE_HADDOCK_DOCUMENTATION
#       Description:
#           Whether haddock documentation should be built or not.
#       Possible values:
#           yes, no
#       Default value:
#           yes

.if !defined(HASKELL_MK)
HASKELL_MK=	# defined

.include "../../mk/bsd.fast.prefs.mk"


# Declare HASKELL_COMPILER as one of BUILD_DEFS variables. See
# ../../mk/misc/show.mk
BUILD_DEFS+=	HASKELL_COMPILER
BUILD_DEFS+=	HASKELL_ENABLE_SHARED_LIBRARY
BUILD_DEFS+=	HASKELL_ENABLE_LIBRARY_PROFILING
BUILD_DEFS+=	HASKELL_ENABLE_HADDOCK_DOCUMENTATION


# Declarations for ../../mk/misc/show.mk
_VARGROUPS+=	haskell
_USER_VARS.haskell= \
	HASKELL_ENABLE_SHARED_LIBRARY \
	HASKELL_ENABLE_LIBRARY_PROFILING \
	HASKELL_ENABLE_HADDOCK_DOCUMENTATION
_SYS_VARS.haskell= \
	PKGNAME DISTNAME MASTER_SITES MASTER_SITE_HASKELL_HACKAGE \
	HOMEPAGE UNLIMIT_RESOURCES PREFIX
_DEF_VARS.haskell= \
	HASKELL_OPTIMIZATION_LEVEL \
	HASKELL_PKG_NAME \
	_DISTBASE \
	_DISTVERSION \
	_GHC_BIN \
	_GHC_PKG_BIN \
	_GHC_VERSION \
	_GHC_VERSION_CMD \
	_GHC_VERSION_FULL \
	_HASKELL_BIN \
	_HASKELL_PKG_BIN \
	_HASKELL_PKG_DESCR_FILE \
	_HASKELL_PKG_ID_FILE \
	_HASKELL_VERSION
_IGN_VARS.haskell= \
	USE_TOOLS _*

# PKGNAME is usually named after DISTNAME.
PKGNAME?=	hs-${DISTNAME}

# Default value of MASTER_SITES.
_DISTBASE?=	${DISTNAME:C/-[^-]*$//}
_DISTVERSION?=	${DISTNAME:C/^.*-//}
MASTER_SITES?=	${MASTER_SITE_HASKELL_HACKAGE:=${DISTNAME}/}

# Default value of HOMEPAGE.
HOMEPAGE?=	http://hackage.haskell.org/package/${_DISTBASE}

# Cabal packages may use pkg-config, but url2pkg can't detect
# that. (PHO: I think that should be handled by url2pkg (2009-05-20))
USE_TOOLS+=	pkg-config

# GHC can be a memory hog, so don't apply regular limits.
UNLIMIT_RESOURCES+=	datasize virtualsize

# Default value of HASKELL_OPTIMIZATION_LEVEL
HASKELL_OPTIMIZATION_LEVEL?=		2

# Default value of HASKELL_ENABLE_SHARED_LIBRARY
HASKELL_ENABLE_SHARED_LIBRARY?=		yes

# Default value of HASKELL_ENABLE_LIBRARY_PROFILING
HASKELL_ENABLE_LIBRARY_PROFILING?=	yes

# Default value of HASKELL_ENABLE_HADDOCK_DOCUMENTATION
HASKELL_ENABLE_HADDOCK_DOCUMENTATION?=	yes

# Compiler specific variables and targets.
.if ${HASKELL_COMPILER} == "ghc"

# Add dependency on GHC.
.include "../../lang/ghc88/buildlink3.mk"

# Tools
_GHC_BIN=		${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/ghc
_GHC_PKG_BIN=		${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/ghc-pkg
_HASKELL_BIN=		${_GHC_BIN} # Expose to the outer scope.
_HASKELL_PKG_BIN=	${_GHC_PKG_BIN} # Expose to the outer scope.

# Determine GHC version.
_GHC_VERSION_CMD=	${_GHC_BIN} -V 2>/dev/null | ${CUT} -d ' ' -f 8
_GHC_VERSION=		${_GHC_VERSION_CMD:sh}
_GHC_VERSION_FULL=	ghc-${_GHC_VERSION}
_HASKELL_VERSION=	${_GHC_VERSION_FULL} # Expose to the outer scope.

# Determine GHC shlib suffix
_GHC_SHLIB_SUFFIX.dylib=	dylib
_GHC_SHLIB_SUFFIX=		${_GHC_SHLIB_SUFFIX.${SHLIB_TYPE}:Uso}
_HASKELL_SHLIB_SUFFIX=		${_GHC_SHLIB_SUFFIX}

# GHC requires C compiler.
USE_LANGUAGES+=	c

# Declarations for ../../mk/configure/configure.mk
CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${_GHC_BIN:Q}
CONFIGURE_ARGS+=	--with-hc-pkg=${_GHC_PKG_BIN:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
.endif # ${HASKELL_COMPILER}

# Shared libraries
.if ${HASKELL_ENABLE_SHARED_LIBRARY} == "yes"
CONFIGURE_ARGS+=	--enable-shared --enable-executable-dynamic
.else
CONFIGURE_ARGS+=	--disable-shared --disable-executable-dynamic
.endif

# Library profiling
.if ${HASKELL_ENABLE_LIBRARY_PROFILING} == "yes"
CONFIGURE_ARGS+=	--enable-library-profiling
.else
CONFIGURE_ARGS+=	--disable-library-profiling
.endif

# Haddock documentations
.if ${HASKELL_ENABLE_HADDOCK_DOCUMENTATION} == "yes"
CONFIGURE_ARGS+=	--with-haddock=${BUILDLINK_PREFIX.ghc:Q}/bin/haddock
.endif

# Optimization
CONFIGURE_ARGS+=	-O${HASKELL_OPTIMIZATION_LEVEL}

.if !exists(${PKGDIR}/PLIST)
_HS_PLIST_STATUS=	missing
.elif ${${GREP} HS_INTF ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	lib-ok
.elif !${${GREP} "/package-id" ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	plain
.else
_HS_PLIST_STATUS=	outdated
.endif

# Starting from GHC 7.10 (or 7.8?), packages are installed in directories
# with a hashed name, which makes it a bit more complicated to generate
# the PLIST.
#
.if ${_HS_PLIST_STATUS} == lib-ok || ${_HS_PLIST_STATUS} == missing

_HASKELL_PL_INTF=	${_HASKELL_PKG_ID_FILE:H:S,^${PREFIX}/,,}
_HASKELL_PL_IMPL_AWK=	prev == "import-dirs:" { dir = $$1; exit }
_HASKELL_PL_IMPL_AWK+=	{ prev = $$0 }
_HASKELL_PL_IMPL_AWK+=	END { print(dir ? dir : "never_match_this") }
_HASKELL_PL_IMPL_CMD=	${AWK} '${_HASKELL_PL_IMPL_AWK}' ${DESTDIR}${_HASKELL_PKG_DESCR_FILE}
_HASKELL_PL_IMPL=	${_HASKELL_PL_IMPL_CMD:sh:S,^${PREFIX}/,,}
_HASKELL_PL_DOCS=	${_HASKELL_PL_IMPL:S,^lib,share/doc,:C,-[A-Za-z0-9]*$,,}
_HASKELL_PL_PLATFORM=	${_HASKELL_PL_IMPL:H:T:S,^.$,never_match_this,}
_HASKELL_PL_PKGID_CMD=	${CAT} ${DESTDIR}${_HASKELL_PKG_ID_FILE}
_HASKELL_PL_PKGID=	${_HASKELL_PL_PKGID_CMD:sh}
_HASKELL_PL_VER=	${_HASKELL_VERSION:S,-,,}

PLIST_SUBST+=		HS_INTF=${_HASKELL_PL_INTF}
PLIST_SUBST+=		HS_IMPL=${_HASKELL_PL_IMPL}
PLIST_SUBST+=		HS_DOCS=${_HASKELL_PL_DOCS}
PLIST_SUBST+=		HS_PLATFORM=${_HASKELL_PL_PLATFORM}
PLIST_SUBST+=		HS_PKGID=${_HASKELL_PL_PKGID}
PLIST_SUBST+=		HS_VER=${_HASKELL_PL_VER}
PRINT_PLIST_AWK+=	{ sub("^${_HASKELL_PL_INTF}",       "$${HS_INTF}") }
PRINT_PLIST_AWK+=	{ sub("^${_HASKELL_PL_IMPL}",       "$${HS_IMPL}") }
PRINT_PLIST_AWK+=	{ sub("^${_HASKELL_PL_DOCS}",       "$${HS_DOCS}") }
PRINT_PLIST_AWK+=	{ sub("/${_HASKELL_PL_PLATFORM}/", "/$${HS_PLATFORM}/") }
PRINT_PLIST_AWK+=	{ sub( "${_HASKELL_PL_PKGID}",      "$${HS_PKGID}") }
PRINT_PLIST_AWK+=	{ sub( "${_HASKELL_PL_VER}",        "$${HS_VER}") }

HS_UPDATE_PLIST?=	no

.  if ${HS_UPDATE_PLIST} != no && ${_HS_PLIST_STATUS} == missing
GENERATE_PLIST+= 	${MAKE} print-PLIST > ${PKGDIR}/PLIST;
.  endif
.endif

.if ${_HS_PLIST_STATUS} == missing || ${_HS_PLIST_STATUS} == outdated
GENERATE_PLIST+= \
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} * \( -type f -o -type l \) | ${SORT};
PLIST_SRC=	# none, because the PLIST file is outdated or missing
.  if ${_HS_PLIST_STATUS} == outdated && ${HS_UPDATE_PLIST} == no
WARNINGS+=	"[haskell.mk] The PLIST format is outdated."
WARNINGS+=	"[haskell.mk] Set HS_UPDATE_PLIST=yes to update it automatically."
.  endif
.endif

# Define configure target. We might not have any working Haskell
# interpreter so compile Setup.?hs to a binary. Since dynamic linkage
# is much faster, we try it and then fall back to static linkage if
# that didn't work.
do-configure:
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC} && \
		( ${_HASKELL_BIN:Q} --make Setup -dynamic || \
			${_HASKELL_BIN:Q} --make Setup -static )
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC:Q} && \
		${SETENV} ${CONFIGURE_ENV} \
			./Setup configure ${PKG_VERBOSE:D-v} ${CONFIGURE_ARGS}

# Define build target. _MAKE_JOBS_N is defined in build/build.mk
do-build:
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC:Q} && \
		${SETENV} ${MAKE_ENV} \
		./Setup build ${PKG_VERBOSE:D-v} -j${_MAKE_JOBS_N}
.if ${HASKELL_ENABLE_HADDOCK_DOCUMENTATION} == "yes"
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC:Q} && \
		${SETENV} ${MAKE_ENV} \
		./Setup haddock ${PKG_VERBOSE:D-v}
.endif

# Define install target. We need installed-pkg-config to be installed
# for package registration (if any).
HASKELL_PKG_NAME?=		${DISTNAME}
_HASKELL_PKG_DESCR_DIR=		${PREFIX}/lib/${HASKELL_PKG_NAME}/${_HASKELL_VERSION}
_HASKELL_PKG_DESCR_FILE=	${_HASKELL_PKG_DESCR_DIR}/package-description
_HASKELL_PKG_ID_FILE=		${_HASKELL_PKG_DESCR_DIR}/package-id

INSTALLATION_DIRS+=		${_HASKELL_PKG_DESCR_DIR}
do-install:
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC} && \
		./Setup register ${PKG_VERBOSE:D-v} \
			--gen-pkg-config=dist/package-description \
			--print-ipid \
			> dist/package-id && \
		./Setup copy ${PKG_VERBOSE:D-v} --destdir=${DESTDIR:Q} && \
		if [ -f dist/package-description ]; then \
			${INSTALL_DATA} dist/package-description \
				${DESTDIR:Q}${_HASKELL_PKG_DESCR_FILE:Q}; \
			${INSTALL_DATA} dist/package-id \
				${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q}; \
		fi

# Define test target.
do-test:
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC} && \
		./Setup test ${PKG_VERBOSE:D-v}

# Substitutions for INSTALL and DEINSTALL.
FILES_SUBST+=	HASKELL_PKG_BIN=${_HASKELL_PKG_BIN}
FILES_SUBST+=	HASKELL_PKG_DESCR_FILE=${_HASKELL_PKG_DESCR_FILE}
FILES_SUBST+=	HASKELL_PKG_ID_FILE=${_HASKELL_PKG_ID_FILE}

INSTALL_TEMPLATES+=	../../mk/haskell/INSTALL.in
DEINSTALL_TEMPLATES+=	../../mk/haskell/DEINSTALL.in

# Only present these variables if the definitions can be extracted
# from the files in DESTDIR.
_HS_DESTDIR_DEF_VARS=	PLIST_SUBST PRINT_PLIST_AWK
_HS_DESTDIR_DEF_VARS+=	_HASKELL_PL_INTF
_HS_DESTDIR_DEF_VARS+=	_HASKELL_PL_IMPL
_HS_DESTDIR_DEF_VARS+=	_HASKELL_PL_DOCS
_HS_DESTDIR_DEF_VARS+=	_HASKELL_PL_PLATFORM
_HS_DESTDIR_DEF_VARS+=	_HASKELL_PL_PKGID
_HS_DESTDIR_DEF_VARS+=	_HASKELL_PL_VER
_DEF_VARS.haskell+=	${exists(${DESTDIR}${_HASKELL_PKG_DESCR_FILE}) :? ${_HS_DESTDIR_DEF_VARS} :}
_LISTED_VARS.haskell+=	PLIST_SUBST PRINT_PLIST_AWK

.endif # HASKELL_MK
