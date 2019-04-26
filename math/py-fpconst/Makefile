# $NetBSD: Makefile,v 1.18 2019/04/26 13:14:04 maya Exp $

DISTNAME=	fpconst-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fpconst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/fpconst
COMMENT=	IEEE 754 floating point special handling for Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 0.7.2

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
