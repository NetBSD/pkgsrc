# $NetBSD: Makefile,v 1.6 2010/02/21 15:13:42 wiz Exp $

DISTNAME=	scipy-0.7.0
PKGNAME=	${PYPKGPREFIX}-scipy-0.7.0
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scipy/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.scipy.org/
COMMENT=	Scientific Algorithms Library for Python
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PLIST_SUBST+=   PYPKGPREFIX=${PYPKGPREFIX}
USE_LANGUAGES+=	c c++ fortran
MAKE_ENV+=	ATLAS=None

.include "../../lang/python/extension.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
