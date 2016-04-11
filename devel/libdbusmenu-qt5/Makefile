# $NetBSD: Makefile,v 1.3 2016/04/11 19:01:34 ryoon Exp $

PKGREVISION= 2
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=       libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/qt_/qt5-/:S/+/./}

COMMENT=	Dbusmenu library for Qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
