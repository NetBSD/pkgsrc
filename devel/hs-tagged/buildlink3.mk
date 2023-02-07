# $NetBSD: buildlink3.mk,v 1.10 2023/02/07 01:40:51 pho Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.8.6
BUILDLINK_ABI_DEPENDS.hs-tagged+=	hs-tagged>=0.8.6.1nb5
BUILDLINK_PKGSRCDIR.hs-tagged?=		../../devel/hs-tagged
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
