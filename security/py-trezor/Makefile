# $NetBSD: Makefile,v 1.1 2024/09/15 00:02:13 js Exp $

DISTNAME=	trezor-0.13.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trezor/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/trezor/trezor-firmware
COMMENT=	Python library for communicating with Trezor hardware wallets
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.9:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-mnemonic>=0.20:../../devel/py-mnemonic
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-click>=7<8.2:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-libusb1>=1.6.4:../../devel/py-libusb1
DEPENDS+=	${PYPKGPREFIX}-construct>=2.9:../../devel/py-construct
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.7.1:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-construct-classes>=0.1.2:../../devel/py-construct-classes

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
