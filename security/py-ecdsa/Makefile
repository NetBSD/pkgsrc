# $NetBSD: Makefile,v 1.3 2013/11/05 17:37:48 joerg Exp $

DISTNAME=	python-ecdsa-0.10
PKGNAME=	${PYPKGPREFIX}-ecdsa-0.10
EGG_NAME=	ecdsa-0.0.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/warner/python-ecdsa/archive/
FETCH_USING=	curl

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://github.com/warner/python-ecdsa/
COMMENT=	Easy-to-use implementation of ECDSA cryptography
LICENSE=	mit

WRKSRC=		${WRKDIR}/python-ecdsa-${DISTNAME}
USE_LANGUAGES=	# none

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	ecdsa/ecdsa.py ecdsa/ellipticcurve.py ecdsa/numbertheory.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
