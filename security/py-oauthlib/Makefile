# $NetBSD: Makefile,v 1.24 2022/09/13 12:32:55 adam Exp $

DISTNAME=	oauthlib-3.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/oauthlib/oauthlib
COMMENT=	Generic implementation of the OAuth request-signing logic
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.4.0:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.0.0:../../security/py-cryptography

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
