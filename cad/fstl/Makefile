# $NetBSD: Makefile,v 1.21 2025/10/23 20:35:58 wiz Exp $

DISTNAME=	fstl-0.11.1
PKGREVISION=	1
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
