# $NetBSD: buildlink3.mk,v 1.6 2025/08/13 11:06:31 pho Exp $

BUILDLINK_TREE+=	hs-bitwise

.if !defined(HS_BITWISE_BUILDLINK3_MK)
HS_BITWISE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bitwise+=	hs-bitwise>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-bitwise+=	hs-bitwise>=1.0.0.1nb5
BUILDLINK_PKGSRCDIR.hs-bitwise?=	../../devel/hs-bitwise
.endif	# HS_BITWISE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bitwise
