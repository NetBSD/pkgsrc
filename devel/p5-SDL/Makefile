# $NetBSD: Makefile,v 1.5 2003/02/13 14:54:08 agc Exp $

DISTNAME=	SDL_perl-1.19.2
PKGNAME=	p5-SDL-1.19.2
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://sdlperl.org/SDL_perl/

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for SDL

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SDL_perl/.packlist

BUILDLINK_DEPENDS.SDL=		SDL>=1.2.5
BUILDLINK_DEPENDS.SDL-mixer=	SDL-mixer>=1.2.4

BROKEN=		OpenGL.xs compilation issue, related to XFree86 version

.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/SDL_gfx/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../graphics/SDL-image/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
