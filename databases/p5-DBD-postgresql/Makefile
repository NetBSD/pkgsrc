# $NetBSD: Makefile,v 1.9 2001/05/25 20:40:03 mjl Exp $
#

VER=		0.99
DISTNAME=	DBD-Pg-${VER}
PKGNAME=	p5-DBD-postgresql-${VER}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.postgresql.org/
COMMENT=	perl DBI/DBD driver for PostgreSQL databases

DEPENDS+=	postgresql-{6.5.3*,7.0*,lib-*}:../../databases/postgresql-lib
DEPENDS+=	p5-DBI>=1.08:../../databases/p5-DBI

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/Pg/.packlist

PGUSER?=	pgsql
PGPREFIX=	${PREFIX}/${PGUSER}

MAKE_ENV+=	POSTGRES_INCLUDE=${PREFIX}/include/pgsql
MAKE_ENV+=	POSTGRES_LIB=${PREFIX}/lib

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
