# $NetBSD: buildlink.mk,v 1.1 2002/01/16 01:37:48 rh Exp $
#
# This Makefile fragment is included by packages that use bonobo-conf.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.bonobo-conf to the dependency pattern
#     for the version of bonobo-conf desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(BONOBO_CONF_BUILDLINK_MK)
BONOBO_CONF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.bonobo-conf?=	bonobo-conf>0.14
DEPENDS+=	${BUILDLINK_DEPENDS.bonobo-conf}:../../devel/bonobo-conf

EVAL_PREFIX+=			BUILDLINK_PREFIX.bonobo-conf=bonobo-conf
BUILDLINK_PREFIX.bonobo-conf_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.bonobo-conf=		include/bonobo-conf/*
BUILDLINK_FILES.bonobo-conf+=		lib/bonobo/monikers/libmoniker_config*
BUILDLINK_FILES.bonobo-conf+=		lib/bonobo/monikers/libmoniker_gconf*
BUILDLINK_FILES.bonobo-conf+=		lib/bonobo_conf*
BUILDLINK_FILES.bonobo-conf+=		lib/libbonobo_conf*

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/GConf/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../devel/oaf/buildlink.mk"
.include "../../mk/x11.buildlink.mk"

BUILDLINK_TARGETS.bonobo-conf=	bonobo-conf-buildlink
BUILDLINK_TARGETS.bonobo-conf+=	bonobo-conf-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.bonobo-conf}

BUILDLINK_CONFIG.bonobo-conf=	${BUILDLINK_PREFIX.bonobo-conf}/lib/bonobo_confConf.sh
BUILDLINK_CONFIG_WRAPPER.bonobo-conf=${BUILDLINK_DIR}/lib/bonobo_confConf.sh
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.bonobo-conf}|${BUILDLINK_CONFIG.bonobo-conf}|g"

.if defined(USE_CONFIG_WRAPPER)
BONOBO_CONF_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.bonobo-conf}
CONFIGURE_ENV+=		BONOBO_CONF_CONFIG="${BONOBO_CONF_CONFIG}"
MAKE_ENV+=		BONOBO_CONF_CONFIG="${BONOBO_CONF_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.bonobo-conf}
bonobo-conf-buildlink: _BUILDLINK_USE
bonobo-conf-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# BONOBO_CONF_BUILDLINK_MK
