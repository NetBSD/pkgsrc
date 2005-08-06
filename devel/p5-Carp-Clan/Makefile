# $NetBSD: Makefile,v 1.4 2005/08/06 06:19:08 jlam Exp $
#

DISTNAME=		Carp-Clan-5.3
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ccl
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Carp-Clan/
COMMENT=		Report errors from perspective of caller of a "clan" of modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Carp/Clan/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
