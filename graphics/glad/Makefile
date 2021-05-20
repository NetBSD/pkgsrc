# $NetBSD: Makefile,v 1.1 2021/05/20 20:19:17 nia Exp $

DISTNAME=	glad-0.1.34
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Dav1dde/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Dav1dde/glad
COMMENT=	GL/GLES/EGL/GLX/WGL Loader-Generator
LICENSE=	mit

USE_CMAKE=	yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DGLAD_REPRODUCIBLE=ON
CMAKE_ARGS+=	-DGLAD_INSTALL=ON

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
