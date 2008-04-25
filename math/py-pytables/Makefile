# $NetBSD: Makefile,v 1.15 2008/04/25 20:39:10 joerg Exp $
#

DISTNAME=		pytables-1.3.3
PKGNAME=		${PYPKGPREFIX}-pytables-1.3.3
CATEGORIES=		math python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pytables/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pytables.sourceforge.net/
COMMENT=		Database package for large amounts of data

PKG_OPTIONS_VAR=	PKG_OPTIONS.pytables
PKG_SUPPORTED_OPTIONS=	lzo ucl
PKG_SUGGESTED_OPTIONS=
.include "../../mk/bsd.options.mk"

PYDISTUTILSPKG=		yes
PYSETUPBUILDARGS=	--hdf5=${BUILDLINK_PREFIX.hdf5}
.if !empty(PKG_OPTIONS:Mlzo)
PYSETUPBUILDARGS+=	--lzo=${BUILDLINK_PREFIX.lzo}
.include "../../archivers/lzo/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mucl)
PYSETUPBUILDARGS+=	--ucl=${BUILDLINK_PREFIX.ucl}
.include "../../devel/ucl/buildlink3.mk"
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
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
