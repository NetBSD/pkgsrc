# $NetBSD: module.mk,v 1.1 2002/09/23 08:56:13 jlam Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install perl5 modules.
#
# The following targets are provided by this file:
#
# do-configure		runs the standard perl configuration in
#			each of the directories specified in
#			${PERL5_CONFIGURE_DIRS}.
#
# The following variables may be set prior to including this file:
#
# PERL5_CONFIGURE	if "YES", then run the standard perl
#			configuration assuming Makefile.PL exists;
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

.if defined(USE_BUILDLINK_ONLY)
.  include "../../lang/perl5/buildlink.mk"
.else
.  include "../../lang/perl5/buildlink2.mk"
.endif

PERL5_CONFIGURE?=	YES
PERL5_CONFIGURE_DIRS?=	${CONFIGURE_DIRS}

.if defined(PERL5_CONFIGURE) && !empty(PERL5_CONFIGURE:M[yY][eE][sS])
do-configure:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	for dir in ${PERL5_CONFIGURE_DIRS}; do				\
		if [ -f $$dir/Makefile.PL ]; then			\
			( cd $$dir && ${SETENV} ${MAKE_ENV}		\
			  ${PERL5} Makefile.PL ${MAKE_PARAMS});		\
		fi;							\
	done
.endif

# OTHERLDFLAGS is the hook provided by the perl5 MakeMaker module to allow
# customizing the LDFLAGS passed to the compiler/linker.
#
.if defined(PERL5_LDFLAGS) && !empty(PERL5_LDFLAGS)
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

.endif	# _PERL5_MODULE_MK
