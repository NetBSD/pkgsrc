# $NetBSD: buildlink3.mk,v 1.6 2025/01/30 15:43:39 pho Exp $

BUILDLINK_TREE+=	hs-dec

.if !defined(HS_DEC_BUILDLINK3_MK)
HS_DEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dec+=	hs-dec>=0.0.6
BUILDLINK_ABI_DEPENDS.hs-dec+=	hs-dec>=0.0.6
BUILDLINK_PKGSRCDIR.hs-dec?=	../../devel/hs-dec

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-void/buildlink3.mk"
.endif	# HS_DEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dec
