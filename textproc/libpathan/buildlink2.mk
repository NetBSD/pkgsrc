# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/02/12 02:41:18 minskim Exp $
#
# This Makefile fragment is included by packages that use libpathan.
#

.if !defined(LIBPATHAN_BUILDLINK2_MK)
LIBPATHAN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libpathan
BUILDLINK_DEPENDS.libpathan?=		libpathan>=1.2.2
BUILDLINK_PKGSRCDIR.libpathan?=		../../wip/libpathan

EVAL_PREFIX+=	BUILDLINK_PREFIX.libpathan=libpathan
BUILDLINK_PREFIX.libpathan_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libpathan+=	include/pathan/*.hpp
BUILDLINK_FILES.libpathan+=	include/pathan/ext/*.hpp
BUILDLINK_FILES.libpathan+=	lib/libpathan.*

.include "../../textproc/xerces-c/buildlink2.mk"

BUILDLINK_TARGETS+=	libpathan-buildlink

libpathan-buildlink: _BUILDLINK_USE

.endif	# LIBPATHAN_BUILDLINK2_MK
