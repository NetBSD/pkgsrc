# $NetBSD: haskell.mk,v 1.26 2020/07/01 14:58:43 rillig Exp $
#
# This Makefile fragment handles Haskell Cabal packages.
# Package configuration, building, installation, registration and
# unregistration are fully automated.
# See https://www.haskell.org/cabal/.
#
# Package-settable variables:
#
# PKGNAME
#	Defaults to hs-${DISTNAME}.
#
# HOMEPAGE
# MASTER_SITES
#	Default to HackageDB URLs.
#
# HASKELL_OPTIMIZATION_LEVEL
#	Optimization level for compilation.
#
#	Possible values: 0 1 2
#       Default value: 2
#
# User-settable variables:
#
# HASKELL_ENABLE_SHARED_LIBRARY
#	Whether shared library should be built or not.
#
#	Possible values: yes, no
#       Default value: yes
#
# HASKELL_ENABLE_LIBRARY_PROFILING
#	Whether profiling library should be built or not.
#
#	Possible values: yes, no
#       Default value: yes
#
# HASKELL_ENABLE_HADDOCK_DOCUMENTATION
#	Whether haddock documentation should be built or not.
#
#	Possible values: yes, no
#       Default value: yes

.if !defined(HASKELL_MK)
HASKELL_MK=	# defined

.include "../../mk/bsd.fast.prefs.mk"

HS_UPDATE_PLIST?=	no

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
	_HASKELL_VERSION_CMD \
	_HASKELL_BIN \
	_HASKELL_PKG_BIN \
	_HASKELL_PKG_DESCR_FILE \
	_HASKELL_PKG_ID_FILE \
	_HASKELL_VERSION
_IGN_VARS.haskell= \
	USE_TOOLS _*

PKGNAME?=	hs-${DISTNAME}
MASTER_SITES?=	${MASTER_SITE_HASKELL_HACKAGE:=${DISTNAME}/}
HOMEPAGE?=	http://hackage.haskell.org/package/${DISTNAME:C/-[^-]*$//}

# Cabal packages may use pkg-config, but url2pkg can't detect
# that. (PHO: I think that should be handled by url2pkg (2009-05-20))
USE_TOOLS+=	pkg-config

# GHC can be a memory hog, so don't apply regular limits.
UNLIMIT_RESOURCES+=	datasize virtualsize

HASKELL_OPTIMIZATION_LEVEL?=		2
HASKELL_ENABLE_SHARED_LIBRARY?=		yes
HASKELL_ENABLE_LIBRARY_PROFILING?=	yes
HASKELL_ENABLE_HADDOCK_DOCUMENTATION?=	yes

.include "../../lang/ghc88/buildlink3.mk"

# Tools
_HASKELL_BIN=		${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/ghc
_HASKELL_PKG_BIN=	${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/ghc-pkg

_HASKELL_VERSION_CMD=	${_HASKELL_BIN} -V 2>/dev/null | ${CUT} -d ' ' -f 8
_HASKELL_VERSION=	ghc-${_HASKELL_VERSION_CMD:sh}

# Determine GHC shlib suffix
_HASKELL_SHLIB_SUFFIX.dylib=	dylib
_HASKELL_SHLIB_SUFFIX=		${_HASKELL_SHLIB_SUFFIX.${SHLIB_TYPE}:Uso}

# GHC requires C compiler.
USE_LANGUAGES+=	c

# Declarations for ../../mk/configure/configure.mk
CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${_HASKELL_BIN:Q}
CONFIGURE_ARGS+=	--with-hc-pkg=${_HASKELL_PKG_BIN:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.if ${HASKELL_ENABLE_SHARED_LIBRARY} == "yes"
CONFIGURE_ARGS+=	--enable-shared --enable-executable-dynamic
.else
CONFIGURE_ARGS+=	--disable-shared --disable-executable-dynamic
.endif

.if ${HASKELL_ENABLE_LIBRARY_PROFILING} == "yes"
CONFIGURE_ARGS+=	--enable-library-profiling
.else
CONFIGURE_ARGS+=	--disable-library-profiling
.endif

.if ${HASKELL_ENABLE_HADDOCK_DOCUMENTATION} == "yes"
CONFIGURE_ARGS+=	--with-haddock=${BUILDLINK_PREFIX.ghc:Q}/bin/haddock
.endif

CONFIGURE_ARGS+=	-O${HASKELL_OPTIMIZATION_LEVEL}

.if !exists(${PKGDIR}/PLIST)
_HS_PLIST_STATUS=	missing
.elif !${${GREP} "." ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	missing
.elif ${${GREP} HS_INTF ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	lib-ok
.elif !${${GREP} "/package-description" ${PKGDIR}/PLIST || ${TRUE}:L:sh}
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

_HS_PLIST_SUBST+=	HS_INTF=${_HASKELL_PL_INTF}
_HS_PLIST_SUBST+=	HS_IMPL=${_HASKELL_PL_IMPL}
_HS_PLIST_SUBST+=	HS_DOCS=${_HASKELL_PL_DOCS}
_HS_PLIST_SUBST+=	HS_PLATFORM=${_HASKELL_PL_PLATFORM}
_HS_PLIST_SUBST+=	HS_PKGID=${_HASKELL_PL_PKGID}
_HS_PLIST_SUBST+=	HS_VER=${_HASKELL_PL_VER}
PLIST_SUBST+=		${exists(${DESTDIR}${_HASKELL_PKG_DESCR_FILE}):?${_HS_PLIST_SUBST}:}

_HS_PRINT_PLIST_AWK+=	{ sub("^${_HASKELL_PL_INTF}",       "$${HS_INTF}") }
_HS_PRINT_PLIST_AWK+=	{ sub("^${_HASKELL_PL_IMPL}",       "$${HS_IMPL}") }
_HS_PRINT_PLIST_AWK+=	{ sub("^${_HASKELL_PL_DOCS}",       "$${HS_DOCS}") }
_HS_PRINT_PLIST_AWK+=	{ sub("/${_HASKELL_PL_PLATFORM}/", "/$${HS_PLATFORM}/") }
_HS_PRINT_PLIST_AWK+=	{ sub( "${_HASKELL_PL_PKGID}",      "$${HS_PKGID}") }
_HS_PRINT_PLIST_AWK+=	{ sub( "${_HASKELL_PL_VER}",        "$${HS_VER}") }
PRINT_PLIST_AWK+=	${exists(${DESTDIR}${_HASKELL_PKG_DESCR_FILE}):?${_HS_PRINT_PLIST_AWK}:}
.endif

.if ${_HS_PLIST_STATUS} == missing || ${_HS_PLIST_STATUS} == outdated
.  if ${HS_UPDATE_PLIST} == yes
GENERATE_PLIST+= 	${MAKE} print-PLIST > ${PKGDIR}/PLIST;
.  endif
GENERATE_PLIST+= \
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} * \( -type f -o -type l \) | ${SORT};
PLIST_SRC=	# none
.endif

.if ${_HS_PLIST_STATUS} == outdated && ${HS_UPDATE_PLIST} == no
WARNINGS+=	"[haskell.mk] The PLIST format is outdated."
WARNINGS+=	"[haskell.mk] Set HS_UPDATE_PLIST=yes to update it automatically."
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
