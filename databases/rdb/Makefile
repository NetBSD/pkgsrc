# $NetBSD: Makefile,v 1.9 2006/01/22 23:35:29 rillig Exp $

DISTNAME=	RDB-2.6d
PKGNAME=	rdb-2.6.4
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.rand.org/pub/RDB-hobbs/

MAINTAINER=	njohnston@globaltetrahedron.com
HOMEPAGE=	ftp://ftp.rand.org/pub/RDB-hobbs/
COMMENT=	Relational database system that uses standard filters via pipes

WRKSRC=		${WRKDIR}/rdb
NO_BUILD=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL+=	column compute dataent etbl headchg jointbl lst2tbl mergetbl
REPLACE_PERL+=	mktbl ptbl rdb rdbt repair reporttbl row search sorttbl
REPLACE_PERL+=	subtotal summ tbl2lst uniqtbl valid

.include "../../mk/bsd.pkg.mk"
