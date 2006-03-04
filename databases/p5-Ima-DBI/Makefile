# $NetBSD: Makefile,v 1.7 2006/03/04 21:29:10 jlam Exp $
#

DISTNAME=		Ima-DBI-0.33
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5idi
PKGREVISION=		2
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/T/TM/TMTM/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Ima-DBI/
COMMENT=		Perl5 module for DB connection caching and organization

DEPENDS+=		p5-DBI>=1.20:../../databases/p5-DBI
DEPENDS+=		p5-Class-WhiteHole>=0.03:../../devel/p5-Class-WhiteHole
DEPENDS+=		p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable

PERL5_PACKLIST=		auto/Ima/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
