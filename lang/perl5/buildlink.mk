# $NetBSD: buildlink.mk,v 1.13 2002/09/05 20:44:44 jlam Exp $
#
# This Makefile fragment is included by packages that use perl.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.perl to the dependency pattern
#     for the version of perl desired.
# (2) Include this Makefile fragment in the package Makefile,

.include "../../mk/bsd.buildlink.mk"

USE_PERL5?=		run

BUILDLINK_DEPENDS.perl?=	perl>=${PERL5_REQD}
BUILDLINK_PREFIX.perl?=	${LOCALBASE}
PERL5?=			${BUILDLINK_PREFIX.perl}/bin/perl

.if ${USE_PERL5} == "build"
BUILD_DEPENDS+=		${BUILDLINK_DEPENDS.perl}:${PERL5_PKGSRCDIR}
.else
DEPENDS+=		${BUILDLINK_DEPENDS.perl}:${PERL5_PKGSRCDIR}
.endif

.if defined(USE_BUILDLINK_ONLY)
BUILDLINK_TARGETS.perl=	perl-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.perl}

_CONFIG_PM=		${PERL5_ARCHLIB}/Config.pm
_BUILDLINK_CONFIG_PM=	${_CONFIG_PM:S/${BUILDLINK_PREFIX.perl}\//${BUILDLINK_DIR}\//}

_CPPFLAGS_INCDIRS?=	${CPPFLAGS:M-I*:S/^-I//}
_LDFLAGS_LIBDIRS?=	${LDFLAGS:M-L*:S/^-L//}

_CONFIG_PM_SED=	\
	-e "/^libpth=/s|${LOCALBASE}/lib|${_LDFLAGS_LIBDIRS}|g"		\
	-e "/^libspath=/s|${LOCALBASE}/lib|${_LDFLAGS_LIBDIRS}|g"	\
	-e "/^locincpth=/s|${LOCALBASE}/include|${_CPPFLAGS_INCDIRS}|g"	\
	-e "/^loclibpth=/s|${LOCALBASE}/lib|${_LDFLAGS_LIBDIRS}|g"	\
	-e "s|-I${LOCALBASE}/include|${CPPFLAGS:M-I*}|g"		\
	-e "s|-L${LOCALBASE}/lib|${LDFLAGS:M-L*}|g"

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
