# $NetBSD: Makefile,v 1.16 2017/01/01 14:43:46 wiz Exp $

DISTNAME=	fpconst-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fpconst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/fpconst
COMMENT=	IEEE 754 floating point special handling for Python

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.7.2

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
