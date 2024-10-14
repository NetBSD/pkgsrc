# $NetBSD: Makefile,v 1.19 2024/10/14 06:45:52 wiz Exp $

DISTNAME=	tables-3.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tables/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pytables.org/
COMMENT=	Database package for large amounts of data
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-numexpr>=2.6.2:../../math/py-numexpr

USE_LANGUAGES=	c c++

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pt2to3 pt2to3-${PYVERSSUFFIX} && \
	${MV} ptdump ptdump-${PYVERSSUFFIX} && \
	${MV} ptrepack ptrepack-${PYVERSSUFFIX} && \
	${MV} pttree pttree-${PYVERSSUFFIX} || ${TRUE}

# needs to be installed first
# as of 3.9.2:
# Ran 6799 tests
# FAILED (errors=2, skipped=58)
do-test:
	${PYTHONBIN} -m tables.tests.test_all

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/blosc/buildlink3.mk"
.include "../../devel/blosc2/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
