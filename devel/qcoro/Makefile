# $NetBSD: Makefile,v 1.1 2025/12/30 02:07:53 markd Exp $

DISTNAME=	qcoro-0.12.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=danvratil/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/danvratil/qcoro
COMMENT=	C++ Coroutines for Qt
LICENSE=	mit

.include "../../devel/cmake/build.mk"

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++20

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../net/qt6-qtwebsockets/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
