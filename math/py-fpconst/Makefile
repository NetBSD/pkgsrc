# $NetBSD: Makefile,v 1.21 2022/01/22 14:41:03 wiz Exp $

DISTNAME=	fpconst-0.7.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fpconst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/fpconst
COMMENT=	IEEE 754 floating point special handling for Python

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.7.2

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
