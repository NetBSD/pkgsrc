# $NetBSD: Makefile,v 1.16 2024/06/26 16:40:58 adam Exp $

DISTNAME=	qt5compat-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qt5compat-${QTVERSION}
COMMENT=	Qt6 module for Qt5 portability
CATEGORIES=	devel x11

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Core5Compat.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
