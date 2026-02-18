# $NetBSD: Makefile,v 1.39 2026/02/18 10:47:08 wiz Exp $

DISTNAME=	buildbot-${BBVERSION}
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot/}

COMMENT=	Continuous integration system

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.9.0:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-treq>=20.9:../../devel/py-treq
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.6.0:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-croniter>=1.3.0:../../time/py-croniter
DEPENDS+=	${PYPKGPREFIX}-zope.interface>=4.1.1:../../devel/py-zope.interface
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=1.4.0:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-alembic>=1.6.0:../../databases/py-alembic
DEPENDS+=	${PYPKGPREFIX}-dateutil>=1.5:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-txaio>=2.2.2:../../devel/py-txaio
DEPENDS+=	${PYPKGPREFIX}-autobahn>=0.16.0:../../www/py-autobahn
DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-JWT-[0-9]*:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-unidiff>=0.7.5:../../devel/py-unidiff
# optional
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-service_identity-[0-9]*:../../security/py-service_identity
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-brotli-[0-9]*:../../archivers/py-brotli
DEPENDS+=	${PYPKGPREFIX}-zstandard-[0-9]*:../../archivers/py-zstandard
DEPENDS+=	${PYPKGPREFIX}-evalidate-[0-9]*:../../devel/py-evalidate
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-txrequests-[0-9]*:../../devel/py-txrequests
TEST_DEPENDS+=	${PYPKGPREFIX}-buildbot-pkg-[0-9]*:../../devel/py-buildbot-pkg
TEST_DEPENDS+=	${PYPKGPREFIX}-buildbot-worker-[0-9]*:../../devel/py-buildbot-worker
TEST_DEPENDS+=	${PYPKGPREFIX}-pugjs-[0-9]*:../../textproc/py-pugjs
TEST_DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
TEST_DEPENDS+=	${PYPKGPREFIX}-moto-[0-9]*:../../net/py-moto
TEST_DEPENDS+=	${PYPKGPREFIX}-markdown>=3:../../textproc/py-markdown
TEST_DEPENDS+=	${PYPKGPREFIX}-parameterized-[0-9]*:../../devel/py-parameterized

USE_LANGUAGES=	# none
USE_TOOLS+=	git:test

TEST_ENV+=	PYTHONPATH=.

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif
# as of 4.3.0, with Python 3.14
# FAILED (skips=45, errors=48, successes=651)
# with Python 3.13
# PASSED (skips=39, successes=657)
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} trial-${PYVERSSUFFIX} buildbot.test

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} buildbot buildbot-${PYVERSSUFFIX} && \
	${MV} buildbot_windows_service buildbot_windows_service-${PYVERSSUFFIX} || ${TRUE}

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
