# $NetBSD: Makefile,v 1.1 2026/04/15 08:06:40 adam Exp $

DISTNAME=	standard_chunk-3.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/standard-chunk/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/youknowone/python-deadlib
COMMENT=	Support for reading and writing Interchange File Format
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 312

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
