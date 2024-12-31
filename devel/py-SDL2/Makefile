# $NetBSD: Makefile,v 1.14 2024/12/31 17:53:39 adam Exp $

DISTNAME=	pysdl2-0.9.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PySDL2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/py-sdl/py-sdl2
COMMENT=	Python SDL2 bindings
LICENSE=	cc0-1.0-universal OR zlib

WHEEL_NAME=	${DISTNAME:S/pysdl/PySDL/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

TEST_ENV+=	PYSDL2_DLL_PATH=${BUILDLINK_PREFIX.SDL2}/lib

BUILDLINK_API_DEPENDS.SDL2+=	SDL2>=2.0.5
.include "../../devel/SDL2/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2_mixer+=	SDL2_mixer>=2.0.1
.include "../../audio/SDL2_mixer/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2_ttf+=	SDL2_ttf>=2.0.14
.include "../../fonts/SDL2_ttf/buildlink3.mk"
BUILDLINK_API_DEPENDS.SDL2_image+=	SDL2_image>=2.0.1
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/SDL2_gfx/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
