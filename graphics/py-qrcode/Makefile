# $NetBSD: Makefile,v 1.1 2014/02/02 00:27:38 rodent Exp $

DISTNAME=	qrcode-4.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	https://pypi.python.org/packages/source/q/qrcode/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/lincolnloop/python-qrcode
COMMENT=	Python QR Code image generator
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml # XXX for py26
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
