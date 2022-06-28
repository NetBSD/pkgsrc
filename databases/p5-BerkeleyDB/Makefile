# $NetBSD: Makefile,v 1.57 2022/06/28 11:31:20 wiz Exp $

DISTNAME=	BerkeleyDB-0.64
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=BerkeleyDB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/BerkeleyDB
COMMENT=	Access Berkeley DB
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta
TEST_DEPENDS+=	p5-Test-CPAN-Meta-JSON-[0-9]*:../../devel/p5-Test-CPAN-Meta-JSON
TEST_DEPENDS+=	p5-MLDBM-[0-9]*:../../databases/p5-MLDBM

BDB_ACCEPTED=		db5 db4 db3 db2
PERL5_PACKLIST=		auto/BerkeleyDB/.packlist
REPLACE_PERL=		mkconsts.pl scan.pl

MAKE_ENV+=	BERKELEYDB_INCLUDE="${BDBBASE}/include/${BDB_TYPE}"
MAKE_ENV+=	BERKELEYDB_LIB="${BDBBASE}/lib"
MAKE_ENV+=	BERKELEYDB_NAME=${BDB_LIBS:Q}

.include "../../lang/perl5/module.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
