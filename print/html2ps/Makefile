# $NetBSD: Makefile,v 1.10 2003/09/22 21:02:51 kim Exp $
#

DISTNAME=	html2ps-1.0b1
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.tdb.uu.se/~jan/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.tdb.uu.se/~jan/html2ps.html
COMMENT=	HTML to PostScript converter

DEPENDS+=	ImageMagick>=5.3.9nb1:../../graphics/ImageMagick
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	teTeX{,2}-bin>=1.0.6:../../print/teTeX-bin
DEPENDS+=	weblint-[0-9]*:../../www/weblint

USE_PERL5=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/html2ps
	@cd ${WRKSRC} && ./install ${PREFIX}
	@${INSTALL_DATA} ${WRKSRC}/sample ${PREFIX}/share/html2ps/sample.rc

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
