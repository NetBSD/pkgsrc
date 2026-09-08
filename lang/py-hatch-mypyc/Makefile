# $NetBSD: Makefile,v 1.1 2026/09/08 05:22:14 adam Exp $

DISTNAME=	hatch_mypyc-0.16.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-mypyc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ofek/hatch-mypyc
COMMENT=	Hatch build hook plugin for Mypyc
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.12.2:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-mypy>=0.971:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
