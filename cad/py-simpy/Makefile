# $NetBSD: Makefile,v 1.28 2025/04/15 15:45:37 adam Exp $

DISTNAME=	simpy-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	cad math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/simpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://simpy.readthedocs.io/
COMMENT=	Discrete event simulation framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.0:../../devel/py-setuptools_scm

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
