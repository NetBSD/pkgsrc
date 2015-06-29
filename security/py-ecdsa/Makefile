# $NetBSD: Makefile,v 1.7 2015/06/29 17:00:00 gls Exp $

DISTNAME=	python-ecdsa-0.13
PKGNAME=	${PYPKGPREFIX}-ecdsa-0.13
EGG_NAME=	ecdsa-${PKGVERSION}
CATEGORIES=	security
MASTER_SITES=	https://github.com/warner/python-ecdsa/archive/

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://github.com/warner/python-ecdsa/
COMMENT=	Easy-to-use implementation of ECDSA cryptography
LICENSE=	mit

WRKSRC=		${WRKDIR}/python-ecdsa-${DISTNAME}
USE_LANGUAGES=	# none

REPLACE_PYTHON=	ecdsa/ecdsa.py ecdsa/ellipticcurve.py ecdsa/numbertheory.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
