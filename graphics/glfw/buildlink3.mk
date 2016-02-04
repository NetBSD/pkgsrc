# $NetBSD: buildlink3.mk,v 1.1 2016/02/04 11:38:10 leot Exp $

BUILDLINK_TREE+=	glfw

.if !defined(GLFW_BUILDLINK3_MK)
GLFW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glfw+=	glfw>=3.1.2
BUILDLINK_PKGSRCDIR.glfw?=	../../graphics/glfw

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# GLFW_BUILDLINK3_MK

BUILDLINK_TREE+=	-glfw
