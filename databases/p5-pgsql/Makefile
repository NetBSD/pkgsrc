# $NetBSD: Makefile,v 1.5 2001/02/16 14:17:35 wiz Exp $
#

DISTNAME=	pgsql_perl5-1.8.1
PKGNAME=	p5-pgsql-1.8.1
CATEGORIES=	databases devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pg/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pobox.com/~gbarr/perl-ldap/
COMMENT=	Perl interface class for PostgreSQL

DEPENDS+=	postgresql-*:../../databases/postgresql

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Pg/.packlist

MAKE_ENV+=	POSTGRES_HOME="${PREFIX}"

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
MAKE_PARAMS=	DEFINE="-DPERL_POLLUTE=1"

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
