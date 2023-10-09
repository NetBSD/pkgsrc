# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:54:08 pho Exp $

BUILDLINK_TREE+=	hs-bitarray

.if !defined(HS_BITARRAY_BUILDLINK3_MK)
HS_BITARRAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bitarray+=	hs-bitarray>=0.0.1
BUILDLINK_ABI_DEPENDS.hs-bitarray+=	hs-bitarray>=0.0.1.1nb6
BUILDLINK_PKGSRCDIR.hs-bitarray?=	../../devel/hs-bitarray
.endif	# HS_BITARRAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bitarray
