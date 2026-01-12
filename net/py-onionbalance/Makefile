# $NetBSD: Makefile,v 1.17 2026/01/12 11:40:11 adam Exp $

DISTNAME=	onionbalance-0.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/onionbalance/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://onionbalance.readthedocs.io/
COMMENT=	Tor onion service load balancer
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
DEPENDS+=	${PYPKGPREFIX}-stem>=1.8:../../devel/py-stem
DEPENDS+=	${PYPKGPREFIX}-yaml>=4.2:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} onionbalance onionbalance-${PYVERSSUFFIX} && \
	${MV} onionbalance-config onionbalance-config-${PYVERSSUFFIX} || ${TRUE}

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
