# $NetBSD: Makefile,v 1.1 2024/09/21 12:40:17 js Exp $

DISTNAME=	trezor-agent-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-libagent-0.15.0
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=romanz/}
GITHUB_PROJECT=	trezor-agent
GITHUB_TAG=	v${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/${DISTNAME}

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	https://github.com/romanz/trezor-agent
COMMENT=	Hardware-based SSH/GPG/age agent
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-bech32>=1.2.0:../../devel/py-bech32
DEPENDS+=	${PYPKGPREFIX}-cryptography>=3.4.6:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.14:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-daemon>=2.3.0:../../devel/py-daemon
DEPENDS+=	${PYPKGPREFIX}-configargparse>=0.12.1:../../devel/py-configargparse
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.13:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.4.0:../../security/py-nacl
DEPENDS+=	${PYPKGPREFIX}-mnemonic>=0.18:../../devel/py-mnemonic
DEPENDS+=	${PYPKGPREFIX}-semver>=2.2:../../devel/py-semver
DEPENDS+=	${PYPKGPREFIX}-Unidecode>=0.4.20:../../textproc/py-Unidecode

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
