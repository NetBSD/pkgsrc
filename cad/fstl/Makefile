# $NetBSD: Makefile,v 1.20 2025/10/12 15:22:57 mef Exp $

DISTNAME=	fstl-0.11.1
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
