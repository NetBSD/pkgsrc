# $NetBSD: Makefile,v 1.58 2017/06/05 14:23:33 ryoon Exp $
#

DISTNAME=	SDL_Perl-2.1.2
PKGNAME=	p5-SDL-2.1.2
PKGREVISION=	19
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DG/DGOEHRIG/}

PERL5_OPTIONS+=	threads

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sdlperl.org/
COMMENT=	Perl module for SDL

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/SDL/.packlist

pre-configure:
	${CAT} ${WRKSRC}/make/lib/SDL/Build/Netbsd.pm | \
		${SED} 's|Netbsd|Dragonfly|g' > \
		${WRKSRC}/make/lib/SDL/Build/Dragonfly.pm

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
