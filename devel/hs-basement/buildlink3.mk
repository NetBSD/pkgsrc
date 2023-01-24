# $NetBSD: buildlink3.mk,v 1.7 2023/01/24 18:56:07 pho Exp $

BUILDLINK_TREE+=	hs-basement

.if !defined(HS_BASEMENT_BUILDLINK3_MK)
HS_BASEMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-basement+=	hs-basement>=0.0.15
BUILDLINK_ABI_DEPENDS.hs-basement+=	hs-basement>=0.0.15
BUILDLINK_PKGSRCDIR.hs-basement?=	../../devel/hs-basement
.endif	# HS_BASEMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-basement
