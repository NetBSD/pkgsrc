# $NetBSD: Makefile,v 1.1 2013/10/20 12:47:11 gls Exp $

DISTNAME=	python-ecdsa-0.9
PKGNAME=	${PYPKGPREFIX}-ecdsa-0.9
CATEGORIES=	security
MASTER_SITES=	https://github.com/warner/python-ecdsa/archive/
FETCH_USING=	curl

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	https://github.com/warner/python-ecdsa/archive/
COMMENT=	Easy-to-use implementation of ECDSA cryptography
LICENSE=	mit

WRKSRC=		${WRKDIR}/python-ecdsa-python-ecdsa-0.9
USE_LANGUAGES=	# none

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	ecdsa/ecdsa.py ecdsa/ellipticcurve.py ecdsa/numbertheory.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
