# $NetBSD: Makefile,v 1.1.1.1 1999/12/23 13:15:12 rh Exp $
#

DISTNAME=	pgsql_perl5-1.8.1
PKGNAME=	p5-pgsql-1.8.1
CATEGORIES=	databases devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pg/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pobox.com/~gbarr/perl-ldap/

DEPENDS+=	postgresql-*:../../databases/postgresql

USE_PERL5=	YES
MAKE_ENV+=	POSTGRES_HOME="${PREFIX}/pgsql"

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
