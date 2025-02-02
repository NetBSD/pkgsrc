# $NetBSD: buildlink3.mk,v 1.10 2025/02/02 13:06:00 pho Exp $

BUILDLINK_TREE+=	hs-unicode-data

.if !defined(HS_UNICODE_DATA_BUILDLINK3_MK)
HS_UNICODE_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-data+=	hs-unicode-data>=0.6.0
BUILDLINK_ABI_DEPENDS.hs-unicode-data+=	hs-unicode-data>=0.6.0nb1
BUILDLINK_PKGSRCDIR.hs-unicode-data?=	../../textproc/hs-unicode-data
.endif	# HS_UNICODE_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-data
