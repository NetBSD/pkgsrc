# $NetBSD: Makefile,v 1.67 2015/01/14 13:09:29 wiz Exp $

DISTNAME=	DBI-1.633
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBI/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/DBI/.packlist
REPLACE_PERL=		dbixs_rev.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
