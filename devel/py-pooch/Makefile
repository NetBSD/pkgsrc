# $NetBSD: Makefile,v 1.10 2026/02/04 13:40:31 adam Exp $

DISTNAME=	pooch-1.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pooch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fatiando/pooch
COMMENT=	Manages Python library's sample data files
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.5.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-requests>=2.19.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
