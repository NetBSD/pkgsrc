# $NetBSD: Makefile,v 1.75 2017/06/05 14:22:26 ryoon Exp $

DISTNAME=	DBI-1.636
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dbi.perl.org/
COMMENT=	The database-independent Perl database access API
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/DBI/.packlist
REPLACE_PERL=		dbixs_rev.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
