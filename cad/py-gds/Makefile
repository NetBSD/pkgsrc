# $NetBSD: Makefile,v 1.16 2021/07/01 14:48:31 nia Exp $

DISTNAME=	gdspy-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gdspy/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/heitzmann/gdspy
COMMENT=	Python module for creating GDSII stream files
LICENSE=	boost-license

PYTHON_VERSIONS_INCOMPATIBLE=	36 # py-numpy

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
.endif

USE_LANGUAGES+=	c c++

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
