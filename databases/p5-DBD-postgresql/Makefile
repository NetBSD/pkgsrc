# $NetBSD: Makefile,v 1.17 2002/06/18 12:43:02 wiz Exp $
#

VER=		1.13
DISTNAME=	DBD-Pg-${VER}
PKGNAME=	p5-DBD-postgresql-${VER}
PKGREVISION=	1
SVR4_PKGNAME=	p5dpo
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/JBAKER/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.postgresql.org/
COMMENT=	perl DBI/DBD driver for PostgreSQL databases

DEPENDS+=	p5-DBI>=1.08:../../databases/p5-DBI

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/Pg/.packlist

PGUSER?=	pgsql
PGPREFIX=	${PREFIX}/${PGUSER}

MAKE_ENV+=	POSTGRES_INCLUDE=${BUILDLINK_DIR}/include/pgsql
MAKE_ENV+=	POSTGRES_LIB=${BUILDLINK_DIR}/lib

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../databases/postgresql-lib/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
