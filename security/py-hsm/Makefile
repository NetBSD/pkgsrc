# $NetBSD: Makefile,v 1.5 2019/09/20 17:13:26 adam Exp $

DISTNAME=	pyhsm-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
