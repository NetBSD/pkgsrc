# $NetBSD: Makefile,v 1.16 2004/01/03 18:49:39 reed Exp $
#

DISTNAME=	SDL_perl-1.19.2
PKGNAME=	p5-SDL-1.19.2
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://sdlperl.org/SDL_perl/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sdlperl.org/
COMMENT=	Perl module for SDL

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SDL_perl/.packlist

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/SDL_gfx/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../net/SDL_net/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
