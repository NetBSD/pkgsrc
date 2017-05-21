# $NetBSD: Makefile,v 1.36 2017/05/21 07:52:55 adam Exp $

DISTNAME=	tables-3.4.2
PKGNAME=	${PYPKGPREFIX}-py${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tables/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pytables.org/
COMMENT=	Database package for large amounts of data
LICENSE=	modified-bsd

PYSETUPBUILDARGS+=	--bzip2=${BUILDLINK_PREFIX.bzip2}
PYSETUPBUILDARGS+=	--hdf5=${BUILDLINK_PREFIX.hdf5}
PYSETUPBUILDARGS+=	--lzo=${BUILDLINK_PREFIX.lzo}
PYSETUPINSTALLARGS=	${PYSETUPBUILDARGS}

DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
DEPENDS+=	${PYPKGPREFIX}-numexpr>=2.0:../../math/py-numexpr

USE_LANGUAGES=		c c++

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		mv pt2to3 pt2to3${PYVERSSUFFIX} && \
		mv ptdump ptdump${PYVERSSUFFIX} && \
		mv ptrepack ptrepack${PYVERSSUFFIX} && \
		mv pttree pttree${PYVERSSUFFIX}

do-test:
	(cd ${WRKSRC}/tables/tests && ${PYTHONBIN} test_all.py)

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
