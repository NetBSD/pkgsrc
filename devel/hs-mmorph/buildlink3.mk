# $NetBSD: buildlink3.mk,v 1.3 2014/09/02 20:57:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-mmorph+=	hs-mmorph>=1.0.4
BUILDLINK_PKGSRCDIR.hs-mmorph?=	../../devel/hs-mmorph

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
