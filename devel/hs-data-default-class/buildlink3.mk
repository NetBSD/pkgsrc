# $NetBSD: buildlink3.mk,v 1.15 2025/08/13 11:06:36 pho Exp $

BUILDLINK_TREE+=	hs-data-default-class

.if !defined(HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK)
HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default-class+=	hs-data-default-class>=0.2.0
BUILDLINK_ABI_DEPENDS.hs-data-default-class+=	hs-data-default-class>=0.2.0.0nb3
BUILDLINK_PKGSRCDIR.hs-data-default-class?=	../../devel/hs-data-default-class

.include "../../devel/hs-data-default/buildlink3.mk"
.endif	# HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default-class
