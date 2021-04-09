# $NetBSD: Makefile,v 1.2 2021/04/09 14:41:34 tnn Exp $

DISTNAME=	matplotlib-venn-0.11.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/matplotlib-venn/}
EXTRACT_SUFX=	.zip

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/konstantint/matplotlib-venn
COMMENT=	Routines for plotting area-weighted venn diagrams
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

PYTHON_VERSIONS_INCOMPATIBLE=	36 27	# py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
