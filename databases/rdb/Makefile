# $NetBSD: Makefile,v 1.3 2002/11/15 00:39:53 jlam Exp $

DISTNAME=	RDB-2.6d
PKGNAME=	rdb-2.6.4
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.rand.org/pub/RDB-hobbs/

MAINTAINER=	njohnston@globaltetrahedron.com
HOMEPAGE=	ftp://ftp.rand.org/pub/RDB-hobbs/
COMMENT=	relational database system that uses standard filters via pipes

WRKSRC=		${WRKDIR}/rdb
NO_BUILD=	yes
USE_BUILDLINK2=	yes

REPLACE_PERL=	column compute dataent etbl headchg jointbl lst2tbl mergetbl
REPLACE_PERL+=	mktbl ptbl rdb rdbt repair reporttbl row search sorttbl
REPLACE_PERL+=	subtotal summ tbl2lst uniqtbl valid

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
