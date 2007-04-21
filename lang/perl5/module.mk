# $NetBSD: module.mk,v 1.54 2007/04/21 09:41:00 rillig Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install perl5 modules.
#
# The following targets are provided by this file:
#
# perl5-configure	runs the standard perl configuration in
#			each of the directories specified in
#			${PERL5_CONFIGURE_DIRS}.
#
# do-configure		runs the perl5-configure target; if PERL5_CONFIGURE
#			is set to "YES", then this target overrides the
#			default do-configure provided by bsd.pkg.mk.
#
# The following variables may be set prior to including this file:
#
# PERL5_CONFIGURE	if "YES", then for do-configure, run the standard
#			perl configuration assuming Makefile.PL exists;
#			defaults to "YES".
#
# PERL5_CONFIGURE_DIRS	list of directories in which to run the
#			standard perl configuration; defaults to
#			${CONFIGURE_DIRS}.
#
# PERL5_LDFLAGS		extra linker flags to pass on to the build
#			process.
#
# PERL5_MODULE_TYPE	"MakeMaker" or "Module::Build" depending on which
#			framework is used to build/install the module.

.if !defined(_PERL5_MODULE_MK)
_PERL5_MODULE_MK=	# defined

.include "../../mk/bsd.prefs.mk"

PERL5_MODULE_TYPE?=		MakeMaker

.if (${PERL5_MODULE_TYPE} != "MakeMaker") && \
    (${PERL5_MODULE_TYPE} != "Module::Build")
PKG_FAIL_REASON+=	"\`\`${PERL5_MODULE_TYPE}'' is not a supported PERL5_MODULE_TYPE."
.endif

# Default test target for Perl modules
TEST_TARGET?=		test

.include "../../mk/compiler.mk"

# see http://mail-index.netbsd.org/tech-pkg/2007/04/20/0004.html
.if ${OPSYS} == "AIX"
.  if !empty(CC_VERSION:Mgcc*)
BROKEN=		Perl does not like building with GCC on AIX, please use a different compiler
.  endif
.endif

.if ${PERL5_MODULE_TYPE} == "Module::Build"
_PERL5_MODTYPE=		modbuild
.elif ${PERL5_MODULE_TYPE} == "MakeMaker"
_PERL5_MODTYPE=		makemaker
.endif


###########################################################################
###
### Add the proper dependencies for using the specified module build
### system.
###

BUILDLINK_DEPMETHOD.perl+=	full
.include "../../lang/perl5/buildlink3.mk"

.if empty(PKGPATH:Mdevel/p5-Module-Build) && \
    (${PERL5_MODULE_TYPE} == "Module::Build")
BUILD_DEPENDS+=		p5-Module-Build>=0.2608nb1:../../devel/p5-Module-Build
.endif


###########################################################################
###
### Target definitions (configure, build, install, etc.)
###

PERL5_CONFIGURE?=	yes
PERL5_CONFIGURE_DIRS?=	${CONFIGURE_DIRS}

MAKE_ENV+=	LC_ALL=C

# All pkgsrc-installed Perl modules are installed into the "vendor"
# directories.
#
MAKE_PARAMS.makemaker+=	INSTALLDIRS=vendor
MAKE_PARAMS.modbuild+=	installdirs=vendor

MAKE_PARAMS+=	${MAKE_PARAMS.${_PERL5_MODTYPE}}

.PHONY: do-makemaker-configure
do-makemaker-configure:
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	for dir in ${PERL5_CONFIGURE_DIRS}; do				\
		cd ${WRKSRC};						\
		if ${TEST} -f "$$dir"/Makefile.PL; then			\
			cd "$$dir";					\
			${SETENV} ${MAKE_ENV}				\
				${PERL5} Makefile.PL ${MAKE_PARAMS};	\
		fi;							\
	done

.PHONY: do-modbuild-configure
do-modbuild-configure:
	${_PKG_SILENT}${_PKG_DEBUG} set -e;				\
	for dir in ${PERL5_CONFIGURE_DIRS}; do				\
		cd ${WRKSRC};						\
		if ${TEST} -f "$$dir"/Build.PL; then			\
			cd "$$dir";					\
			${SETENV} ${MAKE_ENV}				\
				${PERL5} Build.PL ${MAKE_PARAMS};	\
		fi;							\
	done

.PHONY: perl5-configure
perl5-configure: do-${_PERL5_MODTYPE}-configure

.if !empty(PERL5_CONFIGURE:M[yY][eE][sS])
do-configure: perl5-configure
.endif

.PHONY: do-modbuild-build
do-modbuild-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build

.PHONY: do-modbuild-test
do-modbuild-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build test

.PHONY: do-modbuild-install
do-modbuild-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build install

.if target(do-${_PERL5_MODTYPE}-build) && !defined(NO_BUILD)
do-build: do-${_PERL5_MODTYPE}-build
do-test: do-${_PERL5_MODTYPE}-test
.endif
.if target(do-${_PERL5_MODTYPE}-install)
do-install: do-${_PERL5_MODTYPE}-install
.endif


###########################################################################
###
### Make variable overrides
###

# MakeMaker provides two hooks, OPTIMIZE and OTHERLDFLAGS, to
# customize the arguments passed to the preprocessor and linker,
# respectively.
#
PERL5_MAKE_FLAGS.makemaker+=	OPTIMIZE=${CFLAGS:Q}" "${CPPFLAGS:Q}
.if ${OBJECT_FMT} == "a.out"
PERL5_MAKE_FLAGS.makemaker+=	OTHERLDFLAGS=${LDFLAGS:S/-Wl,//g:Q}
.else
PERL5_MAKE_FLAGS.makemaker+=	OTHERLDFLAGS=${LDFLAGS:Q}
.endif

# Repoint all of the vendor-specific variables to be under the perl5
# module's ${PREFIX}.
#
.include "../../lang/perl5/vars.mk"
.for _var_ in ${_PERL5_VARS}
PERL5_MAKE_FLAGS.makemaker+=	${_var_}=${PERL5_${_var_}:Q}
.endfor
#
# The PREFIX in the generated Makefile will point to ${_PERL5_PREFIX},
# so override its value to the module's ${PREFIX}.
#
PERL5_MAKE_FLAGS.makemaker+=	PREFIX=${PREFIX:Q}

PERL5_MAKE_FLAGS+=	${PERL5_MAKE_FLAGS.${_PERL5_MODTYPE}}
MAKE_FLAGS+=		${PERL5_MAKE_FLAGS}

.if defined(PERL5_LDFLAGS) && !empty(PERL5_LDFLAGS)
FIX_RPATH+=	PERL5_LDFLAGS
LDFLAGS+=	${PERL5_LDFLAGS}
.endif

.include "../../lang/perl5/packlist.mk"

.include "../../mk/pthread.buildlink3.mk"

.endif	# _PERL5_MODULE_MK
