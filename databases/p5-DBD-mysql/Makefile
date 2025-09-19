# $NetBSD: Makefile,v 1.88 2025/09/19 23:14:31 gdt Exp $

DISTNAME=	DBD-mysql-5.013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	bad@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBD-mysql
COMMENT=	Perl DBI/DBD driver for MySQL databases
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

PERL5_PACKLIST=		auto/DBD/mysql/.packlist

REPLACE_PERL=		lib/DBD/mysql.pm

MAKE_PARAMS+=		--nocatchstderr

# Version 5 of p5-DBD-mysql drops support for building against mariadb
# client libraries.  (Version 4 allowed this.)
# Upstream does not consider this a bug:
#   https://github.com/perl5-dbi/DBD-mysql/issues/481
# and says that users should use p5-DBD-MariaDB.  However, that is not
# interchangeable, erroring on at least some legal settings with
# DBD:mysql.

# Newer mysql versions should be fine too.  This is not
# ${MYSQL_VERSIONS_ALL} because that includes MariaDB, exposing that
# some think MariaDB should be considered a mysql version, and some
# think not.
MYSQL_VERSIONS_ACCEPTED=	80

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
