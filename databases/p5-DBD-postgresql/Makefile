# $NetBSD: Makefile,v 1.27 2004/01/21 09:35:08 jlam Exp $
#

VER=		1.22
DISTNAME=	DBD-Pg-${VER}
PKGNAME=	p5-DBD-postgresql-${VER}
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

POSTGRES_INCLUDE=	${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
POSTGRES_LIB=		${BUILDLINK_PREFIX.postgresql-lib}/lib
MAKE_ENV+=		POSTGRES_INCLUDE="${POSTGRES_INCLUDE}"
MAKE_ENV+=		POSTGRES_LIB="${POSTGRES_LIB}"

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
