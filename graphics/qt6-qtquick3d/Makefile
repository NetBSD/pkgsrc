# $NetBSD: Makefile,v 1.14 2024/05/29 16:33:02 adam Exp $

DISTNAME=	qtquick3d-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtquick3d-${QTVERSION}
PKGREVISION=	1
COMMENT=	3d engine for Qt6 quick
CATEGORIES=	graphics
LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3D.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DAssetImport.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DAssetUtils.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DEffects.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DHelpers.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DHelpersImpl.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DIblBaker.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DParticleEffects.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DParticles.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DRuntimeRender.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick3DUtils.pc

.if !empty(MACHINE_PLATFORM:MDarwin-*-aarch64) \
 || !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) \
 || !empty(MACHINE_PLATFORM:MLinux-*-aarch64) \
 || !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
PLIST_SRC=	PLIST
PLIST_SRC+=	PLIST.embree
.endif

.include "../../graphics/qt6-qtquicktimeline/buildlink3.mk"
.include "../../graphics/qt6-qtshadertools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/assimp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
