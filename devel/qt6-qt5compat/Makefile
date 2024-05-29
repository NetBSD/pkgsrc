# $NetBSD: Makefile,v 1.15 2024/05/29 16:32:19 adam Exp $

DISTNAME=	qt5compat-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qt5compat-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 module for Qt5 portability
CATEGORIES=	devel x11

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Core5Compat.pc

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
