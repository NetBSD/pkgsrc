# $NetBSD: buildlink.mk,v 1.5 2002/01/15 23:55:38 rh Exp $
#
# This Makefile fragment is included by packages that use oaf.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.oaf to the dependency pattern
#     for the version of oaf desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(OAF_BUILDLINK_MK)
OAF_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.oaf?=	oaf>=0.6.7
DEPENDS+=	${BUILDLINK_DEPENDS.oaf}:../../devel/oaf

EVAL_PREFIX+=			BUILDLINK_PREFIX.oaf=oaf
BUILDLINK_PREFIX.oaf_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.oaf=		include/liboaf/*
BUILDLINK_FILES.oaf+=		lib/liboaf.*
BUILDLINK_FILES.oaf+=		lib/oafConf.sh

.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../devel/popt/buildlink.mk"

BUILDLINK_TARGETS.oaf=		oaf-buildlink
BUILDLINK_TARGETS.oaf+=		oaf-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.oaf}

BUILDLINK_CONFIG.oaf=	${BUILDLINK_PREFIX.oaf}/bin/oaf-config
BUILDLINK_CONFIG_WRAPPER.oaf=${BUILDLINK_DIR}/bin/oaf-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.oaf}|${BUILDLINK_CONFIG.oaf}|g"

.if defined(USE_CONFIG_WRAPPER)
OAF_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.oaf}
CONFIGURE_ENV+=		OAF_CONFIG="${OAF_CONFIG}"
MAKE_ENV+=		OAF_CONFIG="${OAF_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.oaf}
oaf-buildlink: _BUILDLINK_USE
oaf-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# OAF_BUILDLINK_MK
