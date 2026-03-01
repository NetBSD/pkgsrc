# $NetBSD: Makefile,v 1.7 2026/03/01 00:58:18 js Exp $

DISTNAME=	trezor-0.20.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trezor/}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/trezor/trezor-firmware
COMMENT=	Python library for communicating with Trezor hardware wallets
LICENSE=	gnu-lgpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.9:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-mnemonic>=0.20:../../devel/py-mnemonic
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-click>=8:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-libusb1>=1.6.4:../../devel/py-libusb1
DEPENDS+=	${PYPKGPREFIX}-construct>=2.9:../../devel/py-construct
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.7.1:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-construct-classes>=0.1.2:../../devel/py-construct-classes
DEPENDS+=	${PYPKGPREFIX}-keyring>=25.7.0:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-noiseprotocol>=0.3:../../security/py-noiseprotocol
DEPENDS+=	${PYPKGPREFIX}-platformdirs-[0-9]*:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-shamir_mnemonic>=0.3.0:../../security/py-shamir_mnemonic
DEPENDS+=	${PYPKGPREFIX}-slip10>=1.1.0:../../security/py-slip10

USE_LANGUAGES=	# none

SUBST_CLASSES=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	src/trezorlib/cli/trezorctl.py
SUBST_SED.python=	-e 's,/usr/bin/env python3,${PYTHONBIN},'

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
