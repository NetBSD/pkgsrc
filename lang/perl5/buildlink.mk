# $NetBSD: buildlink.mk,v 1.7 2001/11/30 17:21:56 jlam Exp $
#
# This Makefile fragment is included by packages that use perl.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.perl to the dependency pattern
#     for the version of perl desired.
# (2) Include this Makefile fragment in the package Makefile,

.include "../../mk/bsd.buildlink.mk"

PERL5_REQD?=			5.0
BUILDLINK_DEPENDS.perl?=	perl>=${PERL5_REQD}

BUILDLINK_PREFIX.perl?=	${LOCALBASE}
PERL5?=			${BUILDLINK_PREFIX.perl}/bin/perl

DEPENDS+=		${BUILDLINK_DEPENDS.perl}:../../lang/perl5

.if exists(${PERL5})
.  if exists(${BUILDLINK_PREFIX.perl}/share/mk/bsd.perl.mk)
.    include "${BUILDLINK_PREFIX.perl}/share/mk/bsd.perl.mk"
.  elif !defined(PERL5_SITELIB) || !defined(PERL5_SITEARCH) || !defined(PERL5_ARCHLIB)
PERL5_SITELIB!=		eval `${PERL5} -V:installsitelib 2>/dev/null`;	\
			${ECHO} $${installsitelib}
PERL5_SITEARCH!=	eval `${PERL5} -V:installsitearch 2>/dev/null`;	\
			${ECHO} $${installsitearch}
PERL5_ARCHLIB!=		eval `${PERL5} -V:installarchlib 2>/dev/null`;	\
			${ECHO} $${installarchlib}
MAKEFLAGS+=		PERL5_SITELIB=${PERL5_SITELIB}
MAKEFLAGS+=		PERL5_SITEARCH=${PERL5_SITEARCH}
MAKEFLAGS+=		PERL5_ARCHLIB=${PERL5_ARCHLIB}
.  endif # !exists(bsd.perl.mk) && !defined(PERL5_*)
.endif # exists($PERL5)

.if defined(USE_BUILDLINK_ONLY)
BUILDLINK_TARGETS.perl=	perl-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.perl}

_CONFIG_PM=		${PERL5_ARCHLIB}/Config.pm
_BUILDLINK_CONFIG_PM=	${_CONFIG_PM:S/${BUILDLINK_PREFIX.perl}\//${BUILDLINK_DIR}\//}

_CPPFLAGS_LIBDIRS?=	${CPPFLAGS:M-I*:S/^-I//}
_LDFLAGS_LIBDIRS?=	${LDFLAGS:M-L*:S/^-L//}

_CONFIG_PM_SED=	\
	-e "/^libpth=/s|${LOCALBASE}/lib|${_LDFLAGS_LIBDIRS}|g"		\
	-e "/^libspath=/s|${LOCALBASE}/lib|${_LDFLAGS_LIBDIRS}|g"	\
	-e "/^locincpth=/s|${LOCALBASE}/include|${_CPPFLAGS_LIBDIRS}|g"	\
	-e "/^loclibpth=/s|${LOCALBASE}/lib|${_LDFLAGS_LIBDIRS}|g"	\
	-e "s|-I${LOCALBASE}/include|${CPPFLAGS}|g"			\
	-e "s|-L${LOCALBASE}/lib|${LDFLAGS}|g"

REPLACE_RPATH_SED+=	-e "/^LD_RUN_PATH/s|${BUILDLINK_DIR}|${LOCALBASE}|g"
REPLACE_RPATH_SED+=	-e "/^LD_RUN_PATH/s|${BUILDLINK_X11_DIR}|${X11BASE}|g"

PERL5OPT+=		-I${PERL5_ARCHLIB:S/${BUILDLINK_PREFIX.perl}\//${BUILDLINK_DIR}\//}
CONFIGURE_ENV+=		PERL5OPT="${PERL5OPT}"
MAKE_ENV+=		PERL5OPT="${PERL5OPT}"
.endif	# USE_BUILDLINK_ONLY

pre-configure: ${BUILDLINK_TARGETS.perl}

perl-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.perl_buildlink_done;			\
	if [ ! -f $${cookie} ]; then					\
		${ECHO_BUILDLINK_MSG} "Creating ${_BUILDLINK_CONFIG_PM}.";	\
		${MKDIR} ${_BUILDLINK_CONFIG_PM:H};			\
		${SED} ${_CONFIG_PM_SED} ${_CONFIG_PM}			\
			> ${_BUILDLINK_CONFIG_PM};			\
		${ECHO} ${_BUILDLINK_CONFIG_PM} >> $${cookie};		\
	fi
