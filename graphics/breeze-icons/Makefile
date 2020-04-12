# $NetBSD: Makefile,v 1.23 2020/04/12 08:28:48 adam Exp $

DISTNAME=	breeze-icons-${KF5VER}
PKGREVISION=	3
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Breeze icon themes
LICENSE=	gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/kf5.mk"

LDFLAGS+=	${COMPILER_RPATH_FLAG}${QTDIR}/lib

BUILDLINK_DEPMETHOD.qt5-qtbase= build
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
