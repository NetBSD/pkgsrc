# $NetBSD: Makefile,v 1.26 2024/06/12 17:02:05 adam Exp $

DISTNAME=	celery-5.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/celery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-billiard>=4.2.0:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-didyoumean>=0.3.0:../../devel/py-click-didyoumean
DEPENDS+=	${PYPKGPREFIX}-click-plugins>=1.1.1:../../devel/py-click-plugins
DEPENDS+=	${PYPKGPREFIX}-click-repl>=0.2.0:../../devel/py-click-repl
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.2:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-kombu>=5.3.4:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-tzdata>=2022.7:../../time/py-tzdata
DEPENDS+=	${PYPKGPREFIX}-vine>=5.1.0:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3>=1.26.143:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-moto>=4.1.11:../../net/py-moto
TEST_DEPENDS+=	${PYPKGPREFIX}-test-celery-[0-9]*:../../devel/py-test-celery
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-click-[0-9]*:../../
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-order-[0-9]*:../../
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subtests>=0.11.0:../../devel/py-test-subtests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.2.0:../../devel/py-test-timeout
# unlisted but needed
TEST_DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
TEST_DEPENDS+=	${PYPKGPREFIX}-mongo-[0-9]*:../../databases/py-mongo

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} celery celery-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
