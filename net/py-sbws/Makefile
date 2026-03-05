# $NetBSD: Makefile,v 1.5 2026/03/05 16:40:32 wiz Exp $

DISTNAME=	sbws-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://gitlab.torproject.org/tpo/network-health/sbws/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tpo.pages.torproject.net/network-health/sbws/
COMMENT=	Tor simple bandwidth scanner
LICENSE=	cc0-1.0-universal

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-stem>=1.8.0:../../devel/py-stem
DEPENDS+=	${PYPKGPREFIX}-psutil>=7.0:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-versioneer>=0:../../devel/py-versioneer
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-time-machine-[0-9]*:../../time/py-time-machine

WRKSRC=		${WRKDIR}/sbws-v2.2.0-df4c6e9138ca5cbca054e5684e6b580ad1b95dc5

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:test

REPLACE_BASH+=	scripts/maint/update-authors
REPLACE_BASH+=	scripts/maint/update-website
REPLACE_BASH+=	scripts/tools/osx-extra-loopback.sh

REPLACE_PYTHON+=	scripts/tools/get-per-relay-budget.py
REPLACE_PYTHON+=	scripts/tools/scale-v3bw-with-budget.py

# XXX Should run the integration tests too, but it's a bit more
# involved.
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} -s tests/unit -vv

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
