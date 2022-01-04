# $NetBSD: Makefile,v 1.2 2022/01/04 20:54:41 wiz Exp $

DISTNAME=	google-reauth-0.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-reauth/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/google/google-reauth-python
COMMENT=	Library to support two-factor authentication
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-oauth2client>=2:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-u2f-[0-9]*:../../security/py-u2f

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
