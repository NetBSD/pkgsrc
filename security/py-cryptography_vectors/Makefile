# $NetBSD: Makefile,v 1.78 2026/03/27 10:06:27 adam Exp $

DISTNAME=	cryptography_vectors-46.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cryptography_vectors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/cryptography
COMMENT=	Cryptographic test vectors
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.7.19:../../devel/py-uv-build

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
