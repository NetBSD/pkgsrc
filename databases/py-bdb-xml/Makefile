# $NetBSD: Makefile,v 1.22 2014/05/09 07:36:57 wiz Exp $

DISTNAME=	dbxml-2.5.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/db/bdb-/}
CATEGORIES=	databases python
MASTER_SITES=	http://download.oracle.com/berkeley-db/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.oracle.com/us/products/database/berkeley-db/
COMMENT=	Python wrapper for Berkeley DB XML C++ API
LICENSE=	modified-bsd AND apache-1.1

CONFLICTS=	${PYPKGPREFIX}-dbxml<=1.2.1

WRKSRC=		${WRKDIR}/${DISTNAME}/dbxml/src/python

USE_LANGUAGES=		c c++
NO_CONFIGURE=		yes
PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.5.16

SUBST_CLASSES+=		fix-path
SUBST_STAGE.fix-path=	pre-build
SUBST_MESSAGE.fix-path=	Fixing library paths.
SUBST_FILES.fix-path=	setup.py
SUBST_SED.fix-path=	-e 's,@prefix@,${PREFIX},'
SUBST_SED.fix-path+=	-e 's,@DB_DIR@,${BDBBASE},'
SUBST_SED.fix-path+=	-e 's,@XERCES_DIR@,${BUILDLINK_PREFIX.xerces-c},'
SUBST_SED.fix-path+=	-e 's,@XQILLA_DIR@,${BUILDLINK_PREFIX.xqilla},'
SUBST_SED.fix-path+=	-e 's,@BDB_TYPE@,${BDB_TYPE},'

.include "../../databases/bdb-xml/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
