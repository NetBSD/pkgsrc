# $NetBSD: Makefile,v 1.1.1.1 2001/12/20 17:22:16 agc Exp $

DISTNAME=       RDB-2.6d
PKGNAME=        rdb-2.6.4
CATEGORIES=     databases
MASTER_SITES=   ftp://ftp.rand.org/pub/RDB-hobbs/

MAINTAINER=     njohnston@globaltetrahedron.com
HOMEPAGE=       ftp://ftp.rand.org/pub/RDB-hobbs/
COMMENT=        relational database system that uses standard filters via pipes

WRKSRC=         ${WRKDIR}/rdb
NO_BUILD=       yes
USE_BUILDLINK_ONLY=	yes

REPLACE_PERL=	column compute dataent etbl headchg jointbl lst2tbl mergetbl
REPLACE_PERL+=	mktbl ptbl rdb rdbt repair reporttbl row search sorttbl
REPLACE_PERL+=	subtotal summ tbl2lst uniqtbl valid

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
