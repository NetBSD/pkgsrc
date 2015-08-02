# $NetBSD: buildlink3.mk,v 1.16 2015/08/02 11:27:06 szptvlfn Exp $

BUILDLINK_TREE+=	hs-texmath

.if !defined(HS_TEXMATH_BUILDLINK3_MK)
HS_TEXMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-texmath+=	hs-texmath>=0.8
BUILDLINK_ABI_DEPENDS.hs-texmath+=	hs-texmath>=0.8nb15
BUILDLINK_PKGSRCDIR.hs-texmath?=	../../textproc/hs-texmath

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.endif	# HS_TEXMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-texmath
