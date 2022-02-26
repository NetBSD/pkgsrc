# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:57:52 pho Exp $

BUILDLINK_TREE+=	hs-data-ordlist

.if !defined(HS_DATA_ORDLIST_BUILDLINK3_MK)
HS_DATA_ORDLIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-ordlist+=	hs-data-ordlist>=0.4.7.0
BUILDLINK_ABI_DEPENDS.hs-data-ordlist+=	hs-data-ordlist>=0.4.7.0nb1
BUILDLINK_PKGSRCDIR.hs-data-ordlist?=	../../devel/hs-data-ordlist
.endif	# HS_DATA_ORDLIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-ordlist
