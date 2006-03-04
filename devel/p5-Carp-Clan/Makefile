# $NetBSD: Makefile,v 1.5 2006/03/04 21:29:19 jlam Exp $
#

DISTNAME=		Carp-Clan-5.3
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ccl
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Carp-Clan/
COMMENT=		Report errors from perspective of caller of a "clan" of modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Carp/Clan/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
