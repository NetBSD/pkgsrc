# $NetBSD: Makefile,v 1.12 2018/11/27 16:36:28 adam Exp $

DISTNAME=	python-daemon-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-daemon/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://pagure.io/python-daemon/
COMMENT=	Library to implement a well-behaved Unix daemon process
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.10:../../devel/py-lockfile
BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=1.3:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-testscenarios>=0.4:../../devel/py-testscenarios
TEST_DEPENDS+=	${PYPKGPREFIX}-testtools-[0-9]*:../../devel/py-testtools
TEST_DEPENDS+=	${PYPKGPREFIX}-unittest2>=0.5.1:../../devel/py-unittest2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
