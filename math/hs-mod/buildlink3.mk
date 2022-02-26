# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:17 pho Exp $

BUILDLINK_TREE+=	hs-mod

.if !defined(HS_MOD_BUILDLINK3_MK)
HS_MOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mod+=	hs-mod>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-mod+=	hs-mod>=0.1.2.2nb1
BUILDLINK_PKGSRCDIR.hs-mod?=	../../math/hs-mod

.include "../../math/hs-semirings/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_MOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mod
