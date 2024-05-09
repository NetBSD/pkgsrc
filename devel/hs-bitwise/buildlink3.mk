# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:31:47 pho Exp $

BUILDLINK_TREE+=	hs-bitwise

.if !defined(HS_BITWISE_BUILDLINK3_MK)
HS_BITWISE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bitwise+=	hs-bitwise>=1.0.0
BUILDLINK_ABI_DEPENDS.hs-bitwise+=	hs-bitwise>=1.0.0.1nb2
BUILDLINK_PKGSRCDIR.hs-bitwise?=	../../devel/hs-bitwise
.endif	# HS_BITWISE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bitwise
