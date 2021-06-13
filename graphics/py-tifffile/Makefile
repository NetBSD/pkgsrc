# $NetBSD: Makefile,v 1.8 2021/06/13 18:43:24 adam Exp $

DISTNAME=	tifffile-2021.6.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tifffile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lfd.uci.edu/~gohlke/
COMMENT=	Read and write TIFF(r) files
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

post-install:
.for bin in lsm2bin tiff2fsspec tiffcomment tifffile
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
