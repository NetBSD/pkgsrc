# $NetBSD: Makefile,v 1.3 2000/08/27 10:37:02 jlam Exp $
#

DISTNAME=	pgsql_perl5-1.8.1
PKGNAME=	p5-pgsql-1.8.1
CATEGORIES=	databases devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pg/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pobox.com/~gbarr/perl-ldap/

DEPENDS+=	postgresql-*:../../databases/postgresql

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Pg/.packlist

MAKE_ENV+=	POSTGRES_HOME="${PREFIX}"

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
