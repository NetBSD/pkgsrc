# $NetBSD: Makefile,v 1.7 2025/08/20 11:34:59 wiz Exp $

DISTNAME=	glad-0.1.34
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Dav1dde/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Dav1dde/glad
COMMENT=	GL/GLES/EGL/GLX/WGL Loader-Generator
LICENSE=	mit

USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DGLAD_REPRODUCIBLE=ON
CMAKE_CONFIGURE_ARGS+=	-DGLAD_INSTALL=ON
CMAKE_CONFIGURE_ARGS+=  -DCMAKE_POLICY_VERSION_MINIMUM=3.5

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
