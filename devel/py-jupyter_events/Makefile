# $NetBSD: Makefile,v 1.1 2023/05/05 10:10:53 adam Exp $

DISTNAME=	jupyter_events-0.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter-events/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter Event System library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-json-logger>=2.0.4:../../textproc/py-json-logger
DEPENDS+=	${PYPKGPREFIX}-traitlets>=5.3:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio>=0.19.0:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-console-scripts-[0-9]*:../../devel/py-test-console-scripts
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		tests
SUBST_STAGE.tests=	pre-configure
SUBST_MESSAGE.tests=	Fixing command name in tests.
SUBST_FILES.tests=	tests/test_cli.py
SUBST_SED.tests=	-e 's,"jupyter-events","jupyter-events-${PYVERSSUFFIX}",g'

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jupyter-events jupyter-events-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
