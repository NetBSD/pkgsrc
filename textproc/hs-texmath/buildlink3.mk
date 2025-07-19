# $NetBSD: buildlink3.mk,v 1.39 2025/07/19 20:47:04 wiz Exp $

BUILDLINK_TREE+=	hs-texmath

.if !defined(HS_TEXMATH_BUILDLINK3_MK)
HS_TEXMATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-texmath+=	hs-texmath>=0.12.10
BUILDLINK_ABI_DEPENDS.hs-texmath+=	hs-texmath>=0.12.10.3
BUILDLINK_PKGSRCDIR.hs-texmath?=	../../textproc/hs-texmath

.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-typst-symbols/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.endif	# HS_TEXMATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-texmath
