# $NetBSD: buildlink.mk,v 1.1 2001/06/22 05:46:26 jlam Exp $
#
# This Makefile fragment is included by packages that use imap-uw.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define IMAP_UW_REQD to the version of imap-uw desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(IMAP_UW_BUILDLINK_MK)
IMAP_UW_BUILDLINK_MK=	# defined

IMAP_UW_REQD?=		2000.0.3nb1
DEPENDS+=		imap-uw>=${IMAP_UW_REQD}:../../mail/imap-uw

BUILDLINK_PREFIX.imap-uw=	${LOCALBASE}
BUILDLINK_FILES.imap-uw=	include/c-client/*
BUILDLINK_FILES.imap-uw+=	lib/libc-client.*
BUILDLINK_FILES.imap-uw+=	lib/libc-client_pic.*
BUILDLINK_FILES.imap-uw+=	lib/libimapuw.*

BUILDLINK_TARGETS.imap-uw=	imap-uw-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.imap-uw}

pre-configure: ${BUILDLINK_TARGETS.imap-uw}
imap-uw-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# IMAP_UW_BUILDLINK_MK
