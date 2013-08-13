# $NetBSD: Makefile,v 1.28 2013/08/13 21:24:37 markd Exp $
#

DISTNAME=		tables-2.4.0
PKGNAME=		${PYPKGPREFIX}-py${DISTNAME}
CATEGORIES=		math python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pytables/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pytables.org/
COMMENT=		Database package for large amounts of data
LICENSE=		modified-bsd

PKG_OPTIONS_VAR=	PKG_OPTIONS.pytables
PKG_SUPPORTED_OPTIONS=	lzo
PKG_SUGGESTED_OPTIONS=
.include "../../mk/bsd.options.mk"

PYDISTUTILSPKG=		yes
PYSETUPBUILDARGS=	--hdf5=${BUILDLINK_PREFIX.hdf5}
.if !empty(PKG_OPTIONS:Mlzo)
PYSETUPBUILDARGS+=	--lzo=${BUILDLINK_PREFIX.lzo}
.include "../../archivers/lzo/buildlink3.mk"
.else
PYSETUPBUILDARGS+=	--lzo=XXX
.endif
PYSETUPINSTALLARGS=	${PYSETUPBUILDARGS}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	cd ${WRKSRC}/utils; \
	${MV} ptdump ptdump${PYVERSSUFFIX}; \
	${MV} ptrepack ptrepack${PYVERSSUFFIX}; \
	${MV} nctoh5 nctoh5${PYVERSSUFFIX}

do-test:
	(cd ${WRKSRC}/tables/tests && ${PYTHONBIN} test_all.py)

.include "../../lang/python/extension.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
BUILDLINK_API_DEPENDS.pycython+= ${PYPKGPREFIX}-cython>=0.13
.include "../../devel/py-cython/buildlink3.mk"
.include "../../math/py-numexpr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
