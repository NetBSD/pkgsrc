# $NetBSD: Makefile,v 1.19 2014/05/09 07:37:11 wiz Exp $

DISTNAME=	numarray-1.5.2
PKGNAME=	${PYPKGPREFIX}-numarray-1.5.2
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.numpy.org/old_array_packages.html
COMMENT=	Array manipulation

PLIST_VARS+=	blas
.if exists(/System/Library/Frameworks/vecLib.framework/Headers)
BUILDLINK_PASSTHRU_DIRS+=	/System/Library/Frameworks/vecLib.framework/Headers
PLIST.blas=	yes
.endif

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.5.2; use py-numpy

do-test:
	(cd ${WRKSRC}/Lib && ${PYTHONBIN} testall.py)

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
