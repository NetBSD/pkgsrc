# $NetBSD: Makefile,v 1.71 2016/04/27 16:52:19 wiz Exp $

DISTNAME=	DBI-1.636
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
