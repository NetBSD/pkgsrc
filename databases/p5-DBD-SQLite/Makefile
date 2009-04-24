# $NetBSD: Makefile,v 1.23 2009/04/24 07:31:39 sno Exp $
#

DISTNAME=	DBD-SQLite-1.25
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dsl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-SQLite/
COMMENT=	Perl DBI/DBD driver for sqlite databases
LICENSE=	artistic-2.0

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/DBD/SQLite/.packlist
MAKE_PARAMS+=	SQLITE_LOCATION=${PREFIX:Q}

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
