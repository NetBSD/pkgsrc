# $NetBSD: buildlink3.mk,v 1.15 2023/11/02 06:36:53 pho Exp $

BUILDLINK_TREE+=	hs-resourcet

.if !defined(HS_RESOURCET_BUILDLINK3_MK)
HS_RESOURCET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resourcet+=	hs-resourcet>=1.3.0
BUILDLINK_ABI_DEPENDS.hs-resourcet+=	hs-resourcet>=1.3.0nb3
BUILDLINK_PKGSRCDIR.hs-resourcet?=	../../devel/hs-resourcet

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-unliftio-core/buildlink3.mk"
.endif	# HS_RESOURCET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resourcet
