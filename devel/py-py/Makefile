# $NetBSD: Makefile,v 1.23 2022/01/13 19:31:22 wiz Exp $

DISTNAME=	py-1.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://py.readthedocs.io/
COMMENT=	Library with cross-python path, ini-parsing, io, code, log facilities
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm:build

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
