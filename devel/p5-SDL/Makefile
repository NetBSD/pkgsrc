# $NetBSD: Makefile,v 1.65 2018/11/14 22:21:19 kleink Exp $

DISTNAME=	SDL-2.548
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SDL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~froggs/SDL/lib/pods/SDL.pod
COMMENT=	SDL - Simple DirectMedia Layer for Perl
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Alien-SDL-[0-9]*:../../devel/p5-Alien-SDL
BUILD_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most

PERL5_OPTIONS+=	threads
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/SDL/.packlist

REPLACE_PERL+=	lib/SDL.pm
REPLACE_PERL+=	lib/SDL/Constants.pm
REPLACE_PERL+=	lib/SDL/SMPEG/Info.pm
REPLACE_PERL+=	lib/SDL/TTFont.pm
REPLACE_PERL+=	lib/SDL/Tutorial.pm
REPLACE_PERL+=	lib/SDL/Tutorial/Animation.pm
REPLACE_PERL+=	lib/SDL_perl.pm
REPLACE_PERL+=	lib/SDLx/App.pm

.include "../../audio/SDL_mixer/buildlink3.mk"

.include "../../devel/libexecinfo/buildlink3.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_Pango/buildlink3.mk"

.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
