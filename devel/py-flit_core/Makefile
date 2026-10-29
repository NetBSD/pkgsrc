# $NetBSD: Makefile,v 1.14 2026/10/29 12:25:01 adam Exp $

DISTNAME=	flit_core-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Distribution-building parts of Flit
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath>=0:../../devel/py-testpath

USE_LANGUAGES=	# none
PY_PATCHPLIST=	yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} -m flit_core.wheel

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} bootstrap_install.py --installdir ${DESTDIR}${PREFIX}/${PYSITELIB} dist/flit_core*.whl
	find ${DESTDIR}${PREFIX}/${PYSITELIB} -name *.py | ${PYTHONBIN} -m py_compile -

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests_core

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
