# $NetBSD: Makefile,v 1.12 2004/10/03 00:14:44 tv Exp $
#

DISTNAME=	frozen-bubble-1.0.0
PKGREVISION=	4
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
.include "../../lang/perl5/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
