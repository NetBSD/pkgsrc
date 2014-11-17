# $NetBSD: Makefile,v 1.2 2014/11/17 19:05:39 joerg Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3.9

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
