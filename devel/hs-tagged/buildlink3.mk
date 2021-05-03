# $NetBSD: buildlink3.mk,v 1.6 2021/05/03 19:01:03 pho Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.8.6
BUILDLINK_ABI_DEPENDS.hs-tagged+=	hs-tagged>=0.8.6.1nb1
BUILDLINK_PKGSRCDIR.hs-tagged?=		../../devel/hs-tagged
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
