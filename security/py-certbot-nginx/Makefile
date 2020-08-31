# $NetBSD: Makefile,v 1.14 2020/08/31 23:07:06 wiz Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-nginx-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-nginx/}

COMMENT=	Nginx plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-acme>=1.4.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=1.4.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=1.5.5:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

PKG_SYSCONFVAR=		nginx

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	certbot_nginx/_internal/constants.py
SUBST_VARS.paths=	PKG_SYSCONFDIR

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
