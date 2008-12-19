# $NetBSD: Makefile,v 1.1.1.1 2008/12/19 22:14:28 markd Exp $

DISTNAME=	scipy-0.6.0
PKGNAME=	${PYPKGPREFIX}-scipy-0.6.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scipy/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.scipy.org/
COMMENT=	Scientific Algorithms Library for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PLIST_SUBST+=   PYPKGPREFIX=${PYPKGPREFIX}
PYTHON_VERSIONS_ACCEPTED=   25 24 23
USE_LANGUAGES+=	c c++ fortran
MAKE_ENV+=	ATLAS=None

.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
