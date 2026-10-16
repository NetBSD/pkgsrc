# $NetBSD: Makefile,v 1.26 2026/10/16 19:43:59 adam Exp $

DISTNAME=	qrcode-8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=q/qrcode/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lincolnloop/python-qrcode
COMMENT=	QR Code image generator
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
# pil
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.1.0:../../graphics/py-Pillow
# png
DEPENDS+=	${PYPKGPREFIX}-pypng-[0-9]*:../../graphics/py-pypng
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	311

REPLACE_PYTHON+=	qrcode/console_scripts.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} qr qr-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
