# $NetBSD: haskell.mk,v 1.69 2024/05/06 09:33:22 pho Exp $
#
# This Makefile fragment handles Haskell Cabal packages. Package
# configuration, building, installation, registration and unregistration
# are fully automated. See also mk/haskell/README.md for a packaging guide.
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
# HASKELL_PKG_NAME
#	The name of the corresponding Cabal package, in case it differs
#	from ${DISTNAME}.
#
#	Default value: ${DISTNAME}
#
# HASKELL_OPTIMIZATION_LEVEL
#	Optimization level for compilation.
#
#	Possible values: 0 1 2
#       Default value: 2
#
# HASKELL_ENABLE_DYNAMIC_EXECUTABLE
#	Whether executables in the package should be linked dynamically or
#	not.
#
#	Possible values: yes, no
#	Default value: inherits ${HASKELL_ENABLE_SHARED_LIBRARY}
#
# HASKELL_ENABLE_TESTS
#	Build test suites. This usually requires some additional
#	dependencies, which is why tests aren't enabled by
#	default. Enabling it also defines the target "do-test" unless the
#	Makefile already defines one.
#
#	Possible values: yes, no
#	Default value: no
#
# HASKELL_DISABLE_EXECUTABLES
#	A list of executables that we don't want to build or
#	install. Listing executables in this variable will cause the
#	*.cabal file to be rewritten so that they won't be built.
#
#	Default value: empty
#
# HASKELL_DISABLE_LIBRARIES
#	A list of libraries that we don't want to build or install. Listing
#	libraries in this variable will cause the *.cabal file to be
#	rewritten so that they won't be built.
#
#	Default value: empty
#
# HASKELL_UNRESTRICT_DEPENDENCIES
#	A list of Cabal packages that the package depends on, whose version
#	constraints are way too restricted to solve. Listing packages in
#	this variable will cause the *.cabal file to be rewritten so that
#	any version is accepted. Use this with care, because not all
#	incompatibilities are caught during build time.
#
#	Default value: empty
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
_PKG_VARS.haskell= \
	HASKELL_ENABLE_DYNAMIC_EXECUTABLE \
	HASKELL_ENABLE_TESTS \
	HASKELL_OPTIMIZATION_LEVEL \
	HASKELL_PKG_NAME \
	HASKELL_DISABLE_EXECUTABLES \
	HASKELL_DISABLE_LIBRARIES \
	HASKELL_UNRESTRICT_DEPENDENCIES \
	PKGNAME HOMEPAGE MASTER_SITES
_DEF_VARS.haskell= \
	BUILDLINK_PASSTHRU_DIRS \
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
	UNLIMIT_RESOURCES \
	_HASKELL_VERSION_CMD \
	_HASKELL_BIN \
	_HASKELL_INTERP_BIN \
	_HASKELL_GLOBAL_PKG_DB \
	_HASKELL_PKG_BIN \
	_HASKELL_PKG_DESCR_FILE_OR_DIR \
	_HASKELL_PKG_ID_FILE \
	_HASKELL_VERSION
_USE_VARS.haskell= \
	DISTNAME \
	PKG_VERBOSE \
	BUILDLINK_PREFIX.ghc \
	MASTER_SITE_HASKELL_HACKAGE \
	PKGDIR DESTDIR \
	PREFIX \
	WRKSRC \
	_MAKE_JOBS_N \
	_PATH_ORIG
_SORTED_VARS.haskell= \
	HASKELL_DISABLE_EXECUTABLES \
	HASKELL_DISABLE_LIBRARIES \
	HASKELL_UNRESTRICT_DEPENDENCIES
_LISTED_VARS.haskell= \
	BUILDLINK_PASSTHRU_DIRS \
	CONFIGURE_ARGS \
	PLIST_SUBST \
	PRINT_PLIST_AWK \
	FILES_SUBST
_IGN_VARS.haskell= \
	USE_TOOLS CONFIGURE_ENV MAKE_ENV WARNINGS _*

PKGNAME?=	hs-${DISTNAME}
MASTER_SITES?=	${MASTER_SITE_HASKELL_HACKAGE:=${DISTNAME}/}
HOMEPAGE?=	http://hackage.haskell.org/package/${DISTNAME:C/-[^-]*$//}

