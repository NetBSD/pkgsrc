# $NetBSD: Makefile,v 1.22 2024/05/26 10:22:25 markd Exp $

DISTNAME=	plasma-wayland-protocols-1.13.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma-wayland-protocols/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kde/plasma-wayland-protocols
COMMENT=	Plasma Specific Protocols for Wayland
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	extra-cmake-modules>=5.60.0:../../devel/extra-cmake-modules

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"

.include "../../mk/bsd.pkg.mk"
