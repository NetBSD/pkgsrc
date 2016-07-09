# $NetBSD: Makefile,v 1.54 2016/07/09 13:03:54 wiz Exp $

DISTNAME=	Numeric-24.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://numeric.scipy.org/
COMMENT=	Adds multidimensional numeric arrays to Python

PYSETUP=	setup.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 24.2

PLIST_VARS+=	blas
.if exists(/System/Library/Frameworks/vecLib.framework)
BUILDLINK_PASSTHRU_DIRS+=	/System/Library/Frameworks/vecLib.framework/Headers
PLIST.blas=	yes
.endif

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
