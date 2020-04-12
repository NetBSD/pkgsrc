# $NetBSD: Makefile,v 1.21 2020/04/12 08:27:54 adam Exp $

PKGREVISION= 10
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=	libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/qt_/qt5-/:S/+/./}

COMMENT=	Dbusmenu library for Qt5

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
