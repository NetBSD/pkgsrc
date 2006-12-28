# $NetBSD: Makefile,v 1.38 2006/12/28 12:12:57 joerg Exp $
#

VER=		1.48
DISTNAME=	DBD-Pg-${VER}
PKGNAME=	p5-DBD-postgresql-${VER}
SVR4_PKGNAME=	p5dpo
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/dbdpg/projdisplay.php
COMMENT=	Perl DBI/DBD driver for PostgreSQL databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/DBD/Pg/.packlist

PGUSER?=	pgsql
PGPREFIX=	${PREFIX}/${PGUSER}

POSTGRES_INCLUDE=	${PGSQL_PREFIX}/include/postgresql
POSTGRES_LIB=		${PGSQL_PREFIX}/lib
MAKE_ENV+=		POSTGRES_INCLUDE=${POSTGRES_INCLUDE:Q}
MAKE_ENV+=		POSTGRES_LIB=${POSTGRES_LIB:Q}

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
