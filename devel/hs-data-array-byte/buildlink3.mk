# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:31:50 pho Exp $

BUILDLINK_TREE+=	hs-data-array-byte

.if !defined(HS_DATA_ARRAY_BYTE_BUILDLINK3_MK)
HS_DATA_ARRAY_BYTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-array-byte+=	hs-data-array-byte>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-data-array-byte+=	hs-data-array-byte>=0.1.0.1nb4
BUILDLINK_PKGSRCDIR.hs-data-array-byte?=	../../devel/hs-data-array-byte
.endif	# HS_DATA_ARRAY_BYTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-array-byte
