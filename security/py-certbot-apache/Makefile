# $NetBSD: Makefile,v 1.1 2019/02/12 12:57:19 adam Exp $

DISTNAME=	certbot-apache-0.31.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-apache/}

COMMENT=	Apache plugin for Certbot
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/certbot/certbot
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-acme>=0.25.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-augeas-[0-9]*:../../sysutils/py-augeas
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.26.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=1.5.5:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeComponent-[0-9]*:../../devel/py-ZopeComponent
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
