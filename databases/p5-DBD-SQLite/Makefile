# $NetBSD: Makefile,v 1.25 2010/08/21 16:32:56 seb Exp $
#

DISTNAME=	DBD-SQLite-1.29
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5dsl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-SQLite/
COMMENT=	Perl DBI/DBD driver for sqlite databases
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/DBD/SQLite/.packlist
#MAKE_PARAMS+=	SQLITE_LOCATION=${PREFIX:Q}

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.580
.include "../../databases/p5-DBI/buildlink3.mk"
#.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
