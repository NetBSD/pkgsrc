# $NetBSD: buildlink3.mk,v 1.3 2022/02/26 03:58:31 pho Exp $

BUILDLINK_TREE+=	hs-unicode-data

.if !defined(HS_UNICODE_DATA_BUILDLINK3_MK)
HS_UNICODE_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unicode-data+=	hs-unicode-data>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-unicode-data+=	hs-unicode-data>=0.3.0nb2
BUILDLINK_PKGSRCDIR.hs-unicode-data?=	../../textproc/hs-unicode-data
.endif	# HS_UNICODE_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unicode-data
