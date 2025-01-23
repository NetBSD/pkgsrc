# $NetBSD: Makefile,v 1.23 2025/01/23 23:27:25 riastradh Exp $

DISTNAME=	plasma-wayland-protocols-1.13.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=plasma-wayland-protocols/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kde/plasma-wayland-protocols
COMMENT=	Plasma Specific Protocols for Wayland
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"

BUILDLINK_API_DEPENDS.extra-cmake-modules+=	extra-cmake-modules>=5.60.0
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
