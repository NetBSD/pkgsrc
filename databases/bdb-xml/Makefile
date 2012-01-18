# $NetBSD: Makefile,v 1.19 2012/01/18 13:49:23 adam Exp $

DISTNAME=	dbxml-2.5.16
PKGNAME=	${DISTNAME:S/db/bdb-/}
PKGREVISION=	1
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
CONFIGURE_ARGS+=	--with-berkeleydb=${BDBBASE}
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
