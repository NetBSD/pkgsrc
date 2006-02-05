# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:35 joerg Exp $

DISTNAME=	dbxml-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/db/bdb-/}
PKGREVISION=	5
CATEGORIES=	databases python
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.sleepycat.com/products/xml.shtml
COMMENT=	Python wrapper for Berkeley DB XML C++ API

CONFLICTS=	${PYPKGPREFIX}-dbxml<=1.2.1

WRKSRC=		${WRKDIR}/${DISTNAME}/src/python
PYDISTUTILSPKG=	YES
NO_CONFIGURE=	YES

.include "../../lang/python/extension.mk"
PYSETUPBUILDARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4} \
			--with-xerces=${BUILDLINK_PREFIX.xerces-c} \
			--with-pathan=${BUILDLINK_PREFIX.libpathan}

.include "../../databases/bdb-xml/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../textproc/libpathan/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
