# $NetBSD: Makefile,v 1.2 2000/05/03 15:50:24 rh Exp $
#

DISTNAME=	DBD-Pg-0.93
PKGNAME=	p5-DBD-postgresql-0.93
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.postgresql.org/

DEPENDS+=	postgresql-6.5.3:../../databases/postgresql
DEPENDS+=	p5-DBI-1.08:../../databases/p5-DBI

USE_PERL5=	YES

PGUSER?=                pgsql
PGPREFIX=               ${PREFIX}/${PGUSER}

CONFIGURE_ENV+=		POSTGRES_INCLUDE=${PREFIX}/include/pgsql
CONFIGURE_ENV+=		POSTGRES_LIB=${PREFIX}/lib

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${LOCALBASE}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
