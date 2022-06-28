# $NetBSD: Makefile,v 1.23 2022/06/28 11:31:37 wiz Exp $

DISTNAME=	RDB-2.6d
PKGNAME=	rdb-2.6.4
PKGREVISION=	11
CATEGORIES=	databases
MASTER_SITES=	# ftp://ftp.sunet.se/pub/unix/databases/flat-file/RDB/

MAINTAINER=	njohnston@globaltetrahedron.com
#HOMEPAGE=	ftp://ftp.sunet.se/pub/unix/databases/flat-file/RDB/
COMMENT=	Relational database system that uses standard filters via pipes

WRKSRC=		${WRKDIR}/rdb
NO_BUILD=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL+=	column compute dataent etbl headchg jointbl lst2tbl mergetbl
REPLACE_PERL+=	mktbl ptbl rdb rdbt repair reporttbl row search sorttbl
REPLACE_PERL+=	subtotal summ tbl2lst uniqtbl valid

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.pkg.mk"
