# $NetBSD: Makefile,v 1.10 2006/02/15 16:56:09 drochner Exp $
#

DISTNAME=		pytables-1.2.1
PKGNAME=		${PYPKGPREFIX}-pytables-1.2.1
CATEGORIES=		math python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pytables/}

MAINTAINER=		tech-pkg@NetBSD.org
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
.include "../../archivers/ucl/buildlink3.mk"
.endif
PYSETUPINSTALLARGS=	${PYSETUPBUILDARGS}
PYTHON_VERSIONS_ACCEPTED=	24 23 22
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	cd ${WRKSRC}/utils; \
	${MV} ptdump ptdump${PYVERSSUFFIX}; \
	${MV} ptrepack ptrepack${PYVERSSUFFIX}; \
	${MV} nctoh5 nctoh5${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
