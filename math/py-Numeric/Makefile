# $NetBSD: Makefile,v 1.24 2001/10/04 15:24:08 wiz Exp $

DISTNAME=	Numeric-20.2.1
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
