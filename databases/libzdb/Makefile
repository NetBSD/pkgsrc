# $NetBSD: Makefile,v 1.7 2016/12/04 03:51:15 marino Exp $

DISTNAME=	libzdb-3.1
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.tildeslash.com/libzdb/dist/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.tildeslash.com/libzdb/
COMMENT=	Zild Database Library, a fast thread-safe connection pooling library
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	zdb.pc.in

.include "options.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
