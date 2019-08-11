# $NetBSD: Makefile,v 1.23 2019/08/11 13:18:30 wiz Exp $
#

DISTNAME=		Ima-DBI-0.35
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/P/PE/PERRIN/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Ima-DBI
COMMENT=		Perl5 module for DB connection caching and organization

DEPENDS+=		p5-DBI>=1.20:../../databases/p5-DBI
DEPENDS+=		p5-DBIx-ContextualFetch>=1.00:../../databases/p5-DBIx-ContextualFetch
DEPENDS+=		p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable

PERL5_PACKLIST=		auto/Ima/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
