# $NetBSD: Makefile,v 1.35 2004/07/22 09:16:03 recht Exp $

DISTNAME=	Numeric-23.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.pfdubois.com/numpy/
COMMENT=	Adds multidimensional numeric arrays to Python

USE_BUILDLINK3=	yes

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
