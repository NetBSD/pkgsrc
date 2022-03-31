# $NetBSD: Makefile,v 1.1 2022/03/31 21:47:54 wiz Exp $

DISTNAME=	pytest-trio-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-trio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/pytest-trio
COMMENT=	Python testing tool for trio
LICENSE=	mit OR apache-2.0

DEPENDS+=	${PYPKGPREFIX}-trio>=0.15.0:../../devel/py-trio
DEPENDS+=	${PYPKGPREFIX}-async_generator>=1.9:../../devel/py-async_generator
DEPENDS+=	${PYPKGPREFIX}-outcome-[0-9]*:../../devel/py-outcome
DEPENDS+=	${PYPKGPREFIX}-test>=3.6:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# does not run
# Defining 'pytest_plugins' in a non-top-level conftest is no longer supported:
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
