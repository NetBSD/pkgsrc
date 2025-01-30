# $NetBSD: buildlink3.mk,v 1.14 2025/01/30 05:18:44 pho Exp $

BUILDLINK_TREE+=	hs-data-default

.if !defined(HS_DATA_DEFAULT_BUILDLINK3_MK)
HS_DATA_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default+=	hs-data-default>=0.8.0
BUILDLINK_ABI_DEPENDS.hs-data-default+=	hs-data-default>=0.8.0.0
BUILDLINK_PKGSRCDIR.hs-data-default?=	../../devel/hs-data-default
.endif	# HS_DATA_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default
