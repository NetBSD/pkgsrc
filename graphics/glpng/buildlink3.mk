# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/01 21:07:37 wiz Exp $

BUILDLINK_TREE+=	glpng

.if !defined(GLPNG_BUILDLINK3_MK)
GLPNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glpng+=	glpng>=1.45.20081203
BUILDLINK_PKGSRCDIR.glpng?=	../../graphics/glpng

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# GLPNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-glpng
