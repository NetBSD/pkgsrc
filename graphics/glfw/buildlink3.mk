# $NetBSD: buildlink3.mk,v 1.2 2020/03/19 11:23:53 nia Exp $

BUILDLINK_TREE+=	glfw

.if !defined(GLFW_BUILDLINK3_MK)
GLFW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glfw+=	glfw>=3.1.2
BUILDLINK_PKGSRCDIR.glfw?=	../../graphics/glfw

pkgbase:= glfw

.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.glfw:Mx11)
.  include "../../x11/libX11/buildlink3.mk"
.  include "../../x11/libXrandr/buildlink3.mk"
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.endif

.endif	# GLFW_BUILDLINK3_MK

BUILDLINK_TREE+=	-glfw
