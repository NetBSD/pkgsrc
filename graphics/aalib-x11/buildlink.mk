# $NetBSD: buildlink.mk,v 1.3 2002/08/27 18:18:33 jlam Exp $
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

.if !defined(AALIB_X11_BUILDLINK_MK)
AALIB_X11_BUILDLINK_MK= # defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.aalib-x11?= aalib-x11>=1.4.0.4
DEPENDS+=	${BUILDLINK_DEPENDS.aalib-x11}:../../graphics/aalib-x11

EVAL_PREFIX+=	BUILDLINK_PREFIX.aalib-x11=aalib-x11
BUILDLINK_PREFIX.aalib-x11_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.aalib-x11=	include/aalib-x11.h
BUILDLINK_FILES.aalib-x11+=	lib/libaa-x11.*
BUILDLINK_TRANSFORM.aalib-x11=	-e "s|/aalib-x11.h|/aalib.h|g"
BUILDLINK_TRANSFORM.aalib-x11+=	-e "s|libaa-x11\.|libaa.|g"
REPLACE_LIBNAMES_SED+=		-e "s|-laa|-laa-x11|g"

BUILDLINK_TARGETS.aalib-x11=	aalib-x11-buildlink
BUILDLINK_TARGETS.aalib-x11+=	aalib-x11-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.aalib-x11}

BUILDLINK_CONFIG.aalib-x11=	${BUILDLINK_PREFIX.aalib-x11}/bin/aalib-x11-config
BUILDLINK_CONFIG_WRAPPER.aalib-x11=	${BUILDLINK_DIR}/bin/aalib-x11-config
REPLACE_BUILDLINK_SED+= \
	-e "s|${BUILDLINK_CONFIG_WRAPPER.aalib-x11}|${BUILDLINK_CONFIG.aalib-x11}|g"

.if defined(USE_CONFIG_WRAPPER)
AALIB_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.aalib-x11}
CONFIGURE_ENV+=		AALIB_CONFIG="${AALIB_CONFIG}"
MAKE_ENV+=		AALIB_CONFIG="${AALIB_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.aalib-x11}
aalib-x11-buildlink: _BUILDLINK_USE
aalib-x11-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif # AALIB_X11_BUILDLINK_MK
