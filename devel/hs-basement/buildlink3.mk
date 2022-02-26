# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:57:49 pho Exp $

BUILDLINK_TREE+=	hs-basement

.if !defined(HS_BASEMENT_BUILDLINK3_MK)
HS_BASEMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-basement+=	hs-basement>=0.0.12
BUILDLINK_ABI_DEPENDS.hs-basement+=	hs-basement>=0.0.12nb2
BUILDLINK_PKGSRCDIR.hs-basement?=	../../devel/hs-basement
.endif	# HS_BASEMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-basement
