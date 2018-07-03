# $NetBSD: Makefile,v 1.11 2018/07/03 05:03:13 adam Exp $

DISTNAME=	tabular-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tabular/}

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/tabular
COMMENT=	Tabular data tools for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 0.1

BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.6
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
