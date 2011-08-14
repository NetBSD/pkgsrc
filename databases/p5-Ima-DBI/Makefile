# $NetBSD: Makefile,v 1.12 2011/08/14 08:18:08 obache Exp $
#

DISTNAME=		Ima-DBI-0.35
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5idi
CATEGORIES=		perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/P/PE/PERRIN/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Ima-DBI/
COMMENT=		Perl5 module for DB connection caching and organization

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-DBI>=1.20:../../databases/p5-DBI
DEPENDS+=		p5-DBIx-ContextualFetch>=1.00:../../databases/p5-DBIx-ContextualFetch
DEPENDS+=		p5-Class-Data-Inheritable>=0.02:../../devel/p5-Class-Data-Inheritable

PERL5_PACKLIST=		auto/Ima/DBI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
