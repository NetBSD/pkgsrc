# $NetBSD: Makefile,v 1.63 2026/01/30 09:17:02 wiz Exp $

DISTNAME=	tifffile-2026.1.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tifffile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cgohlke/tifffile/
COMMENT=	Read and write TIFF(r) files
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-fsspec-[0-9]*:../../sysutils/py-fsspec

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

post-install:
.for bin in lsm2bin tiff2fsspec tiffcomment tifffile
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
