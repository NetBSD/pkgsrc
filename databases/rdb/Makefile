# $NetBSD: Makefile,v 1.5 2003/07/21 16:39:13 martti Exp $

DISTNAME=	RDB-2.6d
PKGNAME=	rdb-2.6.4
WRKSRC=		${WRKDIR}/rdb
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.rand.org/pub/RDB-hobbs/

MAINTAINER=	njohnston@globaltetrahedron.com
HOMEPAGE=	ftp://ftp.rand.org/pub/RDB-hobbs/
COMMENT=	Relational database system that uses standard filters via pipes

NO_BUILD=	yes
USE_BUILDLINK2=	yes

REPLACE_PERL=	column compute dataent etbl headchg jointbl lst2tbl mergetbl
REPLACE_PERL+=	mktbl ptbl rdb rdbt repair reporttbl row search sorttbl
REPLACE_PERL+=	subtotal summ tbl2lst uniqtbl valid

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
