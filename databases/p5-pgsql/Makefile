# $NetBSD: Makefile,v 1.7 2001/05/14 15:04:51 jlam Exp $

DISTNAME=	pgsql_perl5-1.9.0
PKGNAME=	p5-pgsql-1.9.0
CATEGORIES=	databases devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pg/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pobox.com/~gbarr/perl-ldap/
COMMENT=	Perl interface class for PostgreSQL

DEPENDS+=	postgresql-{6.5.3*,7.0*,lib-*}:../../databases/postgresql-lib

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Pg/.packlist

EVAL_PREFIX+=	POSTGRES_HOME=postgresql

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
MAKE_PARAMS=	DEFINE="-DPERL_POLLUTE=1"

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
