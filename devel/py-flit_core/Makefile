# $NetBSD: Makefile,v 1.9 2024/11/03 07:50:30 adam Exp $

DISTNAME=	flit_core-3.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flit-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flit.readthedocs.io/
COMMENT=	Distribution-building parts of Flit
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-testpath-[0-9]*:../../devel/py-testpath

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
