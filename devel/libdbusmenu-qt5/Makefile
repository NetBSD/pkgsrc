# $NetBSD: Makefile,v 1.9 2017/11/30 16:45:03 adam Exp $

PKGREVISION= 8
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=       libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/qt_/qt5-/:S/+/./}

COMMENT=	Dbusmenu library for Qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
