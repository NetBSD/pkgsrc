# $NetBSD: Makefile,v 1.31 2022/07/05 18:07:38 adam Exp $

DISTNAME=	cryptography_vectors-37.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cryptography_vectors/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/cryptography
COMMENT=	Cryptographic test vectors
LICENSE=	apache-2.0 OR modified-bsd

USE_LANGUAGES=	# none

post-extract:
	${RM} -r ${WRKSRC}/cryptography_vectors/__pycache__

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
