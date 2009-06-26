# $NetBSD: Makefile,v 1.3 2009/06/26 19:47:14 joerg Exp $
#

DISTNAME=	numpy-1.1.0
PKGNAME=	${PYPKGPREFIX}-numpy-1.1.0
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://numpy.scipy.org/
COMMENT=	Array processing for numbers, strings, records, and objects

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
USE_LANGUAGES+=	c fortran
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
MAKE_ENV+=	ATLAS=None

.include "../../lang/python/extension.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
