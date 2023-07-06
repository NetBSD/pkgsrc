# $NetBSD: Makefile,v 1.3 2023/07/06 09:38:20 wiz Exp $

DISTNAME=	DBD-MariaDB-1.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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

MYSQL_VERSIONS_ACCEPTED=	mariadb106 mariadb105 mariadb104

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
