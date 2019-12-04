# $NetBSD: buildlink3.mk,v 1.1 2019/12/04 11:17:32 leot Exp $

BUILDLINK_TREE+=	zbar

.if !defined(ZBAR_BUILDLINK3_MK)
ZBAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zbar+=	zbar>=0.23
BUILDLINK_PKGSRCDIR.zbar?=	../../graphics/zbar

pkgbase:=	zbar
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.zbar:Mx11)
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.endif

.include "../../mk/jpeg.buildlink3.mk"

.endif # ZBAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-zbar
