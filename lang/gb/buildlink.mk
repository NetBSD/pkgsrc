# $NetBSD: buildlink.mk,v 1.2 2001/10/03 20:56:51 jlam Exp $
#
# This Makefile fragment is included by packages that use gb.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gb to the dependency pattern
#     for the version of gb desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GB_BUILDLINK_MK)
GB_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gb?=		gb>=0.0.20
DEPENDS+=	${BUILDLINK_DEPENDS.gb}:../../lang/gb

EVAL_PREFIX+=			BUILDLINK_PREFIX.gb=gb
BUILDLINK_PREFIX.gb_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.gb=	include/gb/*
BUILDLINK_FILES.gb+=	include/gbrun/*
BUILDLINK_FILES.gb+=	lib/libgbrun.*

.include "../../print/gnome-print/buildlink.mk"

BUILDLINK_TARGETS.gb=	gb-buildlink
BUILDLINK_TARGETS.gb+=	gb-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.gb}

BUILDLINK_CONFIG.gb=		${BUILDLINK_PREFIX.gb}/lib/gbConf.sh
BUILDLINK_CONFIG_WRAPPER.gb=	${BUILDLINK_DIR}/lib/gbConf.sh
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.gb}|${BUILDLINK_CONFIG.gb}|g"

.if defined(USE_CONFIG_WRAPPER)
GB_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.gb}
CONFIGURE_ENV+=		GB_CONFIG="${GB_CONFIG}"
MAKE_ENV+=		GB_CONFIG="${GB_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.gb}
gb-buildlink: _BUILDLINK_USE
gb-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
libart-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# GB_BUILDLINK_MK
