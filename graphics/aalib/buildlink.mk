# $NetBSD: buildlink.mk,v 1.1 2002/01/03 01:29:54 hubertf Exp $
#
# This Makefile fragment is included by packages that use aalib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.aalib to the dependency pattern
#     for the version of aalib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(AALIB_BUILDLINK_MK)
aalib_BUILDLINK_MK= # defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.aalib?= aalib>=1.4rc4
DEPENDS+= ${BUILDLINK_DEPENDS.aalib}:../../graphics/aalib

EVAL_PREFIX+= BUILDLINK_PREFIX.aalib=aalib
BUILDLINK_PREFIX.aalib_DEFAULT= ${LOCALBASE}
BUILDLINK_FILES.aalib= include/aalib.h
BUILDLINK_FILES.aalib+= lib/libaa.*

BUILDLINK_TARGETS.aalib= aalib-buildlink
BUILDLINK_TARGETS.aalib+= aalib-buildlink-config-wrapper
BUILDLINK_TARGETS+= ${BUILDLINK_TARGETS.aalib}

BUILDLINK_CONFIG.aalib= ${BUILDLINK_PREFIX.aalib}/bin/aalib-config
BUILDLINK_CONFIG_WRAPPER.aalib= ${BUILDLINK_DIR}/bin/aalib-config
REPLACE_BUILDLINK_SED+= \
	-e "s|${BUILDLINK_CONFIG_WRAPPER.aalib}|${BUILDLINK_CONFIG.aalib}|g"

.if defined(USE_CONFIG_WRAPPER)
AALIB_CONFIG?= ${BUILDLINK_CONFIG_WRAPPER.aalib}
CONFIGURE_ENV+= AALIB_CONFIG="${AALIB_CONFIG}"
MAKE_ENV+= AALIB_CONFIG="${AALIB_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.aalib}
aalib-buildlink: _BUILDLINK_USE
aalib-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif # aalib_BUILDLINK_MK
