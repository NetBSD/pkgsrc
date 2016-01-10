# $NetBSD: buildlink3.mk,v 1.9 2016/01/10 11:48:24 szptvlfn Exp $

BUILDLINK_TREE+=	hs-hashable

.if !defined(HS_HASHABLE_BUILDLINK3_MK)
HS_HASHABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hashable+=	hs-hashable>=1.2.3
BUILDLINK_ABI_DEPENDS.hs-hashable+=	hs-hashable>=1.2.3.3
BUILDLINK_PKGSRCDIR.hs-hashable?=	../../devel/hs-hashable

.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_HASHABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hashable
