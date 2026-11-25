# $NetBSD: buildlink3.mk,v 1.7 2026/11/25 14:42:12 wiz Exp $

BUILDLINK_TREE+=	glpng

.if !defined(GLPNG_BUILDLINK3_MK)
GLPNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glpng+=	glpng>=1.45.20081203
BUILDLINK_ABI_DEPENDS.glpng+=	glpng>=1.46nb1
BUILDLINK_PKGSRCDIR.glpng?=	../../graphics/glpng

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/mesa.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.endif	# GLPNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-glpng
