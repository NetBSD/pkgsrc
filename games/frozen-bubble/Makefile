# $NetBSD: Makefile,v 1.4 2003/04/18 17:55:52 salo Exp $
#

DISTNAME=	frozen-bubble-1.0.0
CATEGORIES=	games
MASTER_SITES=	http://people.mandrakesoft.com/~gc/fb/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://www.frozen-bubble.org/
COMMENT=	Pop the frozen bubbles

DEPENDS+=	p5-SDL>=1.19.2:../../devel/p5-SDL

USE_PERL5=	run
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

MAKE_ENV+=	PERL5="${PERL5}" CP="${CP}"

REPLACE_PERL=	frozen-bubble*
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/fb_c_stuff/.packlist

post-extract:
	${RM} -rf ${WRKSRC}/gfx/.xvpics

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
