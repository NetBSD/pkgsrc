# $NetBSD: buildlink.mk,v 1.1.1.1 2002/01/30 11:31:42 agc Exp $
#
# This Makefile fragment is included by packages that use aalib-x11.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.aalib-x11 to the dependency pattern
#     for the version of aalib-x11 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(AALIB-X11_BUILDLINK_MK)
aalib-x11_BUILDLINK_MK= # defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.aalib-x11?= aalib-x11>=1.4.0.4
DEPENDS+=	${BUILDLINK_DEPENDS.aalib-x11}:../../graphics/aalib-x11

EVAL_PREFIX+=	BUILDLINK_PREFIX.aalib-x11=aalib-x11
BUILDLINK_PREFIX.aalib-x11_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.aalib-x11=	include/aalib.h
BUILDLINK_FILES.aalib-x11+=	lib/libaa.*

BUILDLINK_TARGETS.aalib-x11=	aalib-x11-buildlink
BUILDLINK_TARGETS.aalib-x11+=	aalib-x11-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.aalib-x11}

BUILDLINK_CONFIG.aalib-x11=	${BUILDLINK_PREFIX.aalib-x11}/bin/aalib-config
BUILDLINK_CONFIG_WRAPPER.aalib-x11=	${BUILDLINK_DIR}/bin/aalib-config
REPLACE_BUILDLINK_SED+= \
	-e "s|${BUILDLINK_CONFIG_WRAPPER.aalib-x11}|${BUILDLINK_CONFIG.aalib-x11}|g"

.if defined(USE_CONFIG_WRAPPER)
AALIB-X11_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.aalib-x11}
CONFIGURE_ENV+=		AALIB-X11_CONFIG="${AALIB-X11_CONFIG}"
MAKE_ENV+=		AALIB-X11_CONFIG="${AALIB-X11_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.aalib-x11}
aalib-x11-buildlink: _BUILDLINK_USE
aalib-x11-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif # aalib-x11_BUILDLINK_MK
