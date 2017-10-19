# $NetBSD: Makefile,v 1.11 2017/10/19 06:28:40 adam Exp $

DISTNAME=	oauthlib-2.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/oauthlib
COMMENT=	Generic implementation of the OAuth request-signing logic
LICENSE=	original-bsd

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-JWT>=1.0.0:../../textproc/py-JWT
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
