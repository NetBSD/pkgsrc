# $NetBSD: Makefile,v 1.4 2009/09/23 09:54:45 tron Exp $

DISTNAME=	scipy-0.7.0
PKGNAME=	${PYPKGPREFIX}-scipy-0.7.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scipy/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.scipy.org/
COMMENT=	Scientific Algorithms Library for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PLIST_SUBST+=   PYPKGPREFIX=${PYPKGPREFIX}
USE_LANGUAGES+=	c c++ fortran
MAKE_ENV+=	ATLAS=None

.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
