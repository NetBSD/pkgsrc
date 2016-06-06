# $NetBSD: Makefile,v 1.5 2016/06/06 12:03:26 wiz Exp $

DISTNAME=	oauthlib-1.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
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
