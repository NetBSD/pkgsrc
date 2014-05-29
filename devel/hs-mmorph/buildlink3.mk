# $NetBSD: buildlink3.mk,v 1.1 2014/05/29 22:06:00 szptvlfn Exp $

BUILDLINK_TREE+=	hs-mmorph

.if !defined(HS_MMORPH_BUILDLINK3_MK)
HS_MMORPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mmorph+=	hs-mmorph>=1.0.3
BUILDLINK_PKGSRCDIR.hs-mmorph?=	../../devel/hs-mmorph

.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_MMORPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mmorph
