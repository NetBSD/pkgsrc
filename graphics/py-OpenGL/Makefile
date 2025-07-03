# $NetBSD: Makefile,v 1.47 2025/07/03 19:18:05 wiz Exp $

DISTNAME=	pyopengl-3.1.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyopengl/OpenGL/}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyOpenGL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyopengl.sourceforge.net/
COMMENT=	Python bindings for OpenGL
# There are many similar licenses, see license.txt
LICENSE=	modified-bsd AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
TEST_DEPENDS+=	${PYPKGPREFIX}-OpenGL-accelerate-[0-9]*:../../graphics/py-OpenGL-accelerate
TEST_DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

USE_LANGUAGES=	c # for tests

REPLACE_PYTHON+=	OpenGL/arrays/buffers.py

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
