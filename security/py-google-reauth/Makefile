# $NetBSD: Makefile,v 1.4 2022/07/12 09:07:13 wiz Exp $

DISTNAME=	google-reauth-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-reauth/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/google/google-reauth-python
COMMENT=	Library to support two-factor authentication
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-oauth2client>=2:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-u2f-[0-9]*:../../security/py-u2f

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