# GHC can be a memory hog, so don't apply regular limits.
UNLIMIT_RESOURCES+=	datasize virtualsize

HASKELL_OPTIMIZATION_LEVEL?=		2
HASKELL_ENABLE_DYNAMIC_EXECUTABLE?=	${HASKELL_ENABLE_SHARED_LIBRARY}
HASKELL_ENABLE_SHARED_LIBRARY?=		yes
HASKELL_ENABLE_LIBRARY_PROFILING?=	yes
HASKELL_ENABLE_HADDOCK_DOCUMENTATION?=	yes
HASKELL_ENABLE_TESTS?=			no
HASKELL_DISABLE_EXECUTABLES?=		# empty
HASKELL_DISABLE_LIBRARIES?=		# empty
HASKELL_UNRESTRICT_DEPENDENCIES?=	# empty

.include "../../lang/ghc96/buildlink3.mk"

# Some Cabal packages requires preprocessors to build, and we don't
# want them to implicitly depend on such tools. Place dummy scripts by
# default.
.include "../../mk/haskell/tools/alex.mk"
.include "../../mk/haskell/tools/cpphs.mk"
.include "../../mk/haskell/tools/happy.mk"

# Define some useful targets for pkgsrc developers.
.include "../../mk/haskell/developer.mk"

