# $NetBSD: Makefile,v 1.2 2013/10/29 08:12:09 gls Exp $

DISTNAME=	python-ecdsa-0.10
PKGNAME=	${PYPKGPREFIX}-ecdsa-0.10
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

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
