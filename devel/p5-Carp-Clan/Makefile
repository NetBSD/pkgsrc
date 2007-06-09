# $NetBSD: Makefile,v 1.9 2007/06/09 23:26:44 abs Exp $
#

DISTNAME=		Carp-Clan-5.9
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ccl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Carp-Clan/
COMMENT=		Report errors from perspective of a "clan" of modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Carp/Clan/.packlist
MAKE_PARAMS+=		< /dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
