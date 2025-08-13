# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:07:11 pho Exp $

BUILDLINK_TREE+=	hs-language-glsl

.if !defined(HS_LANGUAGE_GLSL_BUILDLINK3_MK)
HS_LANGUAGE_GLSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-language-glsl+=	hs-language-glsl>=0.3.0
BUILDLINK_ABI_DEPENDS.hs-language-glsl+=	hs-language-glsl>=0.3.0nb1
BUILDLINK_PKGSRCDIR.hs-language-glsl?=		../../lang/hs-language-glsl

.include "../../devel/hs-prettyclass/buildlink3.mk"
.endif	# HS_LANGUAGE_GLSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-language-glsl
