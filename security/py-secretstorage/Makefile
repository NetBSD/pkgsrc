# $NetBSD: Makefile,v 1.1 2023/03/12 13:55:17 wiz Exp $

DISTNAME=	secretstorage-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitya57/}
GITHUB_PROJECT=	secretstorage
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/mitya57/secretstorage/
COMMENT=	Module for securely storing passwords and secrets
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-jeepney>=0.6.0:../../sysutils/py-jeepney

PYTHON_VERSIONS_INCOMPATIBLE=	27

EGG_NAME=	SecretStorage-${PKGVERSION_NOREV}

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
