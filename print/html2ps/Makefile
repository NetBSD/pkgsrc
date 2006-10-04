# $NetBSD: Makefile,v 1.25 2006/10/04 21:56:34 wiz Exp $
#

DISTNAME=	html2ps-1.0b4
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://user.it.uu.se/~jan/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://user.it.uu.se/~jan/html2ps.html
COMMENT=	HTML to PostScript converter

DEPENDS+=	ImageMagick>=5.3.9nb1:../../graphics/ImageMagick
DEPENDS+=	jpeg>=6b:../../graphics/jpeg
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	weblint-[0-9]*:../../www/weblint

USE_TOOLS+=	gs:run perl:run
TEX_ACCEPTED=	teTeX3

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/html2ps
	@cd ${WRKSRC} && PATH=${LOCALBASE}/bin:${PREFIX}/bin ./install ${PREFIX}
	@${INSTALL_DATA} ${WRKSRC}/sample ${PREFIX}/share/html2ps/sample.rc

.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
