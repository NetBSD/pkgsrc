# $NetBSD: buildlink2.mk,v 1.3 2003/12/06 00:28:21 xtraeme Exp $
#
# This Makefile fragment is included by packages that use opencdk.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(OPENCDK_BUILDLINK2_MK)
OPENCDK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			opencdk
BUILDLINK_DEPENDS.opencdk?=		opencdk>=0.5.3
BUILDLINK_PKGSRCDIR.opencdk?=		../../security/opencdk

EVAL_PREFIX+=	BUILDLINK_PREFIX.opencdk=opencdk
BUILDLINK_PREFIX.opencdk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.opencdk+=	include/opencdk.h
BUILDLINK_FILES.opencdk+=	lib/libopencdk.*

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/libgcrypt/buildlink2.mk"

BUILDLINK_TARGETS+=	opencdk-buildlink

opencdk-buildlink: _BUILDLINK_USE

.endif	# OPENCDK_BUILDLINK2_MK
