# $NetBSD: Makefile,v 1.80 2026/10/16 19:43:59 adam Exp $

DISTNAME=	tifffile-2026.9.20
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tifffile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cgohlke/tifffile/
COMMENT=	Read and write TIFF(r) files
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-numpy>=2.1:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-fsspec>=0:../../sysutils/py-fsspec

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	lsm2bin tiff2fsspec tiffcomment tifffile

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
