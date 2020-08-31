# $NetBSD: Makefile,v 1.11 2020/08/31 23:07:04 wiz Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-apache-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-apache/}

COMMENT=	Apache plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=0.29.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-augeas-[0-9]*:../../sysutils/py-augeas
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.39.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
