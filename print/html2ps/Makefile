# $NetBSD: Makefile,v 1.1.1.1 2000/04/23 05:55:02 kim Exp $
#

DISTNAME=	html2ps-1.0b1
CATEGORIES=	www
MASTER_SITES=	http://www.tdb.uu.se/~jan/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.tdb.uu.se/~jan/html2ps.html

DEPENDS+=	ImageMagick-*:../../graphics/ImageMagick
DEPENDS+=	ghostscript-*:../../print/ghostscript5
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	p5-PerlMagick-*:../../graphics/p5-PerlMagick
DEPENDS+=	p5-libwww-*:../../www/p5-libwww
DEPENDS+=	teTeX-bin>=1.0.6:../../print/teTeX-bin
DEPENDS+=	weblint-*:../../www/weblint

USE_PERL5=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	@cd ${WRKSRC} && ./install ${PREFIX}
	@${INSTALL_DATA} ${WRKSRC}/sample ${PREFIX}/share/html2ps/sample.rc

.include "../../mk/bsd.pkg.mk"
