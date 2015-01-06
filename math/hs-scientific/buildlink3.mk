# $NetBSD: buildlink3.mk,v 1.7 2015/01/06 11:53:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-scientific

.if !defined(HS_SCIENTIFIC_BUILDLINK3_MK)
HS_SCIENTIFIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-scientific+=	hs-scientific>=0.3.3
BUILDLINK_ABI_DEPENDS.hs-scientific+=	hs-scientific>=0.3.3.4
BUILDLINK_PKGSRCDIR.hs-scientific?=	../../math/hs-scientific

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_SCIENTIFIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-scientific
