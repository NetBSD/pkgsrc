# $NetBSD: Makefile,v 1.7 2002/10/21 11:56:49 wiz Exp $

DISTNAME=	pgsql_perl5-1.9.0
PKGNAME=	p5-postgresql-1.9.0
SVR4_PKGNAME=	p5pgs
CATEGORIES=	databases devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pg/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pobox.com/~gbarr/perl-ldap/
COMMENT=	Perl interface class for PostgreSQL

USE_BUILDLINK2=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Pg/.packlist

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
MAKE_PARAMS=	DEFINE="-DPERL_POLLUTE=1"
MAKE_ENV+=	POSTGRES_HOME="${BUILDLINK_PREFIX.postgresql-lib}"

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
