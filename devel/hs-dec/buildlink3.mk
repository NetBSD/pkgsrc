# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:31:52 pho Exp $

BUILDLINK_TREE+=	hs-dec

.if !defined(HS_DEC_BUILDLINK3_MK)
HS_DEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-dec+=	hs-dec>=0.0.5
BUILDLINK_ABI_DEPENDS.hs-dec+=	hs-dec>=0.0.5nb4
BUILDLINK_PKGSRCDIR.hs-dec?=	../../devel/hs-dec

.include "../../devel/hs-boring/buildlink3.mk"
.include "../../devel/hs-void/buildlink3.mk"
.endif	# HS_DEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-dec
