# $NetBSD: Makefile,v 1.7 2017/04/22 21:03:11 adam Exp $

PKGREVISION= 6
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=       libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/qt_/qt5-/:S/+/./}

COMMENT=	Dbusmenu library for Qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
