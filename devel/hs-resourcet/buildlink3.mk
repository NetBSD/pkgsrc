# $NetBSD: buildlink3.mk,v 1.17 2025/02/02 13:05:20 pho Exp $

BUILDLINK_TREE+=	hs-resourcet

.if !defined(HS_RESOURCET_BUILDLINK3_MK)
HS_RESOURCET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resourcet+=	hs-resourcet>=1.3.0
BUILDLINK_ABI_DEPENDS.hs-resourcet+=	hs-resourcet>=1.3.0nb5
BUILDLINK_PKGSRCDIR.hs-resourcet?=	../../devel/hs-resourcet

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.endif	# HS_RESOURCET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resourcet
