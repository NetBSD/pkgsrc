# $NetBSD: Makefile,v 1.10 2018/01/17 19:49:29 markd Exp $

.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=       libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/qt_/qt5-/:S/+/./}

COMMENT=	Dbusmenu library for Qt5

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
