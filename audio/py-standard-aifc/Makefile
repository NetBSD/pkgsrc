# $NetBSD: Makefile,v 1.1 2026/04/15 08:07:24 adam Exp $

DISTNAME=	standard_aifc-3.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/standard-aifc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/youknowone/python-deadlib
COMMENT=	Support for reading and writing AIFF and AIFF-C files
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-audioop-lts>0:../../audio/py-audioop-lts
DEPENDS+=	${PYPKGPREFIX}-standard-chunk>0:../../audio/py-standard-chunk

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 312

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
