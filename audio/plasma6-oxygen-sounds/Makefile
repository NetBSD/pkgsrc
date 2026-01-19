# $NetBSD: Makefile,v 1.1 2026/01/19 09:37:16 markd Exp $

DISTNAME=	oxygen-sounds-${PLASMAVER}
CATEGORIES=	audio

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Oxygen Sound Theme for Plasma
LICENSE=	gnu-lgpl-v3

.include "../../meta-pkgs/kde/plasma6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
