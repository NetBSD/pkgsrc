# $NetBSD: Makefile,v 1.8 2023/10/31 19:56:50 adam Exp $

DISTNAME=	qtquicktimeline-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtquicktimeline-${QTVERSION}
COMMENT=	Qt6 quick controls for keyframe animation
CATEGORIES=	graphics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickTimeline.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
