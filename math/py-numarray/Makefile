# $NetBSD: Makefile,v 1.28 2022/01/10 18:51:10 wiz Exp $

DISTNAME=	numarray-1.5.2
PKGNAME=	${PYPKGPREFIX}-numarray-1.5.2
PKGREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.numpy.org/old_array_packages.html
COMMENT=	Array manipulation

PLIST_VARS+=	blas
.if exists(/System/Library/Frameworks/Accelerate.framework)
PLIST.blas=	yes
.endif

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.5.2; use py-numpy

do-test:
	(cd ${WRKSRC}/Lib && ${PYTHONBIN} testall.py)

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
