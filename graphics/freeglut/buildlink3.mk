# $NetBSD: buildlink3.mk,v 1.14 2019/10/03 11:17:51 nia Exp $

BUILDLINK_TREE+=	freeglut

.if !defined(FREEGLUT_BUILDLINK3_MK)
FREEGLUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.freeglut+=	freeglut>=2.2.0
BUILDLINK_ABI_DEPENDS.freeglut+=	freeglut>=2.8.1nb1
BUILDLINK_PKGSRCDIR.freeglut?=		../../graphics/freeglut

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"

pkgbase:=	freeglut

.include "../../mk/pkg-build-options.mk"

.  if !empty(PKG_BUILD_OPTIONS.freeglut:Mwayland)
.    include "../../devel/wayland/buildlink3.mk"
. endif

.  if !empty(PKG_BUILD_OPTIONS.freeglut:Mx11)
.    include "../../x11/libXi/buildlink3.mk"
.    include "../../x11/libXrandr/buildlink3.mk"
.    include "../../x11/libXxf86vm/buildlink3.mk"
.    include "../../x11/libX11/buildlink3.mk"
. endif
.endif # FREEGLUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-freeglut
