# $NetBSD: Makefile,v 1.26 2022/10/25 07:26:58 adam Exp $

DISTNAME=	oauthlib-3.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/oauthlib/oauthlib
COMMENT=	Generic implementation of the OAuth request-signing logic
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-blinker>=1.4.0:../../devel/py-blinker

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
