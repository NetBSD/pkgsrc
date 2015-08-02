# $NetBSD: buildlink3.mk,v 1.8 2015/08/02 11:27:04 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.2.3
BUILDLINK_ABI_DEPENDS.hs-hashable+=	hs-hashable>=1.2.3.2nb1
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../devel/hs-hashable

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
