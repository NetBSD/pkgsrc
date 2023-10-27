# $NetBSD: Makefile,v 1.1 2023/10/27 08:18:38 adam Exp $

DISTNAME=	pytest-mypy-testing-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-mypy-testing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davidfritzsche/pytest-mypy-testing
COMMENT=	Pytest plugin to check mypy output
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mypy>=0.931:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-test>=7:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
