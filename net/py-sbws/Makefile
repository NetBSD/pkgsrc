# $NetBSD: Makefile,v 1.3 2022/01/10 08:01:01 wiz Exp $

DISTNAME=	sbws-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=torproject/}
GITHUB_PROJECT=	sbws
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sbws.readthedocs.io/
COMMENT=	Tor simple bandwidth scanner
LICENSE=	cc0-1.0-universal

USE_LANGUAGES=	# none

# Python 3 only.
PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-stem>=1.7.0:../../devel/py-stem

TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
TEST_DEPENDS+=	bash>=4.0:../../shells/bash

REPLACE_BASH+=	scripts/maint/update-authors
REPLACE_BASH+=	scripts/maint/update-website
REPLACE_BASH+=	scripts/tools/osx-extra-loopback.sh
REPLACE_BASH+=	tests/testnets/run-network.sh
REPLACE_BASH+=	tests/testnets/simple.common/01-gen-configs.sh
REPLACE_BASH+=	tests/testnets/simple.common/02-start-network.sh
REPLACE_BASH+=	tests/testnets/simple.common/04-stop-network.sh

REPLACE_PYTHON+=	scripts/tools/get-per-relay-budget.py
REPLACE_PYTHON+=	scripts/tools/sbws-http-server.py
REPLACE_PYTHON+=	scripts/tools/scale-v3bw-with-budget.py
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	tests/testnets/simple.common/03-network-in-ready-state.py

# XXX Should run the integration tests too, but it's a bit more
# involved.
do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} -s tests/unit -vv

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
