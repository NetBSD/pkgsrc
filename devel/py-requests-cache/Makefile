# $NetBSD: Makefile,v 1.4 2026/03/05 07:20:48 adam Exp $

DISTNAME=	requests_cache-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-cache/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/requests-cache/requests-cache
COMMENT=	Persistent cache for requests library
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.0.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-attrs>=21.2:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-cattrs>=22.2:../../devel/py-cattrs
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.5:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-url-normalize>=2.0:../../www/py-url-normalize
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.5:../../www/py-urllib3

# Optional dependencies
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.15:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-botocore>=1.18:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-mongo>=3:../../databases/py-mongo
DEPENDS+=	${PYPKGPREFIX}-redis>=3:../../databases/py-redis

#DEPENDS+=	${PYPKGPREFIX}-bson>=0.5:../../wip/py-bson
DEPENDS+=	${PYPKGPREFIX}-itsdangerous>=2.0:../../security/py-itsdangerous
DEPENDS+=	${PYPKGPREFIX}-ujson>=5.4:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.1:../../textproc/py-yaml

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.2:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil>=5.0:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-clarity>=1.0.1:../../devel/py-test-clarity
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-pretty>=1.2:../../devel/py-test-pretty
TEST_DEPENDS+=	${PYPKGPREFIX}-test-rerunfailures>=10.1:../../devel/py-test-rerunfailures
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.2:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-requests-mock>=1.12:../../devel/py-requests-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-responses>=0.19:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-tenacity>=8.0:../../devel/py-tenacity
TEST_DEPENDS+=	${PYPKGPREFIX}-timeout-decorator>=0.5:../../devel/py-timeout-decorator
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine>=2.9:../../time/py-time-machine
#TEST_DEPENDS+=	${PYPKGPREFIX}-nox>=2024.4:../../wip/py-nox
#TEST_DEPENDS+=	${PYPKGPREFIX}-pre-commit>=3.5:../../wip/py-pre-commit
TEST_DEPENDS+=	${PYPKGPREFIX}-rich>=10.0:../../comms/py-rich

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
