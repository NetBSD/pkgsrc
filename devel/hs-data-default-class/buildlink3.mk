# $NetBSD: buildlink3.mk,v 1.10 2023/11/02 06:36:25 pho Exp $

BUILDLINK_TREE+=	hs-data-default-class

.if !defined(HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK)
HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default-class+=	hs-data-default-class>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-data-default-class+=	hs-data-default-class>=0.1.2.0nb7
BUILDLINK_PKGSRCDIR.hs-data-default-class?=	../../devel/hs-data-default-class
.endif	# HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default-class
