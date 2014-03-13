# $NetBSD: Makefile,v 1.3 2014/03/13 23:50:08 pettai Exp $

DISTNAME=	pyhsm-1.0.4h
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security
MASTER_SITES=	http://opensource.yubico.com/python-pyhsm/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://opensource.yubico.com/python-pyhsm/
COMMENT=	Python package that talk to a YubiHSM
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-serial-[0-9]*:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-crypto-[0-9]*:../../security/py-crypto

PYDISTUTILSPKG= yes

PYSETUP=                setup.py

USE_LANGUAGES=	# none

CONFLICTS+=	${PYPKGPREFIX}-pyhsm-[0-9]*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
