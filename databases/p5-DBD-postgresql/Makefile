# $NetBSD: Makefile,v 1.20 2002/10/27 19:39:01 seb Exp $
#

VER=		1.13
DISTNAME=	DBD-Pg-${VER}
PKGNAME=	p5-DBD-postgresql-${VER}
PKGREVISION=	2
SVR4_PKGNAME=	p5dpo
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/JBAKER/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.postgresql.org/
COMMENT=	perl DBI/DBD driver for PostgreSQL databases

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/Pg/.packlist

PGUSER?=	pgsql
PGPREFIX=	${PREFIX}/${PGUSER}

MAKE_ENV+=	POSTGRES_INCLUDE=${BUILDLINK_PREFIX.postgresql-lib}/include/pgsql
MAKE_ENV+=	POSTGRES_LIB=${BUILDLINK_PREFIX.postgresql-lib}/lib

.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
