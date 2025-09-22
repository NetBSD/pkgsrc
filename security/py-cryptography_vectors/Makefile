# $NetBSD: Makefile,v 1.72 2025/09/22 17:40:08 adam Exp $

DISTNAME=	cryptography_vectors-46.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cryptography_vectors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/cryptography
COMMENT=	Cryptographic test vectors
LICENSE=	apache-2.0 OR modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-uv-build>=0.7.19:../../devel/py-uv-build

USE_LANGUAGES=	# none

pre-configure:
	${LN} -sf ${PREFIX}/bin/uv-build-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/uv-build

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
