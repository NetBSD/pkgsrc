# $NetBSD: Makefile,v 1.1 2013/10/08 15:21:37 pettai Exp $

DISTNAME=	pyhsm-1.0.4g
PKGNAME=	${PYPKGPREFIX}-pyhsm-1.0.4g
CATEGORIES=	security
MASTER_SITES=	http://opensource.yubico.com/python-pyhsm/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://opensource.yubico.com/python-pyhsm/
COMMENT=	Python package that talk to a YubiHSM
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pyserial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

PYDISTUTILSPKG= yes

PYSETUP=                setup.py

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
