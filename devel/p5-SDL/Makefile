# $NetBSD: Makefile,v 1.1 2003/01/02 00:22:30 explorer Exp $

DISTNAME=	SDL_perl-1.19.2
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://sdlperl.org/SDL_perl/

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for SDL

DEPENDS+=	SDL>=1.2.5:../../devel/SDL
DEPENDS+=	SDL-image>=1.2.2:../../graphics/SDL-image
DEPENDS+=	SDL-mixer>=1.2.4:../../audio/SDL-mixer
DEPENDS+=	SDL_ttf>=2.0.3:../../devel/SDL_ttf
DEPENDS+=	SDL_gfx>=2.0.3:../../devel/SDL_gfx

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SDL_perl/.packlist

.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../graphics/SDL-image/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../devel/SDL_gfx/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/x11.buildlink2.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
