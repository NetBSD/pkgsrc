# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:08:40 szptvlfn Exp $

BUILDLINK_TREE+=	hs-tagged

.if !defined(HS_TAGGED_BUILDLINK3_MK)
HS_TAGGED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tagged+=	hs-tagged>=0.7.2
BUILDLINK_ABI_DEPENDS.hs-tagged+=	hs-tagged>=0.7.2
BUILDLINK_PKGSRCDIR.hs-tagged?=	../../devel/hs-tagged
.endif	# HS_TAGGED_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tagged
