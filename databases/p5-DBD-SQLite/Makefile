# $NetBSD: Makefile,v 1.96 2024/11/01 12:51:49 wiz Exp $

DISTNAME=	DBD-SQLite-1.76
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBD-SQLite
COMMENT=	Perl DBI/DBD driver for sqlite databases (self contained)
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/DBD/SQLite/.packlist
MAKE_PARAMS+=	SQLITE_LOCATION=${BUILDLINK_PREFIX.sqlite3}

.include "../../databases/p5-DBI/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.34
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
