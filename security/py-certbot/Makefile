# $NetBSD: Makefile,v 1.9 2018/12/15 21:12:23 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security

COMMENT=	Client for the Let's Encrypt CA
MAINTAINER=	fhajny@NetBSD.org
LICENSE=	apache-2.0

EGG_NAME=	${DISTNAME}

.include "Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme-${PKGVERSION_NOREV}{nb*,}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.9.3:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.2:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-josepy-[0-9]*:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-parsedatetime>=2.0:../../time/py-parsedatetime
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

# Needed for the test target
# https://github.com/certbot/certbot/issues/2956
BUILD_DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	letsencrypt

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-build
SUBST_MESSAGE.path=	Fixing default paths
SUBST_FILES.path+=	certbot/constants.py certbot/display/ops.py
SUBST_FILES.path+=	certbot/plugins/*.py certbot/tests/*.py
SUBST_SED.path+=	-e 's,/etc/letsencrypt,${PKG_SYSCONFDIR},g'
SUBST_SED.path+=	-e 's,/var/lib/letsencrypt,${VARBASE}/letsencrypt,g'
SUBST_SED.path+=	-e 's,/var/log/letsencrypt,${VARBASE}/letsencrypt/log,g'

MAKE_DIRS+=		${VARBASE}/letsencrypt/log

INSTALLATION_DIRS+=	share/examples/certbot

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/certbot \
		${DESTDIR}${PREFIX}/bin/certbot${PYVERSSUFFIX}
	${INSTALL_DATA} ${WRKSRC}/examples/cli.ini \
		${DESTDIR}${PREFIX}/share/examples/certbot

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
