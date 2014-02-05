# $NetBSD: haskell.mk,v 1.1 2014/02/05 07:02:30 obache Exp $
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
# Package-settable variables:
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
#           no

.if !defined(HASKELL_MK)
HASKELL_MK=	# defined

.include "../../mk/bsd.fast.prefs.mk"


# Declare HASKELL_COMPILER as one of BUILD_DEFS variables. See
# ../../mk/misc/show.mk
BUILD_DEFS+=	HASKELL_COMPILER


# Declarations for ../../mk/misc/show.mk
_VARGROUPS+=		haskell
_DEF_VARS.haskell= \
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
	_HASKELL_VERSION
_PKG_VARS.haskell= \
	HASKELL_ENABLE_LIBRARY_PROFILING \
	HASKELL_ENABLE_HADDOCK_DOCUMENTATION

# PKGNAME is usually named after DISTNAME.
PKGNAME?=	hs-${DISTNAME}

# Default value of MASTER_SITES.
_DISTBASE?=	${DISTNAME:C/-[^-]*$//}
_DISTVERSION?=	${DISTNAME:C/^.*-//}
MASTER_SITES?=	${MASTER_SITE_HASKELL_HACKAGE:=${DISTNAME}/}

# Default value of HOMEPAGE.
HOMEPAGE?=	http://hackage.haskell.org/cgi-bin/hackage-scripts/package/${_DISTBASE}

# Cabal packages may use pkg-config, but url2pkg can't detect
# that. (PHO: I think that should be handled by url2pkg (2009-05-20))
USE_TOOLS+=	pkg-config

# Default value of HASKELL_ENABLE_LIBRARY_PROFILING
HASKELL_ENABLE_LIBRARY_PROFILING?=	yes

# Default value of HASKELL_ENABLE_HADDOCK_DOCUMENTATION
HASKELL_ENABLE_HADDOCK_DOCUMENTATION?=	no

# Compiler specific variables and targets.
.if ${HASKELL_COMPILER} == "ghc"

# Add dependency to the GHC.
.include "../../lang/ghc7/buildlink3.mk"

# Tools
_GHC_BIN=		${BUILDLINK_PREFIX.ghc}/bin/ghc
_GHC_PKG_BIN=		${BUILDLINK_PREFIX.ghc}/bin/ghc-pkg
_HASKELL_BIN=		${_GHC_BIN} # Expose to the outer scope.
_HASKELL_PKG_BIN=	${_GHC_PKG_BIN} # Expose to the outer scope.

# Determine GHC version.
_GHC_VERSION_CMD=	${_GHC_BIN} -V | ${CUT} -d ' ' -f 8
_GHC_VERSION=		${_GHC_VERSION_CMD:sh}
_GHC_VERSION_FULL=	ghc-${_GHC_VERSION}
_HASKELL_VERSION=	${_GHC_VERSION_FULL} # Expose to the outer scope.

# GHC requires C compiler.
USE_LANGUAGES+=	c

# Declarations for ../../mk/configure/configure.mk
CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${_GHC_BIN}
CONFIGURE_ARGS+=	--with-hc-pkg=${_GHC_PKG_BIN}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif # ${HASKELL_COMPILER}

# Library profiling
PLIST_VARS+=		prof
.if ${HASKELL_ENABLE_LIBRARY_PROFILING} == "yes"
CONFIGURE_ARGS+=	-p
PLIST.prof=		yes
.endif


# Haddock documentations
PLIST_VARS+=		doc
.if ${HASKELL_ENABLE_HADDOCK_DOCUMENTATION} == "yes"
CONFIGURE_ARGS+=	--with-haddock=${BUILDLINK_PREFIX.ghc}/bin/haddock
PLIST.doc=		yes
.endif

# Optimization
CONFIGURE_ARGS+=	-O2

# package.conf and package.conf.old should be ignored at all.
PRINT_PLIST_AWK+= \
	/\/package\.conf(\.old)?$$/ { next; }

# _HASKELL_VERSION should be substituted in PLIST.
PLIST_SUBST+=	HASKELL_VERSION=${_HASKELL_VERSION}
PRINT_PLIST_AWK+= \
	{ gsub(/${_HASKELL_VERSION}/, "$${HASKELL_VERSION}"); }

# We might not have any working Haskell interpreter so compile
# Setup.?hs to a binary.
pre-configure: ${WRKSRC}/Setup

${WRKSRC}/Setup:
	${RUN} cd ${WRKSRC} && \
		${_HASKELL_BIN} --make Setup

# Define configure target.
do-configure:
	${RUN} cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
			./Setup configure ${CONFIGURE_ARGS}

# Define build target.
do-build:
	${RUN} cd ${WRKSRC} && \
		./Setup build
.if ${HASKELL_ENABLE_HADDOCK_DOCUMENTATION} == "yes"
	${RUN} cd ${WRKSRC} && \
		./Setup haddock
.endif

# Define install target. We need installed-pkg-config to be installed
# for package registration (if any).
_HASKELL_PKG_DESCR_FILE=	${PREFIX}/lib/${DISTNAME}/${_HASKELL_VERSION}/package-description

do-install:
	${RUN} cd ${WRKSRC} && \
		./Setup register --gen-pkg-config=dist/package-description && \
		if [ "${_USE_DESTDIR}" = "no" ]; then \
			./Setup copy && \
			if [ -f dist/package-description ]; then \
				${INSTALL_DATA} dist/package-description ${_HASKELL_PKG_DESCR_FILE}; \
			fi \
		else \
			./Setup copy --destdir=${DESTDIR} && \
			if [ -f dist/package-description ]; then \
				${INSTALL_DATA} dist/package-description ${DESTDIR}${_HASKELL_PKG_DESCR_FILE}; \
			fi \
		fi

# Define test target.
do-test:
	${RUN} cd ${WRKSRC} && \
		./Setup test

# Substitutions for INSTALL and DEINSTALL.
FILES_SUBST+=	DISTNAME=${DISTNAME}
FILES_SUBST+=	HASKELL_PKG_BIN=${_HASKELL_PKG_BIN}
FILES_SUBST+=	HASKELL_PKG_DESCR_FILE=${_HASKELL_PKG_DESCR_FILE}

INSTALL_TEMPLATES+=	../../mk/haskell/INSTALL.in
DEINSTALL_TEMPLATES+=	../../mk/haskell/DEINSTALL.in


.endif # HASKELL_MK
