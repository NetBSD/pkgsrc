# $NetBSD: Makefile,v 1.16 2009/07/12 12:07:44 obache Exp $

DISTNAME=	dbxml-1.2.1
PKGNAME=	${DISTNAME:S/db/bdb-/}
PKGREVISION=	9
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.oracle.com/database/berkeley-db/xml/index.html
COMMENT=	Native XML data manager built on Berkeley DB

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	dbxml<=1.2.1

WRKSRC=			${WRKDIR}/${DISTNAME}/build_unix
GNU_CONFIGURE=		YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIG_GUESS_OVERRIDE=	../dist/config.guess
CONFIG_SUB_OVERRIDE=	../dist/config.sub
CONFIG_STATUS_OVERRIDE=	../dist/config.status
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES

CONFIGURE_ARGS+=	--with-berkeleydb=${BUILDLINK_PREFIX.db46}
CONFIGURE_ARGS+=	--with-xerces=${BUILDLINK_PREFIX.xerces-c}
CONFIGURE_ARGS+=	--with-pathan=${BUILDLINK_PREFIX.libpathan}

.include "../../databases/db46/buildlink3.mk"
.include "../../textproc/libpathan/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
