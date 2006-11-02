# $NetBSD: Makefile,v 1.26 2006/11/02 21:28:59 rillig Exp $
#

DISTNAME=	frozen-bubble-1.0.0
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://zarb.org/~gc/fb/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://www.frozen-bubble.org/
COMMENT=	Pop the frozen bubbles

DEPENDS+=	p5-SDL>=1.19.2:../../devel/p5-SDL

USE_TOOLS+=	gmake perl:run

MAKE_ENV+=	PERL5=${PERL5:Q} CP=${CP:Q} INSTALLDIRS="vendor"
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

REPLACE_PERL+=	frozen-bubble* gfx/shoot/create.pl
PERL5_PACKLIST=	auto/fb_c_stuff/.packlist

post-extract:
	${RM} -rf ${WRKSRC}/gfx/.xvpics

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
