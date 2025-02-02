# $NetBSD: buildlink3.mk,v 1.15 2025/02/02 13:05:02 pho Exp $

BUILDLINK_TREE+=	hs-data-default

.if !defined(HS_DATA_DEFAULT_BUILDLINK3_MK)
HS_DATA_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default+=	hs-data-default>=0.8.0
BUILDLINK_ABI_DEPENDS.hs-data-default+=	hs-data-default>=0.8.0.0nb1
BUILDLINK_PKGSRCDIR.hs-data-default?=	../../devel/hs-data-default
.endif	# HS_DATA_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default
