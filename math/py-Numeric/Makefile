# $NetBSD: Makefile,v 1.31 2003/06/04 19:47:21 drochner Exp $

DISTNAME=	Numeric-23.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pfdubois.com/numpy/
COMMENT=	Adds multidimensional numeric arrays to Python

USE_BUILDLINK2=	yes

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
