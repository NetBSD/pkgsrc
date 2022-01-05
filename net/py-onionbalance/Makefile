# $NetBSD: Makefile,v 1.9 2022/01/05 15:41:17 wiz Exp $

DISTNAME=	OnionBalance-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OnionBalance/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://onionbalance.readthedocs.io/
COMMENT=	Tor onion service load balancer
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.5:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-future>=0.14.0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
DEPENDS+=	${PYPKGPREFIX}-stem>=1.8:../../devel/py-stem
DEPENDS+=	${PYPKGPREFIX}-yaml>=4.2:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

PYSETUPTESTTARGET=	pytest

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} onionbalance onionbalance-${PYVERSSUFFIX} && \
	${MV} onionbalance-config onionbalance-config-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
