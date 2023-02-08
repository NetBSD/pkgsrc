# $NetBSD: Makefile,v 1.38 2023/02/08 10:20:20 adam Exp $

DISTNAME=	cryptography_vectors-39.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cryptography_vectors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/cryptography
COMMENT=	Cryptographic test vectors
LICENSE=	apache-2.0 OR modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	${RM} -r ${WRKSRC}/cryptography_vectors/__pycache__

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
