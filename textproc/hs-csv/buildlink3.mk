# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:25 pho Exp $

BUILDLINK_TREE+=	hs-csv

.if !defined(HS_CSV_BUILDLINK3_MK)
HS_CSV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-csv+=	hs-csv>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-csv+=	hs-csv>=0.1.2nb2
BUILDLINK_PKGSRCDIR.hs-csv?=	../../textproc/hs-csv
.endif	# HS_CSV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-csv
