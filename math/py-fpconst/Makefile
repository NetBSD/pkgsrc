# $NetBSD: Makefile,v 1.13 2015/12/05 21:25:49 adam Exp $

DISTNAME=	fpconst-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	http://pypi.python.org/packages/source/f/fpconst/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/fpconst
COMMENT=	IEEE 754 floating point special handling for Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 0.7.2

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
