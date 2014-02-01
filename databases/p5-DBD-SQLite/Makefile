# $NetBSD: Makefile,v 1.41 2014/02/01 03:14:38 markd Exp $

DISTNAME=	DBD-SQLite-1.40
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dsl
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-SQLite/
COMMENT=	Perl DBI/DBD driver for sqlite databases (self contained)
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/DBD/SQLite/.packlist
MAKE_PARAMS+=	SQLITE_LOCATION=${BUILDLINK_PREFIX.sqlite3}

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.580
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7.17

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
