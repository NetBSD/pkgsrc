# $NetBSD: buildlink3.mk,v 1.3 2011/01/13 13:36:12 wiz Exp $

BUILDLINK_TREE+=	glpng

.if !defined(GLPNG_BUILDLINK3_MK)
GLPNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glpng+=	glpng>=1.45.20081203
BUILDLINK_ABI_DEPENDS.glpng?=	glpng>=1.45.20081203nb2
BUILDLINK_PKGSRCDIR.glpng?=	../../graphics/glpng

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# GLPNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-glpng
