# $NetBSD: buildlink.mk,v 1.1 2002/07/24 11:37:36 martti Exp $
#
# This Makefile fragment is included by packages that use libscsi.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libscsi to the dependency pattern
#     for the version of libscsi desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBSCSI_BUILDLINK_MK)
LIBSCSI_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libscsi?=		libscsi>=1.6
DEPENDS+=	${BUILDLINK_DEPENDS.libscsi}:../../devel/libscsi

EVAL_PREFIX+=	BUILDLINK_PREFIX.libscsi=libscsi
BUILDLINK_PREFIX.libscsi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libscsi=	include/scsi.h
BUILDLINK_FILES.libscsi+=	lib/libscsi.a

BUILDLINK_TARGETS.libscsi=	libscsi-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libscsi}

pre-configure: ${BUILDLINK_TARGETS}
libscsi-buildlink: _BUILDLINK_USE

.endif	# LIBSCSI_BUILDLINK_MK
