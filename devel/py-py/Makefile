# $NetBSD: Makefile,v 1.26 2024/11/11 07:28:19 wiz Exp $

DISTNAME=	py-1.11.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://py.readthedocs.io/
COMMENT=	Library with cross-python path, ini-parsing, io, code, log facilities
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
