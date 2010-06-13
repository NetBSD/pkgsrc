# $NetBSD: buildlink3.mk,v 1.2 2010/06/13 22:44:33 wiz Exp $

BUILDLINK_TREE+=	glpng

.if !defined(GLPNG_BUILDLINK3_MK)
GLPNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glpng+=	glpng>=1.45.20081203
BUILDLINK_ABI_DEPENDS.glpng?=	glpng>=1.45.20081203nb1
BUILDLINK_PKGSRCDIR.glpng?=	../../graphics/glpng

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# GLPNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-glpng
