# $NetBSD: Makefile,v 1.40 2023/10/26 09:32:25 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot/}

COMMENT=	Client for the Let's Encrypt CA

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-configargparse>=1.5.3:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-configobj>=5.0.6:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-distro>=1.0.1:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-josepy>=1.13.0:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=2.4:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytz>=2019.3:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
# Needed for the test target
# https://github.com/certbot/certbot/issues/2956
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	letsencrypt

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path=	certbot/compat/misc.py
SUBST_FILES.path+=	certbot/_internal/tests/cli_test.py
SUBST_SED.path=		-e 's,/etc/letsencrypt,${PKG_SYSCONFDIR},g'
SUBST_SED.path+=	-e 's,/var/lib/letsencrypt,${VARBASE}/letsencrypt,g'
SUBST_SED.path+=	-e 's,/var/log/letsencrypt,${VARBASE}/letsencrypt/log,g'

MAKE_DIRS+=		${VARBASE}/letsencrypt/log

INSTALLATION_DIRS+=	share/examples/certbot-${PYVERSSUFFIX}

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} certbot certbot-${PYVERSSUFFIX} || ${TRUE}
	${INSTALL_DATA} ${WRKSRC}/examples/cli.ini \
		${DESTDIR}${PREFIX}/share/examples/certbot-${PYVERSSUFFIX}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
