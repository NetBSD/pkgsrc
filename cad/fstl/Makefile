# $NetBSD: Makefile,v 1.22 2026/01/07 08:45:57 wiz Exp $

DISTNAME=	fstl-0.11.1
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=fstl-app/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mattkeeter.com/projects/fstl/
COMMENT=	Fast STL file viewer
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
