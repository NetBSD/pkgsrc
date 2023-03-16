# $NetBSD: Makefile,v 1.2 2023/03/16 17:35:21 adam Exp $

DISTNAME=	SecretStorage-3.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SecretStorage/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/mitya57/secretstorage
COMMENT=	Module for securely storing passwords and secrets
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-jeepney>=0.6:../../sysutils/py-jeepney

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
