# $NetBSD: Makefile,v 1.1 2013/06/02 01:47:54 dholland Exp $

DISTNAME=	tabular-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/t/tabular/

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/tabular
COMMENT=	Tabular data tools for Python
LICENSE=	mit

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
BUILDLINK_API_DEPENDS.pynumpy+=	${PYPKGPREFIX}-numpy>=1.6

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
