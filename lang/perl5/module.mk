# $NetBSD: module.mk,v 1.39 2005/02/23 10:42:07 wiz Exp $
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
# PERL5_USES_MODULE_BUILD	the package uses Module::Build instead
#				of ExtUtils::MakeMaker

.if !defined(_PERL5_MODULE_MK)
_PERL5_MODULE_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPMETHOD.perl+=	full

.if !defined(BUILDING_PERL5)
.  if !defined(NO_BUILDLINK)
.    if empty(USE_BUILDLINK3:M[nN][oO])
.      include "../../lang/perl5/buildlink3.mk"
.    endif
.  endif
.endif

.if defined(PERL5_USES_MODULE_BUILD)
BUILD_DEPENDS+=		p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
.endif

PERL5_CONFIGURE?=	YES
PERL5_CONFIGURE_DIRS?=	${CONFIGURE_DIRS}

# All pkgsrc-install perl modules are installed into the "site"
# directories.
#
MAKE_PARAMS+=		INSTALLDIRS=site

.include "../../mk/compiler.mk"

.if ${OPSYS} == "AIX"
.if !empty(CC_VERSION:Mgcc*)
BROKEN=		Perl does not like building with gcc on AIX, please use a different compiler
.endif
.endif

MAKE_ENV+=	LC_ALL=C
.if defined(PERL5_USES_MODULE_BUILD)
_CONF_ARG=	Build.PL
.else
_CONF_ARG=	Makefile.PL ${MAKE_PARAMS}
.endif

.PHONY: perl5-configure
perl5-configure:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in ${PERL5_CONFIGURE_DIRS}; do				\
		if [ -f $$dir/Makefile.PL ]; then			\
			( cd $$dir && ${SETENV} ${MAKE_ENV}		\
			  ${PERL5} ${_CONF_ARG});		\
		fi;							\
	done

.if defined(PERL5_CONFIGURE) && !empty(PERL5_CONFIGURE:M[yY][eE][sS])
.  if target(do-configure)
do-configure: perl5-configure
.  else
do-configure: perl5-configure
	${_PKG_SILENT}${_PKG_DEBUG}${DO_NADA}
.  endif
.endif

# Repoint all of the site-specific variables to be under the perl5
# module's ${PREFIX}.
#
.for _var_ in ${_PERL5_SITEVARS} INSTALLSCRIPT
PERL5_${_var_}=		${PREFIX}/${PERL5_SUB_${_var_}}
PERL5_MAKE_FLAGS+=	${_var_}="${PERL5_${_var_}}"
.endfor

.if !defined(PERL5_USES_MODULE_BUILD)
#
# The PREFIX in the generated Makefile will point to ${_PERL5_PREFIX},
# so override its value to the module's ${PREFIX}.
#
PERL5_MAKE_FLAGS+=	PREFIX="${PREFIX}"
.endif

.if defined(PERL5_USES_MODULE_BUILD)
do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build test

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build install
.endif

.if defined(DEFAULT_VIEW.perl)
DEFAULT_VIEW.${PKGBASE}=	${DEFAULT_VIEW.perl}
.endif

.if defined(PERL5_LDFLAGS) && !empty(PERL5_LDFLAGS)
FIX_RPATH+=	PERL5_LDFLAGS
LDFLAGS+=	${PERL5_LDFLAGS}
.endif

# MakeMaker provides two hooks, OPTIMIZE and OTHERLDFLAGS, to
# customize the arguments passed to the preprocessor and linker,
# respectively.
#
PERL5_MAKE_FLAGS+=	OPTIMIZE="${CFLAGS} ${CPPFLAGS}"
.if ${OBJECT_FMT} == "a.out"
PERL5_MAKE_FLAGS+=	OTHERLDFLAGS="${LDFLAGS:S/-Wl,//g}"
.else
PERL5_MAKE_FLAGS+=	OTHERLDFLAGS="${LDFLAGS}"
.endif

# Generate the PLIST from the files listed in PERL5_PACKLIST.
.if defined(PERL5_PACKLIST)
PERL5_PLIST_COMMENT= \
	( ${ECHO} "@comment The following lines are automatically generated"; \
	  ${ECHO} "@comment from the installed .packlist files." )
PERL5_PLIST_FILES= \
	( ${CAT} ${PERL5_PACKLIST}; for f in ${PERL5_PACKLIST}; do [ ! -f $$f ] || ${ECHO} $$f; done ) \
	| ${SED} -e "s,[ 	].*,," -e "s,/\./,/,g" -e "s,${PREFIX}/,," \
	| ${SORT} -u
PERL5_PLIST_DIRS= \
	( ${CAT} ${PERL5_PACKLIST}; for f in ${PERL5_PACKLIST}; do [ ! -f $$f ] || ${ECHO} $$f; done ) \
	| ${SED} -e "s,[ 	].*,," -e "s,/\./,/,g" -e "s,${PREFIX}/,," \
		-e "s,^,@unexec \${RMDIR} -p %D/," \
		-e "s,/[^/]*$$, 2>/dev/null || ${TRUE}," \
	| ${SORT} -ur
PERL5_GENERATE_PLIST=	${PERL5_PLIST_COMMENT}; \
			${PERL5_PLIST_FILES}; \
			${PERL5_PLIST_DIRS}
GENERATE_PLIST+=	${PERL5_GENERATE_PLIST};
.endif

# The build and install stages require slightly different values for
# INSTALLARCHLIB.  During the build, INSTALLARCHLIB refers to the
# directory where libperl.so may be found, which should point into the
# default view.  During the install, INSTALLARCHLIB refers to the
# directory where the perllocal.pod file should be installed, which
# should point into the package prefix.
#
.if !defined(BUILDING_PERL5)
MAKE_FLAGS+=		${PERL5_MAKE_FLAGS}
BUILD_MAKE_FLAGS=	${MAKE_FLAGS}
BUILD_MAKE_FLAGS+=	INSTALLARCHLIB="${VIEWBASE}/${PERL5_SUB_INSTALLARCHLIB}"
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}
INSTALL_MAKE_FLAGS+=	INSTALLARCHLIB="${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}"
.endif

# Remove the perllocal.pod file from the installation since we don't
# bother keeping the file contents up-to-date anyway.
#
.if ${PKG_INSTALLATION_TYPE} == "pkgviews"
post-install: perl5-post-install
.endif

.PHONY: perl5-post-install
perl5-post-install:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in							\
	    ${PREFIX}/${PERL5_SUB_INSTALLARCHLIB}			\
	    ${PERL5_INSTALLSITEARCH};					\
	do								\
		if [ -f $$dir/perllocal.pod ]; then			\
			${RM} -f $$dir/perllocal.pod;			\
		fi;							\
	done

# Default test target for perl5 modules
TEST_TARGET?=	test

.endif	# _PERL5_MODULE_MK
