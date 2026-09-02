# $NetBSD: Makefile,v 1.55 2026/09/02 09:13:20 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot/}

COMMENT=	Client for the Let's Encrypt CA

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-configargparse>=1.5.3:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-configobj>=5.0.6:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-cryptography>=47.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-distro>=1.7.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-josepy>=2.0.0:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=2.6:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-rfc3339>=0:../../time/py-rfc3339
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.1.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist

BUILD_DEFS+=		VARBASE
PKG_SYSCONFSUBDIR=	letsencrypt
PY_RENAME_BINARIES=	certbot

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path=	src/certbot/compat/misc.py
SUBST_FILES.path+=	src/certbot/_internal/plugins/nginx/constants.py
SUBST_FILES.path+=	src/certbot/_internal/tests/cli_test.py
SUBST_SED.path=		-e 's,/etc/letsencrypt,${PKG_SYSCONFDIR},g'
SUBST_SED.path+=	-e 's,/var/lib/letsencrypt,${VARBASE}/letsencrypt,g'
SUBST_SED.path+=	-e 's,/var/log/letsencrypt,${VARBASE}/letsencrypt/log,g'
SUBST_VARS.path+=	PKG_SYSCONFBASE
SUBST_VARS.path+=	PKG_SYSCONFDIR

MAKE_DIRS+=		${VARBASE}/letsencrypt/log

INSTALLATION_DIRS+=	share/examples/certbot-${PYVERSSUFFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/examples/cli.ini \
		${DESTDIR}${PREFIX}/share/examples/certbot-${PYVERSSUFFIX}

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
