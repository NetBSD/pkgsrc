# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:08:40 szptvlfn Exp $

BUILDLINK_TREE+=	hs-uniplate

.if !defined(HS_UNIPLATE_BUILDLINK3_MK)
HS_UNIPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uniplate+=	hs-uniplate>=1.6.12
BUILDLINK_ABI_DEPENDS.hs-uniplate+=	hs-uniplate>=1.6.12
BUILDLINK_PKGSRCDIR.hs-uniplate?=	../../devel/hs-uniplate

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_UNIPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uniplate
