# $NetBSD: Makefile,v 1.28 2002/09/22 10:29:42 jlam Exp $

DISTNAME=	Numeric-20.3
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
PYSETUP=	setup_all.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
