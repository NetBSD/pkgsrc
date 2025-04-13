# $NetBSD: Makefile,v 1.27 2025/04/13 20:40:26 wiz Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_nginx-${CERTBOT_VERSION}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-nginx/}

COMMENT=	Nginx plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.4.7:../../devel/py-pyparsing

PKG_SYSCONFVAR=		nginx

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	certbot_nginx/_internal/constants.py
SUBST_VARS.paths=	PKG_SYSCONFDIR

PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
