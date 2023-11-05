# $NetBSD: Makefile,v 1.12 2023/11/05 22:37:01 wiz Exp $

DISTNAME=	OnionBalance-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OnionBalance/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://onionbalance.readthedocs.io/
COMMENT=	Tor onion service load balancer
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-future>=0.14.0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-setproctitle-[0-9]*:../../sysutils/py-setproctitle
DEPENDS+=	${PYPKGPREFIX}-stem>=1.8:../../devel/py-stem
DEPENDS+=	${PYPKGPREFIX}-yaml>=4.2:../../textproc/py-yaml
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 312

SUBST_CLASSES+=		crypto
SUBST_STAGE.crypto=	pre-configure
SUBST_MESSAGE.crypto=	Replace Cryptodome with Crypto
SUBST_FILES.crypto=	onionbalance/config_generator/config_generator.py
SUBST_FILES.crypto+=	onionbalance/hs_v2/descriptor.py
SUBST_FILES.crypto+=	onionbalance/hs_v2/manager.py
SUBST_FILES.crypto+=	onionbalance/hs_v2/service.py
SUBST_FILES.crypto+=	onionbalance/hs_v2/util.py
SUBST_SED.crypto=	-e 's,Cryptodome,Crypto,g'

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} onionbalance onionbalance-${PYVERSSUFFIX} && \
	${MV} onionbalance-config onionbalance-config-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
