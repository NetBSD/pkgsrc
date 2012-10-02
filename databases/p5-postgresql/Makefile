# $NetBSD: Makefile,v 1.29 2012/10/02 21:25:36 asau Exp $

DISTNAME=	pgsql_perl5-1.9.0
PKGNAME=	p5-postgresql-1.9.0
PKGREVISION=	12
SVR4_PKGNAME=	p5pgs
CATEGORIES=	databases devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gborg.postgresql.org/project/pgperl/projdisplay.php
COMMENT=	Perl interface class for PostgreSQL

PERL5_PACKLIST=		auto/Pg/.packlist

# Until the source catches up to the current Perl API, we need PERL_POLLUTE
# to look like an older perl.
MAKE_PARAMS=	DEFINE="-DPERL_POLLUTE=1"
MAKE_ENV+=	POSTGRES_HOME=${PGSQL_PREFIX:Q}

.include "../../lang/perl5/module.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
