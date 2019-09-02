# $NetBSD: Makefile,v 1.9 2019/09/02 13:19:55 adam Exp $

DISTNAME=	yubiauth-0.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubiauth/Releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/yubiauth/
COMMENT=	YubiAuth authentication backend
LICENSE=	2-clause-bsd

PYDISTUTILSPKG=	yes

PYSETUP=	setup.py

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.3.9

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
