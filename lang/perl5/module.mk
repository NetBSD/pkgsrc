# $NetBSD: module.mk,v 1.27 2003/12/03 17:29:12 erh Exp $
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

.if !defined(_PERL5_MODULE_MK)
_PERL5_MODULE_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPMETHOD.perl+=	full

.if !defined(NO_BUILDLINK)
.  if empty(USE_BUILDLINK3:M[nN][oO])
.    include "../../lang/perl5/buildlink3.mk"
.  elif empty(USE_BUILDLINK2:M[nN][oO])
.    include "../../lang/perl5/buildlink2.mk"
.  endif
.endif

PERL5_CONFIGURE?=	YES
PERL5_CONFIGURE_DIRS?=	${CONFIGURE_DIRS}

# All pkgsrc-install perl modules are installed into the "site"
# directories.
#
MAKE_PARAMS+=		INSTALLDIRS=site

.if ${OPSYS} == "AIX"
# Perl doesn't like building with gcc on AIX
CC=/usr/bin/cc
MAKE_PARAMS+=  CC="${CC}"
.undef USE_GCC3
.endif

.PHONY: perl5-configure
perl5-configure:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in ${PERL5_CONFIGURE_DIRS}; do				\
		if [ -f $$dir/Makefile.PL ]; then			\
			( cd $$dir && ${SETENV} ${MAKE_ENV}		\
			  ${PERL5} Makefile.PL ${MAKE_PARAMS});		\
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
PERL5_${_var_}=	${PREFIX}/${PERL5_SUB_${_var_}}
MAKE_FLAGS+=	${_var_}="${PERL5_${_var_}}"
.endfor
#
# The PREFIX in the generated Makefile will point to ${_PERL5_PREFIX},
# so override its value to the module's ${PREFIX}.
#
MAKE_FLAGS+=		PREFIX="${PREFIX}"

.if defined(DEFAULT_VIEW.perl)
DEFAULT_VIEW.${PKGBASE}=	${DEFAULT_VIEW.perl}
.endif

.if defined(PERL5_LDFLAGS) && !empty(PERL5_LDFLAGS)
FIX_RPATH+=	PERL5_LDFLAGS
LDFLAGS+=	${PERL5_LDFLAGS}
.endif

.include "../../mk/bsd.prefs.mk"

# MakeMaker provides two hooks, PASTHRU_INC and OTHERLDFLAGS, to
# customize the arguments passed to the preprocessor and linker,
# respectively.
#
MAKE_FLAGS+=	PASTHRU_INC="${CPPFLAGS}"
.if ${OBJECT_FMT} == "a.out"
MAKE_FLAGS+=	OTHERLDFLAGS="${LDFLAGS:S/-Wl,//g}"
.else
MAKE_FLAGS+=	OTHERLDFLAGS="${LDFLAGS}"
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
		-e "s,/[^/]*$$, 2>/dev/null || \${TRUE}," \
	| ${SORT} -ur
PERL5_GENERATE_PLIST=	${PERL5_PLIST_COMMENT}; \
			${PERL5_PLIST_FILES}; \
			${PERL5_PLIST_DIRS}
GENERATE_PLIST+=	${PERL5_GENERATE_PLIST};
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
	for dir in ${PERL5_INSTALLARCHLIB} ${PERL5_INSTALLSITEARCH}; do \
		if [ -f $$dir/perllocal.pod ]; then			\
			${RM} -f $$dir/perllocal.pod;			\
		fi;							\
	done

# Default test target for perl5 modules
TEST_TARGET?=	test

.endif	# _PERL5_MODULE_MK
