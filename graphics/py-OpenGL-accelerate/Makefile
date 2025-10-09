# $NetBSD: Makefile,v 1.17 2025/10/09 07:57:41 wiz Exp $

DISTNAME=	pyopengl_accelerate-3.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyopengl_/OpenGL-/}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyOpenGL-accelerate/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mcfletch.github.io/pyopengl/
COMMENT=	Acceleration code for PyOpenGL
# There are many similar licenses, see license.txt
LICENSE=	modified-bsd AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=0.28:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=42.0:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
