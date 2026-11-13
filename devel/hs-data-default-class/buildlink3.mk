# $NetBSD: buildlink3.mk,v 1.16 2026/11/13 14:38:54 pho Exp $

BUILDLINK_TREE+=	hs-data-default-class

.if !defined(HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK)
HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default-class+=	hs-data-default-class>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-data-default-class+=	hs-data-default-class>=0.2.0.0nb4
BUILDLINK_PKGSRCDIR.hs-data-default-class?=	../../devel/hs-data-default-class

.include "../../devel/hs-data-default/buildlink3.mk"
.endif	# HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default-class
