# $NetBSD: Makefile,v 1.25 2002/01/10 20:47:27 drochner Exp $

DISTNAME=	Numeric-20.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pfdubois.com/numpy/
COMMENT=	Adds multidimensional numeric arrays to Python

PYTHON_VERSIONS_ACCEPTED=	21 20
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUP=	setup_all.py

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
