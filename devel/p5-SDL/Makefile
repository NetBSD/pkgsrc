# $NetBSD: Makefile,v 1.8 2003/05/02 11:54:40 wiz Exp $

DISTNAME=	SDL_perl-1.19.2
PKGNAME=	p5-SDL-1.19.2
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://sdlperl.org/SDL_perl/

MAINTAINER=	packages@netbsd.org
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
.include "../../mk/bsd.pkg.mk"
