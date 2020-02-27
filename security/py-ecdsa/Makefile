# $NetBSD: Makefile,v 1.8 2020/02/27 16:55:07 bsiegert Exp $

DISTNAME=	ecdsa-0.15
PKGNAME=	${PYPKGPREFIX}-ecdsa-0.15
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ecdsa/}

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://github.com/warner/python-ecdsa/
COMMENT=	Easy-to-use implementation of ECDSA cryptography
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

REPLACE_PYTHON=	ecdsa/ecdsa.py ecdsa/ellipticcurve.py ecdsa/numbertheory.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
