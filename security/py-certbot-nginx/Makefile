# $NetBSD: Makefile,v 1.15 2020/09/30 09:03:47 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-nginx-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-nginx/}

COMMENT=	Nginx plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-acme>=1.4.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=1.6.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=1.5.5:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

PKG_SYSCONFVAR=		nginx

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	certbot_nginx/_internal/constants.py
SUBST_VARS.paths=	PKG_SYSCONFDIR

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
