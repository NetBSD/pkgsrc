# $NetBSD: Makefile,v 1.25 2016/08/21 01:32:45 kamil Exp $

DISTNAME=	PyOpenGL-3.1.1a1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//}
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyOpenGL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyopengl.sourceforge.net/
COMMENT=	Python bindings for OpenGL
# There are many similar licenses, see license.txt
LICENSE=	modified-bsd AND mit

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

REPLACE_PYTHON+=	*.py */*.py */*/*.py */*/*/*.py */*/*/*/*.py

# Tests require:
# - devel/py-virtualenv
# - devel/py-game
# - math/py-numpy
# ...

SUBST_CLASSES+=		pyver
SUBST_MESSAGE.pyver=	Set Python version suffix for virtualenv calls.
SUBST_STAGE.pyver=	pre-configure
SUBST_FILES.pyver=	tests/tests.py
SUBST_SED.pyver=	-e '121s,virtualenv,virtualenv-${PYVERSSUFFIX},'

do-test:
	${RUN} ${PYTHONBIN} ${WRKSRC}/tests/tests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
