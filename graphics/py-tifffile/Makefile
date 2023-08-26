# $NetBSD: Makefile,v 1.18 2023/08/26 08:33:23 adam Exp $

DISTNAME=	tifffile-2023.8.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tifffile/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.lfd.uci.edu/~gohlke/
COMMENT=	Read and write TIFF(r) files
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-fsspec-[0-9]*:../../sysutils/py-fsspec
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
.for bin in lsm2bin tiff2fsspec tiffcomment tifffile
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
