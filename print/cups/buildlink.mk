# $NetBSD: buildlink.mk,v 1.6 2001/06/11 01:59:37 jlam Exp $
#
# This Makefile fragment is included by packages that use libcups.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define CUPS_REQD to the version of cups desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CUPS_BUILDLINK_MK)
CUPS_BUILDLINK_MK=	# defined

CUPS_REQD?=		1.1.1
DEPENDS+=		cups>=${CUPS_REQD}:../../print/cups

BUILDLINK_PREFIX.cups=	${LOCALBASE}
BUILDLINK_FILES.cups=	include/cups/*
BUILDLINK_FILES.cups+=	lib/libcups.*
BUILDLINK_FILES.cups+=	lib/libcupsimage.*

BUILDLINK_TARGETS.cups=	cups-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.cups}

pre-configure: ${BUILDLINK_TARGETS.cups}
cups-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# CUPS_BUILDLINK_MK
