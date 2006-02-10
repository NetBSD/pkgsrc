# $NetBSD: Makefile,v 1.9 2006/02/10 20:05:11 drochner Exp $
#

DISTNAME=		pytables-1.2.1
PKGNAME=		${PYPKGPREFIX}-pytables-1.2.1
CATEGORIES=		math python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pytables/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pytables.sourceforge.net/
COMMENT=		Database package for large amounts of data


PYDISTUTILSPKG=		yes
PYSETUPBUILDARGS=	--hdf5=${BUILDLINK_PREFIX.hdf5}
PYSETUPINSTALLARGS=	--hdf5=${BUILDLINK_PREFIX.hdf5}
PYTHON_VERSIONS_ACCEPTED=	24 23 22
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

post-extract:
	cd ${WRKSRC}/utils; \
	${MV} ptdump ptdump${PYVERSSUFFIX}; \
	${MV} ptrepack ptrepack${PYVERSSUFFIX}; \
	${MV} nctoh5 nctoh5${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
