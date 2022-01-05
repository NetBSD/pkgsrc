# $NetBSD: Makefile,v 1.7 2022/01/05 20:47:37 wiz Exp $

DISTNAME=	pyhsm-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	security python
MASTER_SITES=	https://developers.yubico.com/python-pyhsm/Releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/python-pyhsm/
COMMENT=	Python package that talk to a YubiHSM
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-serial>=2.3:../../comms/py-serial

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
