# $NetBSD: Makefile,v 1.11 2022/01/05 15:41:02 wiz Exp $

DISTNAME=	buildbot-worker-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/buildbot-worker/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://buildbot.net/
COMMENT=	Worker for the buildbot CI system
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-twisted>=17.9.0:../../net/py-twisted
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_trial-[0-9]*:../../devel/py-setuptools_trial
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} buildbot-worker buildbot-worker-${PYVERSSUFFIX} && \
	${MV} buildbot_worker_windows_service buildbot_worker_windows_service-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
