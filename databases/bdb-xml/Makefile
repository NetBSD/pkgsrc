# $NetBSD: Makefile,v 1.7 2006/02/05 23:08:30 joerg Exp $

DISTNAME=	dbxml-1.2.1
PKGNAME=	${DISTNAME:S/db/bdb-/}
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.sleepycat.com/products/xml.shtml
COMMENT=	Native XML data manager built on Berkeley DB

CONFLITCS=	dbxml<=1.2.1

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIG_GUESS_OVERRIDE=	../dist/config.guess
CONFIG_SUB_OVERRIDE=	../dist/config.sub
CONFIG_STATUS_OVERRIDE=	../dist/config.status
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-xerces=${BUILDLINK_PREFIX.xerces-c}
CONFIGURE_ARGS+=	--with-pathan=${BUILDLINK_PREFIX.libpathan}

.include "../../databases/db4/buildlink3.mk"
.include "../../textproc/libpathan/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
