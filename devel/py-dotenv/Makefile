# $NetBSD: Makefile,v 1.12 2023/05/22 12:25:07 adam Exp $

DISTNAME=	python-dotenv-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-dotenv/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://github.com/theskumar/python-dotenv
COMMENT=	Add .env support to your django/flask apps
LICENSE=	modified-bsd

# cli
DEPENDS+=	${PYPKGPREFIX}-click>=5.0:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-sh>=2:../../sysutils/py-sh
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=3.9:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} dotenv dotenv-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
