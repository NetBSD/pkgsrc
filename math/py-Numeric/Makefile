# $NetBSD: Makefile,v 1.42 2006/06/02 16:56:49 joerg Exp $

DISTNAME=	Numeric-24.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://numeric.scipy.org/
COMMENT=	Adds multidimensional numeric arrays to Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED= 24 23 22
PYBINMODULE=	yes
PYSETUP=	setup.py

.if exists(/System/Library/Frameworks/vecLib.framework)
BUILDLINK_PASSTHRU_DIRS+=	/System/Library/Frameworks/vecLib.framework/Headers
PLIST_SUBST+=	DOTBLAS=""
.else
PLIST_SUBST+=	DOTBLAS="@comment "
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
