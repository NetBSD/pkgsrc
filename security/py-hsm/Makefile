# $NetBSD: Makefile,v 1.2 2014/01/19 09:51:12 wiz Exp $

DISTNAME=	pyhsm-1.0.4g
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
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
