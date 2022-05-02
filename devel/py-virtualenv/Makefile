# $NetBSD: Makefile,v 1.55 2022/05/02 09:08:53 wiz Exp $

DISTNAME=	virtualenv-16.7.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/virtualenv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://virtualenv.pypa.io/
COMMENT=	Virtual Python Environment builder
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=4.5.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-pypiserver-[0-9]*:../../net/py-pypiserver
TEST_DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=1.3.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

REPLACE_PYTHON=	virtualenv.py

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} virtualenv virtualenv-${PYVERSSUFFIX} || ${TRUE}

# as of 16.7.9
# 15 failed, 10 passed, 10 skipped, 5 warnings, 59 errors
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
