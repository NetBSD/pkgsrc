# $NetBSD: buildlink3.mk,v 1.14 2024/05/09 01:32:14 pho Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.8.8
BUILDLINK_ABI_DEPENDS.hs-tagged+=	hs-tagged>=0.8.8nb2
BUILDLINK_PKGSRCDIR.hs-tagged?=		../../devel/hs-tagged
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
