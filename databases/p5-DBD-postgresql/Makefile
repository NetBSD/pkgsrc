# $NetBSD: Makefile,v 1.29 2004/07/24 22:45:15 recht Exp $
#

VER=		1.22
DISTNAME=	DBD-Pg-${VER}
PKGNAME=	p5-DBD-postgresql-${VER}
PKGREVISION=	1
SVR4_PKGNAME=	p5dpo
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/dbdpg/projdisplay.php
COMMENT=	Perl DBI/DBD driver for PostgreSQL databases

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/Pg/.packlist

PGUSER?=	pgsql
PGPREFIX=	${PREFIX}/${PGUSER}

POSTGRES_INCLUDE=	${PGSQL_PREFIX}/include/postgresql
POSTGRES_LIB=		${PGSQL_PREFIX}/lib
MAKE_ENV+=		POSTGRES_INCLUDE="${POSTGRES_INCLUDE}"
MAKE_ENV+=		POSTGRES_LIB="${POSTGRES_LIB}"

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
