# $NetBSD: Makefile,v 1.16 2023/11/12 13:21:09 wiz Exp $

DISTNAME=	plasma-wayland-protocols-1.10.0
PKGREVISION=	5
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma-wayland-protocols/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kde.org/
COMMENT=	Plasma Specific Protocols for Wayland
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules>=5.60.0:../../devel/extra-cmake-modules

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

BUILDLINK_DEPMETHOD.qt5-qtbase=	build
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
