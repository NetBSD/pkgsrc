# $NetBSD: module.mk,v 1.18 2003/09/13 15:04:59 jlam Exp $
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

_PERL5_SITEVARS=							\
	INSTALLSITEBIN INSTALLSITELIB INSTALLSITEARCH			\
	INSTALLSITEMAN1DIR INSTALLSITEMAN3DIR				\
	SITELIBEXP SITEARCHEXP

_PERL5_SITEVAR.INSTALLSITEBIN=		installsitebin
_PERL5_SITEVAR.INSTALLSITELIB=		installsitelib
_PERL5_SITEVAR.INSTALLSITEARCH=		installsitearch
_PERL5_SITEVAR.INSTALLSITEMAN1DIR=	installsiteman1dir
_PERL5_SITEVAR.INSTALLSITEMAN3DIR=	installsiteman3dir
_PERL5_SITEVAR.SITELIBEXP=		sitelibexp
_PERL5_SITEVAR.SITEARCHEXP=		sitearchexp

.if !defined(_PERL5_SITEPREFIX)
.  if exists(${PERL5})
_PERL5_PREFIX!=		\
	eval `${PERL5} -V:prefix 2>/dev/null`; ${ECHO} $$prefix
_PERL5_SITEPREFIX!=	\
	eval `${PERL5} -V:siteprefix 2>/dev/null`; ${ECHO} $$siteprefix
MAKEFLAGS+=	_PERL5_PREFIX="${_PERL5_PREFIX}"
MAKEFLAGS+=	_PERL5_SITEPREFIX="${_PERL5_SITEPREFIX}"

.    for _var_ in ${_PERL5_SITEVARS}
_PERL5_SUB_${_var_}!=	\
	eval `${PERL5} -V:${_PERL5_SITEVAR.${_var_}} 2>/dev/null`;	\
	${ECHO} $${${_PERL5_SITEVAR.${_var_}}} |			\
	${SED} -e "s,^${_PERL5_SITEPREFIX}/,,"
MAKEFLAGS+=	_PERL5_SUB_${_var_}="${_PERL5_SUB_${_var_}}"
.    endfor
_PERL5_SUB_INSTALLSCRIPT!=	\
	eval `${PERL5} -V:installscript 2>/dev/null`;			\
	${ECHO} $$installscript |					\
	${SED} -e "s,^${_PERL5_PREFIX}/,,"
MAKEFLAGS+=	_PERL5_SUB_INSTALLSCRIPT="${_PERL5_SUB_INSTALLSCRIPT}"
.  endif
.endif
#
# Repoint all of the site-specific variables to be under the perl5
# module's ${PREFIX}.
#
.for _var_ in ${_PERL5_SITEVARS} INSTALLSCRIPT
_PERL5_${_var_}=	${PREFIX}/${_PERL5_SUB_${_var_}}
MAKE_FLAGS+=		${_var_}="${_PERL5_${_var_}}"
.endfor
#
# The PREFIX in the generated Makefile will point to ${_PERL5_PREFIX},
# so override its value to the module's ${PREFIX}.
#
MAKE_FLAGS+=		PREFIX="${PREFIX}"

.if defined(DEFAULT_VIEW.perl)
DEFAULT_VIEW.${PKGBASE}=	${DEFAULT_VIEW.perl}
.endif

# OTHERLDFLAGS is the hook provided by the perl5 MakeMaker module to allow
# customizing the LDFLAGS passed to the compiler/linker.
#
.if defined(PERL5_LDFLAGS) && !empty(PERL5_LDFLAGS)
FIX_RPATH+=	PERL5_LDFLAGS
LDFLAGS+=	${PERL5_LDFLAGS}
.  include "../../mk/bsd.prefs.mk"
.  if ${OBJECT_FMT} == "a.out"
MAKE_FLAGS+=	OTHERLDFLAGS="${LDFLAGS:S/-Wl,//g}"
.  else
MAKE_FLAGS+=	OTHERLDFLAGS="${LDFLAGS}"
.  endif
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

# Skip appending to perllocal.pod.  We don't keep this consistent anyway
# with binary packages.
#
# XXX We should be adding to and removing from perllocal.pod in
# XXX VIEW-{INSTALL,DEINSTALL} actions from the INSTALL/DEINSTALL
# XXX scripts.
#
INSTALL_TARGET?=	pure_install

# Default test target for perl5 modules
TEST_TARGET?=	test

.endif	# _PERL5_MODULE_MK
