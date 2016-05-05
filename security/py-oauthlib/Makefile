# $NetBSD: Makefile,v 1.4 2016/05/05 11:43:06 wiz Exp $

DISTNAME=	oauthlib-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	https://pypi.python.org/packages/79/56/cb4c1ff3244f68605a1042a7f257f96815246b0625e28991d268554adb16/

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
