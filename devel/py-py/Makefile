# $NetBSD: Makefile,v 1.27 2025/04/12 20:03:45 adam Exp $

DISTNAME=	py-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://py.readthedocs.io/
COMMENT=	Library with cross-python path, ini-parsing, io, code, log facilities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