# Tools
_HASKELL_BIN=		${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/ghc
_HASKELL_INTERP_BIN=	${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/runghc
_HASKELL_PKG_BIN=	${BUILDLINK_PREFIX.ghc:U${PREFIX}}/bin/ghc-pkg

_HASKELL_VERSION_CMD=	${_HASKELL_BIN} -V 2>/dev/null | ${CUT} -d ' ' -f 8
_HASKELL_VERSION=	ghc-${_HASKELL_VERSION_CMD:sh}

# Determine the path to the global Haskell package database. We need this
# in our INSTALL and DEINSTALL hooks.
_HASKELL_GLOBAL_PKG_DB_CMD=	${_HASKELL_BIN:Q} --print-global-package-db
_HASKELL_GLOBAL_PKG_DB=		${_HASKELL_GLOBAL_PKG_DB_CMD:sh}

# By default GHC uses a per-user default environment file if one is
# available. Cabal has to be visible in order to compile (or interpret)
# Setup.hs, but per-user default environment files usually don't mark it as
# visible. Tell GHC not to read any environment files.
_HASKELL_BUILD_SETUP_OPTS=	-package-env -

# GHC requires C compiler.
USE_LANGUAGES+=	c

# Some Haskell packages build and install example executables that are
# useless aside from debugging the packages, and we don't want them to be
# installed.
.if !empty(HASKELL_DISABLE_EXECUTABLES)
SUBST_CLASSES+=		exe
SUBST_STAGE.exe?=	post-extract
SUBST_FILES.exe?=	${HASKELL_PKG_NAME:C/-[[:digit:].]+$//}.cabal
SUBST_MESSAGE.exe?=	Disabling executables: ${HASKELL_DISABLE_EXECUTABLES}
SUBST_FILTER_CMD.exe=	\
	${AWK} -f "${.CURDIR}/../../mk/haskell/disable-components.awk" \
		-v exe=${HASKELL_DISABLE_EXECUTABLES:Q}
.endif

# Some Haskell packages build and install libraries that are useless aside
# from debugging the packages, and we don't want them to be installed.
.if !empty(HASKELL_DISABLE_LIBRARIES)
SUBST_CLASSES+=		lib
SUBST_STAGE.lib?=	post-extract
SUBST_FILES.lib?=	${HASKELL_PKG_NAME:C/-[[:digit:].]+$//}.cabal
SUBST_MESSAGE.lib?=	Disabling libraries: ${HASKELL_DISABLE_LIBRARIES}
SUBST_FILTER_CMD.lib=	\
	${AWK} -f "${.CURDIR}/../../mk/haskell/disable-components.awk" \
		-v lib=${HASKELL_DISABLE_LIBRARIES:Q}
.endif

# Haskell packages don't use semvars but they use something similar to it,
# which is called Haskell PVP (https://pvp.haskell.org/). Packages usually
# have version constraints on their dependencies that specify not only
# lower bounds but also upper bounds. The problem is that, while lower
# bounds are mostly accurate, package authors can not be sure about upper
# bounds so they tend to be too pessimistic about compatibility.
.if !empty(HASKELL_UNRESTRICT_DEPENDENCIES)
SUBST_CLASSES+=		deps
SUBST_STAGE.deps?=	post-extract
SUBST_FILES.deps?=	${HASKELL_PKG_NAME:C/-[[:digit:].]+$//}.cabal
SUBST_MESSAGE.deps?=	Relaxing version constraints on dependencies
.  for _pkg_ in ${HASKELL_UNRESTRICT_DEPENDENCIES}
# Leading whitespace, or commas, or colons to avoid mismatches, remove
# version constraints up to end of line, ',', or '}'.
SUBST_SED.deps+=	-Ee 's/((^|[,:])[[:space:]]*${_pkg_})[[:space:]=><^][^,}]+([,}]|$$)/\1\3/g'
.  endfor
.endif

# Declarations for ../../mk/configure/configure.mk
CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${_HASKELL_BIN:Q}
CONFIGURE_ARGS+=	--with-hc-pkg=${_HASKELL_PKG_BIN:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

PKGSRC_OVERRIDE_MKPIE=	yes
.if ${_PKGSRC_MKPIE} == "yes"
CONFIGURE_ARGS+=	--ghc-option=-fPIC --ghc-option=-pie
.endif

.if ${HASKELL_ENABLE_DYNAMIC_EXECUTABLE:tl} == "yes"
CONFIGURE_ARGS+=	--enable-executable-dynamic
.else
CONFIGURE_ARGS+=	--disable-executable-dynamic
.endif

PLIST_VARS+=		shlibs
PRINT_PLIST_AWK+=	/(\.dyn_hi|\/lib[^\/]+\.so)$$/ { $$0 = "$${PLIST.shlibs}" $$0 }
.if ${HASKELL_ENABLE_SHARED_LIBRARY:tl} == "yes"
CONFIGURE_ARGS+=	--enable-shared
PLIST.shlibs=		yes
.else
CONFIGURE_ARGS+=	--disable-shared
.endif

PLIST_VARS+=		prof
PRINT_PLIST_AWK+=	/(\.p_hi|\/lib[^\/]+_p\.a)$$/ { $$0 = "$${PLIST.prof}" $$0 }
.if ${HASKELL_ENABLE_LIBRARY_PROFILING:tl} == "yes"
CONFIGURE_ARGS+=	--enable-library-profiling
PLIST.prof=		yes
.else
CONFIGURE_ARGS+=	--disable-library-profiling
.endif

PLIST_VARS+=		doc
PRINT_PLIST_AWK+=	/^share\/doc\// && /\/html\// { $$0 = "$${PLIST.doc}" $$0 }
.if ${HASKELL_ENABLE_HADDOCK_DOCUMENTATION:tl} == "yes"
CONFIGURE_ARGS+=	--with-haddock=${BUILDLINK_PREFIX.ghc:Q}/bin/haddock
PLIST.doc=		yes
.endif

.if ${HASKELL_ENABLE_TESTS:tl} == "yes"
CONFIGURE_ARGS+=	--enable-tests
.  if !target(do-test)
do-test:
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC} && \
		./Setup test ${PKG_VERBOSE:D-v}
.  endif
.endif

CONFIGURE_ARGS+=	-O${HASKELL_OPTIMIZATION_LEVEL}
.if ${OPSYS} != "Darwin"
# when making flags consistent: warning:
#     -fsplit-sections is not useful on this platform since it uses subsections-via-symbols. Ignoring.
CONFIGURE_ARGS+=	--enable-split-sections
.endif

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

# When a Template Haskell splice is to be evaluated by a dynamically-linked
# GHC, it first compiles the splice and creates a .so file like
# /tmp/ghc_XXXX/libghc_XX.so, then it dlopen's it. When the source file
# contains more than one splice, subsequent splices will refer to previous
# ones via "-L/tmp/ghc_XXXX -Wl,-rpath,/tmp/ghc_XXXX -lghc_XX". This means
# /tmp/ghc_* must be protected from getting removed by our wrappers. We
# also want to be explicit about the path to be chosen for temporary files.
CONFIGURE_ARGS+=		--ghc-options=-tmpdir\ ${TMPDIR:U/tmp:Q}
BUILDLINK_PASSTHRU_DIRS+=	${TMPDIR:U/tmp}

# Some packages lack PLIST but they may have things like PLIST.common.
.if empty(PLIST_SRC)
.  if !exists(${PKGDIR}/PLIST)
_HS_PLIST_STATUS=	missing
.  elif !${${GREP} "." ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	missing
.  elif ${${GREP} HS_VERSION ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	ok
.  elif !${${GREP} "/package-description" ${PKGDIR}/PLIST || ${TRUE}:L:sh}
_HS_PLIST_STATUS=	ok
.  else
_HS_PLIST_STATUS=	outdated
.  endif
.else
_HS_PLIST_STATUS=	ok
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
# Abbreviated compiler version. Used for shared libraries.
_HS_PLIST.short-ver=		${_HASKELL_VERSION:S,-,,}

PLIST_SUBST+=			HS_PLATFORM=${_HS_PLIST.platform}
PLIST_SUBST+=			HS_VERSION=${_HASKELL_VERSION}
PLIST_SUBST+=			HS_VER=${_HS_PLIST.short-ver}
# Package IDs formatted as "{name}-{version}-{hash}": these only exist if
# the package contains at least one library.
_HS_PLIST.subst-libs.cmd=	\
	if [ -f ${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q} ]; then \
		n=`${WC} -l ${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q} | ${AWK} '{print $$1}'`; \
		if [ "$$n" -eq 1 ]; then \
			pkg_id=`${CAT} ${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q}`; \
			${ECHO} "HS_PKGID=$${pkg_id}"; \
		else \
			i=1; \
			while read pkg_id; do \
				${ECHO} "HS_PKGID.$${i}=$${pkg_id}"; \
				i=`${EXPR} $${i} + 1`; \
			done < ${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q}; \
		fi; \
	fi
PLIST_SUBST+=			${_HS_PLIST.subst-libs.cmd:sh}

PRINT_PLIST_AWK+=		{ gsub("${_HS_PLIST.platform}",   "$${HS_PLATFORM}") }
PRINT_PLIST_AWK+=		{ gsub("${_HASKELL_VERSION}",     "$${HS_VERSION}" ) }
PRINT_PLIST_AWK+=		{ gsub("${_HS_PLIST.short-ver}",  "$${HS_VER}"     ) }
_HS_PRINT_PLIST_AWK.libs.cmd=	\
	if [ -f ${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q} ]; then \
		n=`${WC} -l ${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q} | ${AWK} '{print $$1}'`; \
		if [ "$$n" -eq 1 ]; then \
			pkg_id=`${CAT} ${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q}`; \
			${ECHO} "{ gsub(\"$${pkg_id}\", \"\$${HS_PKGID}\") }"; \
		else \
			i=1; \
			while read pkg_id; do \
				${ECHO} "{ gsub(\"$${pkg_id}\", \"\$${HS_PKGID.$${i}}\") }"; \
				i=`${EXPR} $${i} + 1`; \
			done < ${DESTDIR:Q}${_HASKELL_PKG_ID_FILE:Q}; \
		fi; \
	fi
PRINT_PLIST_AWK+=		${_HS_PRINT_PLIST_AWK.libs.cmd:sh}

.if ${_HS_PLIST_STATUS} == missing || ${_HS_PLIST_STATUS} == outdated
.  if ${HS_UPDATE_PLIST:tl} == yes
GENERATE_PLIST+=	${MAKE} print-PLIST > ${PKGDIR}/PLIST;
.  endif
GENERATE_PLIST+=	\
	cd ${DESTDIR:Q}${PREFIX:Q} && \
		${FIND} * \( -type f -o -type l \) | ${SORT};
PLIST_SRC=		# none
.endif

.if ${HS_UPDATE_PLIST:tl} == no
.  if ${_HS_PLIST_STATUS} == missing
WARNINGS+=	"[haskell.mk] A PLIST is missing."
WARNINGS+=	"[haskell.mk] Set HS_UPDATE_PLIST=yes to generate it automatically."
.  elif ${_HS_PLIST_STATUS} == outdated
WARNINGS+=	"[haskell.mk] The PLIST format is outdated."
WARNINGS+=	"[haskell.mk] Set HS_UPDATE_PLIST=yes to update it automatically."
.  endif
.endif

# Define configure target. There are 3 ways to run Setup.hs: [1] interpret
# it with runghc, [2] compile it dynamically, and [3] compile it
# statically. [1] is fastest but is least reliable. [3] is slowest but is
# most reliable. So we try all these 3 ways in this order.
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
	${RUN} set -eu; \
	cd ${WRKSRC:Q}; \
	if ${TEST} -f Setup.hs; then \
		setup_src=Setup.hs; \
	else \
		setup_src=Setup.lhs; \
	fi; \
	if ${SETENV} ${CONFIGURE_ENV} \
		${_HASKELL_INTERP_BIN} ${_HASKELL_BUILD_SETUP_OPTS:%=--ghc-arg=%} \
			$$setup_src configure ${PKG_VERBOSE:D-v} ${CONFIGURE_ARGS}; then \
		${ECHO} '#!/bin/sh' > Setup; \
		${ECHO} 'exec' ${_HASKELL_INTERP_BIN} \
			${_HASKELL_BUILD_SETUP_OPTS:%=--ghc-arg=%} \
			$$setup_src '"$$@"' >> Setup; \
		${CHMOD} +x Setup; \
	else \
		${ECHO} "[mk/haskell.mk] Failed to interpret $$setup_src; falling back to compilation"; \
		${_HASKELL_BIN:Q} ${_HASKELL_BUILD_SETUP_OPTS} --make Setup -dynamic || \
			${_HASKELL_BIN:Q} ${_HASKELL_BUILD_SETUP_OPTS} --make Setup -static; \
		${SETENV} ${CONFIGURE_ENV} \
			./Setup configure ${PKG_VERBOSE:D-v} ${CONFIGURE_ARGS}; \
	fi

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
_HASKELL_PKG_DESCR_FILE_OR_DIR=	${_HASKELL_PKG_DESCR_DIR}/package-description
_HASKELL_PKG_ID_FILE=		${_HASKELL_PKG_DESCR_DIR}/package-id

INSTALLATION_DIRS+=		${_HASKELL_PKG_DESCR_DIR}
do-install:
	${RUN} ${SH} ../../mk/haskell/install.sh \
		-s "${WRKSRC}" \
		-d "${DESTDIR}" \
		-D "${_HASKELL_PKG_DESCR_FILE_OR_DIR}" \
		-i "${_HASKELL_PKG_ID_FILE}" \
		-p "${PREFIX}" \
		${PKG_VERBOSE:D-v}

# Substitutions for INSTALL and DEINSTALL.
FILES_SUBST+=	HASKELL_GLOBAL_PKG_DB=${_HASKELL_GLOBAL_PKG_DB:Q}
FILES_SUBST+=	HASKELL_PKG_BIN=${_HASKELL_PKG_BIN:Q}
FILES_SUBST+=	HASKELL_PKG_DESCR_FILE_OR_DIR=${_HASKELL_PKG_DESCR_FILE_OR_DIR:Q}
FILES_SUBST+=	HASKELL_PKG_ID_FILE=${_HASKELL_PKG_ID_FILE:Q}
FILES_SUBST+=	AWK=${AWK:Q}
FILES_SUBST+=	EXPR=${EXPR:Q}
FILES_SUBST+=	TRUE=${TRUE:Q}

INSTALL_TEMPLATES+=	../../mk/haskell/INSTALL.in
DEINSTALL_TEMPLATES+=	../../mk/haskell/DEINSTALL.in

# Only present these variables if the definitions can be extracted
# from the files in DESTDIR.
_DEF_VARS.haskell+=	_HS_PLIST.platform
_DEF_VARS.haskell+=	_HS_PLIST.short-ver

.endif # HASKELL_MK
