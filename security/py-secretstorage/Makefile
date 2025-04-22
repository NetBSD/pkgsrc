# $NetBSD: Makefile,v 1.3 2025/04/22 20:33:04 wiz Exp $

DISTNAME=	SecretStorage-3.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SecretStorage/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/mitya57/secretstorage
COMMENT=	Module for securely storing passwords and secrets
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-jeepney>=0.6:../../sysutils/py-jeepney

USE_LANGUAGES=	# none

WHEEL_NAME+=	${DISTNAME:tl}

# as of 3.3.3
# 19 failed, 1 passed, 6 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
