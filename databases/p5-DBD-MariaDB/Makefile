# $NetBSD: Makefile,v 1.6 2024/04/02 07:26:19 wen Exp $

DISTNAME=	DBD-MariaDB-1.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBD-MariaDB
COMMENT=	MariaDB and MySQL driver for the Perl5 Database Interface (DBI)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-CheckLib>=1.12:../../devel/p5-Devel-CheckLib
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/DBD/MariaDB/.packlist

REPLACE_PERL=		lib/DBD/MariaDB.pm

# MAKE_PARAMS+=		--nocatchstderr

MYSQL_VERSIONS_ACCEPTED=	${MARIADB_VERSIONS_ALL}

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
