# $NetBSD: Makefile,v 1.26 2002/01/15 18:38:05 drochner Exp $

DISTNAME=	Numeric-20.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pfdubois.com/numpy/
COMMENT=	Adds multidimensional numeric arrays to Python

PYTHON_VERSIONS_ACCEPTED=	22 21 20
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup_all.py

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
