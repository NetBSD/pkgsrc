# $NetBSD: Makefile,v 1.39 2023/03/03 10:12:56 adam Exp $

DISTNAME=	cryptography_vectors-39.0.2
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
