# $NetBSD: Makefile,v 1.63 2012/10/02 21:25:28 asau Exp $

DISTNAME=	DBD-Pg-2.19.2
PKGNAME=	p5-${DISTNAME:C/-Pg-/-postgresql-/}
PKGREVISION=	1
SVR4_PKGNAME=	p5dpo
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-Pg/
COMMENT=	Perl DBI/DBD driver for PostgreSQL databases
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{p5-version-[0-9]*,perl>=5.10.0}:../../devel/p5-version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/DBD/Pg/.packlist

POSTGRES_INCLUDE=	${PGSQL_PREFIX}/include/postgresql
POSTGRES_LIB=		${PGSQL_PREFIX}/lib
MAKE_ENV+=		POSTGRES_INCLUDE=${POSTGRES_INCLUDE:Q}
MAKE_ENV+=		POSTGRES_LIB=${POSTGRES_LIB:Q}
REPLACE_PERL+=		testme.tmp.pl

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
