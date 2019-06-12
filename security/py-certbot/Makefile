# $NetBSD: Makefile,v 1.16 2019/06/12 10:27:37 adam Exp $

DISTNAME=	certbot-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot/}

MAINTAINER=	fhajny@NetBSD.org
COMMENT=	Client for the Let's Encrypt CA

.include "../../security/py-certbot/Makefile.common"

#EGG_NAME=	${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-acme>=0.29.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.9.3:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.2.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-josepy>=1.1.0:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=2.0:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface
# Needed for the test target
# https://github.com/certbot/certbot/issues/2956
TEST_DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	letsencrypt

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path+=	certbot/cert_manager.py
SUBST_FILES.path+=	certbot/cli.py
SUBST_FILES.path+=	certbot/compat/misc.py
SUBST_FILES.path+=	certbot/tests/cli_test.py
SUBST_SED.path+=	-e 's,/etc/letsencrypt,${PKG_SYSCONFDIR},g'
SUBST_SED.path+=	-e 's,/var/lib/letsencrypt,${VARBASE}/letsencrypt,g'
SUBST_SED.path+=	-e 's,/var/log/letsencrypt,${VARBASE}/letsencrypt/log,g'

MAKE_DIRS+=		${VARBASE}/letsencrypt/log

INSTALLATION_DIRS+=	share/examples/certbot-${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} certbot certbot-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/examples/cli.ini \
		${DESTDIR}${PREFIX}/share/examples/certbot-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
