# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:02 wiz Exp $

DISTNAME=	tabular-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/t/tabular/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/tabular
COMMENT=	Tabular data tools for Python
LICENSE=	mit

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.1

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.6

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
