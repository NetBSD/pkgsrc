# $NetBSD: buildlink.mk,v 1.1 2001/11/24 04:40:31 jlam Exp $
#
# This Makefile fragment is included by packages that use perl.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.perl to the dependency pattern
#     for the version of perl desired.
# (2) Include this Makefile fragment in the package Makefile,

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.perl?=	perl>=${PERL5_REQD}
DEPENDS+=		${BUILDLINK_DEPENDS.perl}:../../lang/perl5

PERL5?=			${BUILDLINK_PREFIX.perl}/bin/perl
PERL5_REQD?=		5.0

BUILDLINK_PREFIX.perl?=	${LOCALBASE}

BUILDLINK_TARGETS.perl=	perl-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.perl}

_CONFIG_PM=		${PERL5_ARCHLIB}/Config.pm
_BUILDLINK_CONFIG_PM=	${_CONFIG_PM:S/${BUILDLINK_PREFIX.perl}\//${BUILDLINK_DIR}\//}

_CONFIG_PM_SED=	\
	-e "s|-I${LOCALBASE}/include|-I${BUILDLINK_DIR}/include|g"	\
	-e "s|-L${LOCALBASE}/lib|-L${BUILDLINK_DIR}/lib|g"

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
	
PERL5OPT+=		-I${PERL5_ARCHLIB:S/${BUILDLINK_PREFIX.perl}\//${BUILDLINK_DIR}\//}
MAKE_ENV+=		PERL5OPT="${PERL5OPT}"

pre-configure: perl-buildlink

perl-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.perl_buildlink_done;			\
	if [ ! -f $${cookie} ]; then					\
		${ECHO_MSG} "Creating ${_BUILDLINK_CONFIG_PM}.";	\
		${MKDIR} ${_BUILDLINK_CONFIG_PM:H};			\
		${SED} ${_CONFIG_PM_SED} ${_CONFIG_PM}			\
			> ${_BUILDLINK_CONFIG_PM};			\
		${ECHO} ${_BUILDLINK_CONFIG_PM} >> $${cookie};		\
	fi
