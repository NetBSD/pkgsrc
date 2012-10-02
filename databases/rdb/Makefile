# $NetBSD: Makefile,v 1.12 2012/10/02 21:25:51 asau Exp $

DISTNAME=	RDB-2.6d
PKGNAME=	rdb-2.6.4
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.sunet.se/pub/unix/databases/flat-file/RDB/

MAINTAINER=	njohnston@globaltetrahedron.com
HOMEPAGE=	ftp://ftp.sunet.se/pub/unix/databases/flat-file/RDB/
COMMENT=	Relational database system that uses standard filters via pipes

WRKSRC=		${WRKDIR}/rdb
NO_BUILD=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL+=	column compute dataent etbl headchg jointbl lst2tbl mergetbl
REPLACE_PERL+=	mktbl ptbl rdb rdbt repair reporttbl row search sorttbl
REPLACE_PERL+=	subtotal summ tbl2lst uniqtbl valid

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
