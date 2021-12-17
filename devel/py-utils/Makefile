# $NetBSD: Makefile,v 1.3 2021/12/17 08:11:56 adam Exp $

DISTNAME=	python-utils-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-utils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-utils
COMMENT=	Some convenient utilities not included with standard Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8>=0:../../devel/py-test-flake8

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} _python_utils_tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
