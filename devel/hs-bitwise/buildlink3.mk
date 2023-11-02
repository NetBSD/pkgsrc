# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:36:20 pho Exp $

BUILDLINK_TREE+=	hs-bitwise

.if !defined(HS_BITWISE_BUILDLINK3_MK)
HS_BITWISE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bitwise+=	hs-bitwise>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-bitwise+=	hs-bitwise>=1.0.0.1nb1
BUILDLINK_PKGSRCDIR.hs-bitwise?=	../../devel/hs-bitwise
.endif	# HS_BITWISE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bitwise
