# $NetBSD: buildlink3.mk,v 1.6 2018/11/01 21:08:28 adam Exp $

BUILDLINK_TREE+=	SDL2

.if !defined(SDL2_BUILDLINK3_MK)
SDL2_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.SDL2+=	SDL2>=2.0.3nb8
BUILDLINK_API_DEPENDS.SDL2+=	SDL2>=2.0
BUILDLINK_PKGSRCDIR.SDL2?=	../../devel/SDL2
BUILDLINK_INCDIRS.SDL2+=	include/SDL2

pkgbase := SDL2
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mnas)
.include "../../audio/nas/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mopengl) && ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mrpi)
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Moss)
.include "../../mk/oss.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mx11)
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif	# SDL2_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2
