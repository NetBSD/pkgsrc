# $NetBSD: Makefile,v 1.30 2003/04/03 18:52:39 drochner Exp $

DISTNAME=	Numeric-23.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pfdubois.com/numpy/
COMMENT=	Adds multidimensional numeric arrays to Python

USE_BUILDLINK2=	yes

PYTHON_VERSIONS_ACCEPTED=	22 21 20
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
