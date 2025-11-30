# $NetBSD: Makefile,v 1.6 2025/11/30 14:10:27 wiz Exp $

DISTNAME=	secretstorage-3.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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

# as of 3.5.0
# 21 failed, 6 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
