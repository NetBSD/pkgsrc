# $NetBSD: buildlink3.mk,v 1.19 2026/11/13 14:39:19 pho Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.8.9
BUILDLINK_ABI_DEPENDS.hs-tagged+=	hs-tagged>=0.8.9nb4
BUILDLINK_PKGSRCDIR.hs-tagged?=		../../devel/hs-tagged
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
