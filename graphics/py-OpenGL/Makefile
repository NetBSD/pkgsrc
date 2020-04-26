# $NetBSD: Makefile,v 1.30 2020/04/26 10:07:06 rillig Exp $

DISTNAME=	PyOpenGL-3.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyOpenGL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Python bindings for OpenGL
# There are many similar licenses, see license.txt
LICENSE=	modified-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk
TEST_DEPENDS+=	${PYPKGPREFIX}-OpenGL-accelerate-[0-9]*:../../graphics/py-OpenGL-accelerate
TEST_DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	OpenGL/arrays/buffers.py

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests/test_core.py

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.endif
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
