# $NetBSD: Makefile,v 1.13 2004/12/01 15:57:18 wiz Exp $
#

DISTNAME=	frozen-bubble-1.0.0
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://zarb.org/~gc/fb/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.frozen-bubble.org/
COMMENT=	Pop the frozen bubbles

DEPENDS+=	p5-SDL>=1.19.2:../../devel/p5-SDL

USE_PERL5=	run
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

MAKE_ENV+=	PERL5="${PERL5}" CP="${CP}"

REPLACE_PERL=	frozen-bubble*
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/fb_c_stuff/.packlist

post-extract:
	${RM} -rf ${WRKSRC}/gfx/.xvpics

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
