# $NetBSD: Makefile,v 1.7 2023/08/07 05:19:27 adam Exp $

DISTNAME=	qt3d-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qt3d-${QTVERSION}
COMMENT=	Qt6 3d
CATEGORIES=	graphics
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

CONFIGURE_ARGS+=	-system-qt3d-assimp
CONFIGURE_ARGS+=	-no-fbxsdk

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DAnimation.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DCore.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DExtras.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DInput.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DLogic.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DQuick.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DQuickAnimation.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DQuickExtras.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DQuickInput.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DQuickRender.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DQuickScene2D.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt63DRender.pc

PLIST_VARS+=	x86_64

.if ${MACHINE_ARCH} == "x86_64"
PLIST.x86_64=	yes
.endif

.include "../../graphics/qt6-qtshadertools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/assimp/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
