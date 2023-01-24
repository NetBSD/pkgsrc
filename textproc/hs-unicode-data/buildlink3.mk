# $NetBSD: buildlink3.mk,v 1.4 2023/01/24 12:12:11 pho Exp $

BUILDLINK_TREE+=	hs-unicode-data

.if !defined(HS_UNICODE_DATA_BUILDLINK3_MK)
HS_UNICODE_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-data+=	hs-unicode-data>=0.4
BUILDLINK_ABI_DEPENDS.hs-unicode-data+=	hs-unicode-data>=0.4.0.1
BUILDLINK_PKGSRCDIR.hs-unicode-data?=	../../textproc/hs-unicode-data
.endif	# HS_UNICODE_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-data
