# $NetBSD: Makefile,v 1.27 2025/01/24 10:13:59 wiz Exp $

DISTNAME=	simpy-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad math python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/simpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://simpy.readthedocs.io/
COMMENT=	Discrete event simulation framework
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=64:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8.0:../../devel/py-setuptools_scm

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
