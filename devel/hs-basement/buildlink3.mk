# $NetBSD: buildlink3.mk,v 1.2 2021/05/03 19:00:55 pho Exp $

BUILDLINK_TREE+=	hs-basement

.if !defined(HS_BASEMENT_BUILDLINK3_MK)
HS_BASEMENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-basement+=	hs-basement>=0.0.11
BUILDLINK_ABI_DEPENDS.hs-basement+=	hs-basement>=0.0.11nb1
BUILDLINK_PKGSRCDIR.hs-basement?=	../../devel/hs-basement
.endif	# HS_BASEMENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-basement
