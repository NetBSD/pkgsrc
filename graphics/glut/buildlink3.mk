# $NetBSD: buildlink3.mk,v 1.19 2009/03/20 19:24:39 joerg Exp $

BUILDLINK_TREE+=	glut

.if !defined(GLUT_BUILDLINK3_MK)
GLUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glut+=	glut>=3.4.2
BUILDLINK_ABI_DEPENDS.glut+=	glut>=7.0.3
BUILDLINK_PKGSRCDIR.glut?=	../../graphics/glut

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.endif # GLUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-glut
