# $NetBSD: Makefile,v 1.37 2005/02/25 17:10:09 drochner Exp $

DISTNAME=	Numeric-23.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://numeric.scipy.org/
COMMENT=	Adds multidimensional numeric arrays to Python

USE_BUILDLINK3=	yes

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
