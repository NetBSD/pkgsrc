# $NetBSD: Makefile,v 1.24 2022/07/11 08:50:27 adam Exp $

DISTNAME=	celery-5.2.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/celery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-billiard>=3.6.4.0:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-click>=8.0.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-didyoumean>=0.0.3:../../devel/py-click-didyoumean
DEPENDS+=	${PYPKGPREFIX}-click-plugins>=1.1.1:../../devel/py-click-plugins
DEPENDS+=	${PYPKGPREFIX}-click-repl>=0.2.0:../../devel/py-click-repl
DEPENDS+=	${PYPKGPREFIX}-kombu>=5.2.3:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-pytz>=2021.3:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-vine>=5.0.0:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3>=1.9.178:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-moto>=2.2.6:../../net/py-moto
TEST_DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
#TEST_DEPENDS+=	${PYPKGPREFIX}-pre-commit-[0-9]*:../../wip/py-pre-commit
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-celery-[0-9]*:../../devel/py-test-celery
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subtests-[0-9]*:../../devel/py-test-subtests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout
# unlisted but needed
TEST_DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
TEST_DEPENDS+=	${PYPKGPREFIX}-mongo-[0-9]*:../../databases/py-mongo

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} celery celery-${PYVERSSUFFIX} || ${TRUE}

# test status as of 5.2.3 with py-pre-commit
# 1 failed, 2444 passed, 49 skipped, 3 xfailed, 30 warnings

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
