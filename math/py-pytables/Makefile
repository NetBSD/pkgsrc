# $NetBSD: Makefile,v 1.1.1.1 2004/04/22 15:17:08 drochner Exp $
#

DISTNAME=		pytables-0.8
PKGNAME=		${PYPKGPREFIX}-pytables-0.8
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pytables/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://pytables.sourceforge.net/
COMMENT=		Database package for large amounts of data

USE_BUILDLINK3=		yes

PYDISTUTILSPKG=		yes
PYSETUPBUILDARGS=	--hdf5=${BUILDLINK_PREFIX.hdf5}
PYSETUPINSTALLARGS=	--hdf5=${BUILDLINK_PREFIX.hdf5}
PYTHON_VERSIONS_ACCEPTED=	22pth 23pth
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	cd ${WRKSRC}/utils; \
	${MV} ptdump ptdump${PYVERSSUFFIX}; \
	${MV} ptrepack ptrepack${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../math/py-numarray/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
