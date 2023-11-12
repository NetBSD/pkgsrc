# $NetBSD: Makefile,v 1.35 2023/11/12 13:21:05 wiz Exp $

PKGREVISION= 24
.include "../../devel/libdbusmenu-qt/Makefile.common"

DISTNAME=	libdbusmenu-qt_${_VER}
PKGNAME=	${DISTNAME:S/qt_/qt5-/:S/+/./}

COMMENT=	Dbusmenu library for Qt5

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
