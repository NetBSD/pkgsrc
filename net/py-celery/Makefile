# $NetBSD: Makefile,v 1.30 2026/11/26 08:48:32 adam Exp $

DISTNAME=	celery-5.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/celery/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.celeryproject.org/
COMMENT=	Asynchronous task/job queue based on distributed message passing
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-billiard>=4.3.2:../../parallel/py-billiard
DEPENDS+=	${PYPKGPREFIX}-click>=8.3.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-didyoumean>=0.3.1:../../devel/py-click-didyoumean
DEPENDS+=	${PYPKGPREFIX}-click-plugins>=1.1.1.2:../../devel/py-click-plugins
DEPENDS+=	${PYPKGPREFIX}-click-repl>=0.4.1:../../devel/py-click-repl
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.9.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-kombu>=5.7.0:../../net/py-kombu
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=0:../../time/py-tzlocal
DEPENDS+=	${PYPKGPREFIX}-vine>=5.1.0:../../devel/py-vine
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3>=1.26.143:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-moto>=4.1.11:../../net/py-moto
# circular dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-celery>=0:../../devel/py-test-celery
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-click>=0:../../
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-order>=0:../../
TEST_DEPENDS+=	${PYPKGPREFIX}-test-subtests>=0.11.0:../../devel/py-test-subtests
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.2.0:../../devel/py-test-timeout
# unlisted but needed
TEST_DEPENDS+=	${PYPKGPREFIX}-dns>=0:../../net/py-dns
TEST_DEPENDS+=	${PYPKGPREFIX}-mongo>=0:../../databases/py-mongo

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	celery

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
