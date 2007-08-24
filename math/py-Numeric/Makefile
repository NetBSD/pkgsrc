# $NetBSD: Makefile,v 1.43 2007/08/24 08:58:28 heinz Exp $

DISTNAME=	Numeric-24.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://numeric.scipy.org/
COMMENT=	Adds multidimensional numeric arrays to Python

PKG_DESTDIR_SUPPORT=	user-destdir

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
