# $NetBSD: Makefile,v 1.25 2003/07/21 16:39:07 martti Exp $
#

VER=		1.22
DISTNAME=	DBD-Pg-${VER}
PKGNAME=	p5-DBD-postgresql-${VER}
# PKGREVISION=	3
SVR4_PKGNAME=	p5dpo
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/dbdpg/projdisplay.php
COMMENT=	Perl DBI/DBD driver for PostgreSQL databases

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/Pg/.packlist

PGUSER?=	pgsql
PGPREFIX=	${PREFIX}/${PGUSER}

MAKE_ENV+=	POSTGRES_INCLUDE=${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
MAKE_ENV+=	POSTGRES_LIB=${BUILDLINK_PREFIX.postgresql-lib}/lib

.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
