# $NetBSD: Makefile,v 1.19 2019/08/12 07:45:23 adam Exp $

DISTNAME=	oauthlib-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/oauthlib/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://github.com/oauthlib/oauthlib
COMMENT=	Generic implementation of the OAuth request-signing logic
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-JWT>=1.0.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-blinker-[0-9]*:../../devel/py-blinker
DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
