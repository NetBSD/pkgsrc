# $NetBSD: Makefile,v 1.18 2022/01/04 20:54:39 wiz Exp $

PKGREVISION= 1
.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-nginx-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-nginx/}

COMMENT=	Nginx plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=17.3.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-setuptools>=39.0.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.2.0:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

PKG_SYSCONFVAR=		nginx

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	certbot_nginx/_internal/constants.py
SUBST_VARS.paths=	PKG_SYSCONFDIR

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
