# $NetBSD: Makefile,v 1.50 2018/08/22 09:43:13 wiz Exp $

DISTNAME=	BerkeleyDB-0.55
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BerkeleyDB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/BerkeleyDB/
COMMENT=	Access Berkeley DB
LICENSE=	${PERL5_LICENSE}

BDB_ACCEPTED=		db5 db4 db3 db2
PERL5_PACKLIST=		auto/BerkeleyDB/.packlist
REPLACE_PERL=		mkconsts.pl scan.pl

MAKE_ENV+=	BERKELEYDB_INCLUDE="${BDBBASE}/include/${BDB_TYPE}"
MAKE_ENV+=	BERKELEYDB_LIB="${BDBBASE}/lib"
MAKE_ENV+=	BERKELEYDB_NAME=${BDB_LIBS:Q}

.include "../../lang/perl5/module.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
