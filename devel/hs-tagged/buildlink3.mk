# $NetBSD: buildlink3.mk,v 1.4 2019/12/31 14:47:06 pho Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.8.6
BUILDLINK_ABI_DEPENDS.hs-tagged+=	hs-tagged>=0.8.6
BUILDLINK_PKGSRCDIR.hs-tagged?=		../../devel/hs-tagged

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
