# $NetBSD: Makefile,v 1.1 2018/10/23 03:18:06 riastradh Exp $

.include "net/py-onionbalance/Makefile.common"

DISTNAME=	onionbalance-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_GITHUB:=DonnchaC/}
GITHUB_PROJECT=	onionbalance

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://onionbalance.readthedocs.io/
COMMENT=	Tor onion service load balancer
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-crypto>=2.6.1:../../security/py-crypto
DEPENDS+=	${PYPKGPREFIX}-future>=0.14.0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
DEPENDS+=	${PYPKGPREFIX}-stem>=0.4.0:../../devel/py-stem
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml

TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

REPLACE_PYTHON+=onionbalance.py
REPLACE_PYTHON+=docs/conf.py

CHECK_INTERPRETER_SKIP+=	test/scripts/install-chutney.sh
CHECK_INTERPRETER_SKIP+=	test/scripts/install-tor.sh

do-test:
	cd ${WRKSRC} && \
	${SETENV} PATH=${PATH:Q}:${DESTDIR:Q}${PREFIX:Q}/bin \
	${SETENV} PYTHONPATH=${DESTDIR:Q}${PREFIX:Q}/lib/python${PYVERSSUFFIX}/site-packages \
		py.test-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
