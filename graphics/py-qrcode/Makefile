# $NetBSD: Makefile,v 1.20 2024/10/14 13:50:35 adam Exp $

DISTNAME=	qrcode-8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qrcode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lincolnloop/python-qrcode
COMMENT=	QR Code image generator
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
# pil
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.1.0:../../graphics/py-Pillow
# png
DEPENDS+=	${PYPKGPREFIX}-pypng-[0-9]*:../../graphics/py-pypng
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	qrcode/console_scripts.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} qr qr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
