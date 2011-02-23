# $NetBSD: Makefile,v 1.17 2011/02/23 10:32:29 adam Exp $

DISTNAME=	dbxml-2.5.16
PKGNAME=	${DISTNAME:S/db/bdb-/}
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.oracle.com/us/products/database/berkeley-db/
COMMENT=	Native XML data manager built on Berkeley DB
LICENSE=	modified-bsd AND apache-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	dbxml<=1.2.1

WRKSRC=			${WRKDIR}/${DISTNAME}/dbxml

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db5}
CONFIGURE_ARGS+=	--with-xerces=${BUILDLINK_PREFIX.xerces-c}
CONFIGURE_ARGS+=	--with-xqilla=${BUILDLINK_PREFIX.xqilla}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ENV+=		BDB_TYPE=${BDB_TYPE}

BDB_ACCEPTED=		db4 db5
.include "../../mk/bdb.buildlink3.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../textproc/xqilla/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
