# $NetBSD: buildlink.mk,v 1.7 2001/12/15 08:30:26 martti Exp $
#
# This Makefile fragment is included by packages that use imap-uw.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.imap-uw to the dependency pattern
#     for the version of imap-uw desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(IMAP_UW_BUILDLINK_MK)
IMAP_UW_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.imap-uw?=	imap-uw>=2001.1
DEPENDS+=	${BUILDLINK_DEPENDS.imap-uw}:../../mail/imap-uw

EVAL_PREFIX+=			BUILDLINK_PREFIX.imap-uw=imap-uw
BUILDLINK_PREFIX.imap-uw_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.imap-uw=	include/c-client/*
BUILDLINK_FILES.imap-uw+=	lib/libc-client.*
BUILDLINK_FILES.imap-uw+=	lib/libc-client_pic.*
BUILDLINK_FILES.imap-uw+=	lib/libimapuw.*

BUILDLINK_TARGETS.imap-uw=	imap-uw-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.imap-uw}

pre-configure: ${BUILDLINK_TARGETS.imap-uw}
imap-uw-buildlink: _BUILDLINK_USE

.endif	# IMAP_UW_BUILDLINK_MK
