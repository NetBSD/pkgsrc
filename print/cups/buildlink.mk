# $NetBSD: buildlink.mk,v 1.11 2002/01/31 17:51:27 jlam Exp $
#
# This Makefile fragment is included by packages that use libcups.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.cups to the dependency pattern
#     for the version of cups desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CUPS_BUILDLINK_MK)
CUPS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.cups?=	cups>=1.1.1
DEPENDS+=	${BUILDLINK_DEPENDS.cups}:../../print/cups

EVAL_PREFIX+=		BUILDLINK_PREFIX.cups=cups
BUILDLINK_PREFIX.cups_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cups=	include/cups/*
BUILDLINK_FILES.cups+=	lib/libcups.*
BUILDLINK_FILES.cups+=	lib/libcupsimage.*

BUILDLINK_TARGETS.cups=		cups-buildlink
BUILDLINK_TARGETS.cups+=	cups-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.cups}

BUILDLINK_CONFIG.cups=		${BUILDLINK_PREFIX.cups}/bin/cups-config
BUILDLINK_CONFIG_WRAPPER.cups=	${BUILDLINK_DIR}/bin/cups-config
REPLACE_BUILDLINK_SED+=	\
	-e "s|${BUILDLINK_CONFIG_WRAPPER.cups}|${BUILDLINK_CONFIG.cups}|g"

.if defined(USE_CONFIG_WRAPPER)
CUPS_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.cups}
CONFIGURE_ENV+=		CUPS_CONFIG="${CUPS_CONFIG}"
MAKE_ENV+=		CUPS_CONFIG="${CUPS_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.cups}
cups-buildlink: _BUILDLINK_USE
cups-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# CUPS_BUILDLINK_MK
