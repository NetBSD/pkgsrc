# $NetBSD: buildlink3.mk,v 1.10 2013/05/04 14:32:20 rodent Exp $

BUILDLINK_TREE+=	freeglut

.if !defined(FREEGLUT_BUILDLINK3_MK)
FREEGLUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freeglut+=	freeglut>=2.2.0
BUILDLINK_ABI_DEPENDS.freeglut+=	freeglut>=2.2.0nb3
BUILDLINK_PKGSRCDIR.freeglut?=	../../graphics/freeglut

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # FREEGLUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-freeglut
