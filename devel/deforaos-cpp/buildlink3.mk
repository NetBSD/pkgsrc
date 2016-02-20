# $NetBSD: buildlink3.mk,v 1.1 2016/02/20 02:54:45 khorben Exp $
#

BUILDLINK_TREE+=	deforaos-cpp

.if !defined(DEFORAOS_CPP_BUILDLINK3_MK)
DEFORAOS_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-cpp+=	deforaos-cpp>=0.0.3
BUILDLINK_ABI_DEPENDS.deforaos-cpp?=	deforaos-cpp>=0.0.3
BUILDLINK_PKGSRCDIR.deforaos-cpp?=	../../x11/deforaos-cpp

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.endif	# DEFORAOS_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-cpp
