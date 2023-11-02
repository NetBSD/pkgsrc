# $NetBSD: buildlink3.mk,v 1.13 2023/11/02 06:36:58 pho Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.8.8
BUILDLINK_ABI_DEPENDS.hs-tagged+=	hs-tagged>=0.8.8nb1
BUILDLINK_PKGSRCDIR.hs-tagged?=		../../devel/hs-tagged
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
