# $NetBSD: Makefile,v 1.20 2004/09/29 21:24:18 kristerw Exp $
#

DISTNAME=	SDL_perl-1.19.2
PKGNAME=	p5-SDL-1.19.2
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	ftp://sdlperl.org/SDL_perl/

DEPENDS+=	perl-thread>=5.8.0:../../lang/perl58-thread

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sdlperl.org/
COMMENT=	Perl module for SDL

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SDL_perl/.packlist

BUILDLINK_PKGSRCDIR.perl=	../../lang/perl58-thread

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
