# $NetBSD: Makefile,v 1.16 2015/12/05 21:25:47 adam Exp $

DISTNAME=	basicproperty-0.6.9a
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=basicproperty/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://basicproperty.sourceforge.net/
COMMENT=	Python RDBMS wrapper for various databases
LICENSE=	original-bsd

USE_LANGUAGES=	c

REPLACE_PYTHON=	basicproperty/tests/test.py
EGG_NAME=	${DISTNAME}0
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

post-extract:
	# wrong architecture binary
	rm ${WRKSRC}/basicproperty/propertyaccel.so

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
