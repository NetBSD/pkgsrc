# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/13 20:00:30 dillo Exp $
#
# This Makefile fragment is included by packages that use physfs.
#

.if !defined(PHYSFS_BUILDLINK2_MK)
PHYSFS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			physfs
BUILDLINK_DEPENDS.physfs?=		physfs>=0.1.8
BUILDLINK_PKGSRCDIR.physfs?=		../../devel/physfs

EVAL_PREFIX+=	BUILDLINK_PREFIX.physfs=physfs
BUILDLINK_PREFIX.physfs_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.physfs+=	include/physfs.h
BUILDLINK_FILES.physfs+=	lib/libphysfs.*

.include "../../devel/readline/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=	physfs-buildlink

physfs-buildlink: _BUILDLINK_USE

.endif	# PHYSFS_BUILDLINK2_MK
