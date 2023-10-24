# $NetBSD: Makefile,v 1.7 2023/10/24 22:08:57 wiz Exp $

DISTNAME=	qt5compat-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qt5compat-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 module for Qt5 portability
CATEGORIES=	devel x11

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Core5Compat.pc

.include "../../graphics/qt6-qtshadertools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
