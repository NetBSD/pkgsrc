# $NetBSD: Makefile,v 1.10 2024/05/29 16:33:12 adam Exp $

DISTNAME=	qtvirtualkeyboard-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtvirtualkeyboard-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 virtual keyboard
CATEGORIES=	inputmethod

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6VirtualKeyboard.pc

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
