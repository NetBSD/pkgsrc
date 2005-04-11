# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:29 tv Exp $
#

DISTNAME=		Carp-Clan-5.3
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ccl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Carp-Clan/
COMMENT=		Report errors from perspective of caller of a "clan" of modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Carp/Clan/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
