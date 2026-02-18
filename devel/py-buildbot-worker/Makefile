# $NetBSD: Makefile,v 1.17 2026/02/18 10:47:09 wiz Exp $

DISTNAME=	buildbot_worker-${BBVERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-worker/}

COMMENT=	Worker for the buildbot CI system

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-twisted>=0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.16.0:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.6.0:../../devel/py-msgpack
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} buildbot-worker buildbot-worker-${PYVERSSUFFIX} && \
	${MV} buildbot_worker_windows_service buildbot_worker_windows_service-${PYVERSSUFFIX} || ${TRUE}

TEST_ENV+=	PYTHONPATH=.

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} trial-${PYVERSSUFFIX} buildbot_worker.test

.include "../../devel/py-buildbot/Makefile.common"
.include "../../mk/bsd.pkg.mk"
