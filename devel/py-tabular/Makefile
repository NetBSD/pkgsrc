# $NetBSD: Makefile,v 1.9 2017/09/04 18:08:21 wiz Exp $

DISTNAME=	tabular-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tabular/}

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/tabular
COMMENT=	Tabular data tools for Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.1

.include "../../graphics/py-matplotlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.6
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
