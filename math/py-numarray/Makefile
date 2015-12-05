# $NetBSD: Makefile,v 1.21 2015/12/05 21:25:49 adam Exp $

DISTNAME=	numarray-1.5.2
PKGNAME=	${PYPKGPREFIX}-numarray-1.5.2
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.numpy.org/old_array_packages.html
COMMENT=	Array manipulation

PLIST_VARS+=	blas
.if exists(/System/Library/Frameworks/Accelerate.framework)
PLIST.blas=	yes
.endif

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 1.5.2; use py-numpy

do-test:
	(cd ${WRKSRC}/Lib && ${PYTHONBIN} testall.py)

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
