# $NetBSD: Makefile,v 1.12 2009/10/24 16:21:15 sno Exp $
#

DISTNAME=		Carp-Clan-6.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ccl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Carp-Clan/
COMMENT=		Report errors from perspective of a "clan" of modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Carp/Clan/.packlist
MAKE_PARAMS+=		< /dev/null

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
