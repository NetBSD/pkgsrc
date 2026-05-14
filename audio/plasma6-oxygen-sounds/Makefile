# $NetBSD: Makefile,v 1.3 2026/05/14 16:40:27 ryoon Exp $

DISTNAME=	oxygen-sounds-${PLASMAVER}
PKGREVISION=	2
CATEGORIES=	audio

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Oxygen Sound Theme for Plasma
LICENSE=	gnu-lgpl-v3

.include "../../meta-pkgs/kde/plasma6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
