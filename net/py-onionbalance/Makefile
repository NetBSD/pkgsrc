# $NetBSD: Makefile,v 1.2 2018/10/24 11:52:33 adam Exp $

.include "../../net/py-onionbalance/Makefile.common"

DISTNAME=	OnionBalance-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OnionBalance/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://onionbalance.readthedocs.io/
COMMENT=	Tor onion service load balancer
LICENSE=	gnu-gpl-v3

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

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

REPLACE_PYTHON+=	onionbalance.py
REPLACE_PYTHON+=	docs/conf.py

CHECK_INTERPRETER_SKIP+=	test/scripts/install-chutney.sh
CHECK_INTERPRETER_SKIP+=	test/scripts/install-tor.sh

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
