# $NetBSD: Makefile,v 1.1 2026/01/19 09:40:13 markd Exp $

DISTNAME=	ocean-sound-theme-${PLASMAVER}
CATEGORIES=	audio

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Ocean Sound Theme for Plasma
LICENSE=	cc-by-sa-v4.0

.include "../../meta-pkgs/kde/plasma6.mk"

CMAKE_CONFIGURE_ARGS+=	-DBUILD_WITH_QT6=ON

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
