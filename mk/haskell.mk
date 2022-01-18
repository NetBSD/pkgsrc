# $NetBSD: haskell.mk,v 1.37 2022/01/18 02:24:36 pho Exp $
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
	HASKELL_ENABLE_HADDOCK_DOCUMENTATION \
	HS_UPDATE_PLIST
_SYS_VARS.haskell= \
	PKGNAME DISTNAME MASTER_SITES MASTER_SITE_HASKELL_HACKAGE \
	HOMEPAGE UNLIMIT_RESOURCES PREFIX
_DEF_VARS.haskell= \
	HASKELL_OPTIMIZATION_LEVEL \
	HASKELL_PKG_NAME \
	USE_LANGUAGES \
	CONFIGURE_ARGS \
	PLIST_SUBST \
	PRINT_PLIST_AWK \
	GENERATE_PLIST \
	PLIST_SRC \
	FILES_SUBST \
	INSTALLATION_DIRS \
	INSTALL_TEMPLATES \
	DEINSTALL_TEMPLATES \
	_HASKELL_VERSION_CMD \
	_HASKELL_BIN \
	_HASKELL_PKG_BIN \
	_HASKELL_PKG_DESCR_FILE \
	_HASKELL_PKG_ID_FILE \
	_HASKELL_VERSION
_USE_VARS.haskell= \
	PKG_VERBOSE \
	BUILDLINK_PREFIX.ghc \
	PKGDIR DESTDIR \
	WRKSRC
_LISTED_VARS.haskell= \
	CONFIGURE_ARGS \
	PLIST_SUBST \
	PRINT_PLIST_AWK \
	FILES_SUBST
_IGN_VARS.haskell= \
	USE_TOOLS CONFIGURE_ENV MAKE_ENV WARNINGS _*

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

.include "../../lang/ghc90/buildlink3.mk"

# Some Cabal packages requires preprocessors to build, and we don't
# want them to implicitly depend on such tools. Place dummy scripts by
# default.
.include "../../mk/haskell/tools/alex.mk"
.include "../../mk/haskell/tools/cpphs.mk"
.include "../../mk/haskell/tools/happy.mk"

