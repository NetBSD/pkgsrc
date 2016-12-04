# $NetBSD: Makefile,v 1.4 2016/12/04 05:17:06 ryoon Exp $

PKGREVISION= 3
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=       libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/qt_/qt5-/:S/+/./}

COMMENT=	Dbusmenu library for Qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