# Tools
_HASKELL_BIN=		${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/ghc
_HASKELL_PKG_BIN=	${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/ghc-pkg

_HASKELL_VERSION_CMD=	${_HASKELL_BIN} -V 2>/dev/null | ${CUT} -d ' ' -f 8
_HASKELL_VERSION=	ghc-${_HASKELL_VERSION_CMD:sh}

# By default GHC uses a per-user default environment file if one is
# available. Cabal has to be visible in order to compile Setup.?hs,
# but per-user default environment files usually don't mark it as
# visible. Tell GHC not to read any environment files.
_HASKELL_BUILD_SETUP_OPTS=	-package-env -

# GHC requires C compiler.
USE_LANGUAGES+=	c

# Declarations for ../../mk/configure/configure.mk
CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${_HASKELL_BIN:Q}
CONFIGURE_ARGS+=	--with-hc-pkg=${_HASKELL_PKG_BIN:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

PKGSRC_OVERRIDE_MKPIE=	yes
.if ${_PKGSRC_MKPIE} == "yes"
CONFIGURE_ARGS+=	--ghc-option=-fPIC --ghc-option=-pie
.endif

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

# Support RELRO. When PKGSRC_USE_RELRO isn't set to "no",
# mk/compiler/{ghc,clang}.mk add "-Wl,-z,relro" and optionally
# "-Wl,-z,now" to LDFLAGS. Since Cabal doesn't respect the environment
# variable LDFLAGS, we need to be explicit about it. Note that -optl
# is a GHC option which specifies options to be passed to CC, not LD,
# while linking executables and shared libraries.
CONFIGURE_ARGS+=	${LDFLAGS:S/^/--ghc-options=-optl\ /}
# GHC heavily uses "ld -r" to combine multiple .o files but our ld
# wrapper is going to inject the relro flags. In this case these flags
# don't make sense so ld(1) emits warnings. Use the original,
# non-wrapped ld(1) for merging objects as a dirty workaround.
_HS_ORIG_LD_CMD=	${SETENV} PATH=${_PATH_ORIG} which ld
CONFIGURE_ARGS+=	--ghc-options=-pgmlm\ ${_HS_ORIG_LD_CMD:sh}
CONFIGURE_ARGS+=	--ghc-options=-optlm\ -r

.if !exists(${PKGDIR}/PLIST)
_HS_PLIST_STATUS=	missing
.elif !${${GREP} "." ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	missing
.elif ${${GREP} HS_VERSION ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	ok
.elif !${${GREP} "/package-description" ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	ok
.else
_HS_PLIST_STATUS=	outdated
.endif

# Starting from GHC 7.10 (or 7.8?), packages are installed in directories
# with a hashed name, which makes it a bit more complicated to generate
# the PLIST.
#

# There is no easy way to obtain a platform string such as
# "x86_64-netbsd-ghc-9.0.1". If the package contains a library we
# could extract it from the description file, but if it's
# executable-only there's no such file. As a workaround we read the
# description of "base" (which always exists) and extract the platform
# from it.
_HS_PLIST.platform.cmd=		${_HASKELL_PKG_BIN} --simple-output field base data-dir
_HS_PLIST.platform=		${_HS_PLIST.platform.cmd:sh:H:T}
# Package ID formatted as "{name}-{version}-{hash}": this only exists
# if the package contains a library.
_HS_PLIST.lib.pkg-id.cmd=	${CAT} ${DESTDIR}${_HASKELL_PKG_ID_FILE}
_HS_PLIST.lib.pkg-id=		${exists(${DESTDIR}${_HASKELL_PKG_ID_FILE}):?${_HS_PLIST.lib.pkg-id.cmd:sh}:}
# Abbreviated compiler version. Used for shared libraries.
_HS_PLIST.short-ver=		${_HASKELL_VERSION:S,-,,}

PLIST_SUBST+=		HS_PLATFORM=${_HS_PLIST.platform}
PLIST_SUBST+=		HS_VERSION=${_HASKELL_VERSION}
PLIST_SUBST+=		HS_VER=${_HS_PLIST.short-ver}
_HS_PLIST_SUBST.lib=	HS_PKGID=${_HS_PLIST.lib.pkg-id}
PLIST_SUBST+=		${!empty(_HS_PLIST.lib.pkg-id):?${_HS_PLIST_SUBST.lib}:}

PRINT_PLIST_AWK+=	{ gsub("${_HS_PLIST.platform}",   "$${HS_PLATFORM}") }
PRINT_PLIST_AWK+=	{ gsub("${_HASKELL_VERSION}",     "$${HS_VERSION}" ) }
PRINT_PLIST_AWK+=	{ gsub("${_HS_PLIST.short-ver}",  "$${HS_VER}"     ) }
_HS_PRINT_PLIST_AWK.lib={ gsub("${_HS_PLIST.lib.pkg-id}", "$${HS_PKGID}"   ) }
PRINT_PLIST_AWK+=	${!empty(_HS_PLIST.lib.pkg-id):?${_HS_PRINT_PLIST_AWK.lib}:}

.if ${_HS_PLIST_STATUS} == missing || ${_HS_PLIST_STATUS} == outdated
.  if ${HS_UPDATE_PLIST} == yes
GENERATE_PLIST+=	${MAKE} print-PLIST > ${PKGDIR}/PLIST;
.  endif
GENERATE_PLIST+=	\
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} * \( -type f -o -type l \) | ${SORT};
PLIST_SRC=		# none
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
# Cabal packages are expected to have either Setup.hs or Setup.lhs,
# but its existence is not mandatory these days because the standard
# way to build a cabal package is to use the cabal-install command,
# which is not always available to us. As a result some packages
# actually lack it. The problem is that its expected content depends
# on the build-type field in *.cabal so we have to read it.
	${RUN} if ! ${TEST} -f ${WRKSRC}/Setup.hs -o -f ${WRKSRC}/Setup.lhs; then \
		buildType=`${AWK} -f ../../mk/haskell/build-type.awk ${WRKSRC}/*.cabal`; \
		${SH} ../../mk/haskell/gen-setup.sh "$$buildType" > ${WRKDIR}/.setup.hs; \
		ret=$$?; \
		if ${TEST} $$ret -eq 0; then \
			${MV} -f ${WRKDIR}/.setup.hs ${WRKSRC}/Setup.hs; \
		else \
			exit $$ret; \
		fi; \
	fi
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC} && \
		( ${_HASKELL_BIN:Q} ${_HASKELL_BUILD_SETUP_OPTS} --make Setup -dynamic || \
			${_HASKELL_BIN:Q} ${_HASKELL_BUILD_SETUP_OPTS} --make Setup -static )
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
# Executable-only packages tend to create an empty directory tree in
# lib/ which results in useless @pkgdir in PLIST.
	${RUN}${FIND} ${DESTDIR:Q}${PREFIX}/lib -type d | \
		${TAIL} -n 1 | \
		${XARGS} ${RMDIR} -p 2>/dev/null || ${TRUE}

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
_DEF_VARS.haskell+=	_HS_PLIST.platform
_DEF_VARS.haskell+=	_HS_PLIST.short-ver
_DEF_VARS.haskell+=	${!empty(_HS_PLIST.lib.pkg-id):?_HS_PLIST.lib.pkg-id:}

.endif # HASKELL_MK
