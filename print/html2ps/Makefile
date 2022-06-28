# $NetBSD: Makefile,v 1.45 2022/06/28 11:35:28 wiz Exp $
#

DISTNAME=	html2ps-1.0b7
PKGREVISION=	13
CATEGORIES=	print
MASTER_SITES=	#http://user.it.uu.se/~jan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://user.it.uu.se/~jan/html2ps.html
COMMENT=	HTML to PostScript converter

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	ImageMagick>=5.3.9nb1:../../graphics/ImageMagick
DEPENDS+=	jpeg>=6b:../../graphics/jpeg
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	tex-tex-[0-9]*:../../print/tex-tex
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	weblint-[0-9]*:../../www/weblint

USE_TOOLS+=	gs:run perl:run

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/html2ps
	@cd ${WRKSRC} && PATH=${LOCALBASE}/bin:${PREFIX}/bin ./install ${DESTDIR}${PREFIX} ${PKGMANDIR} ${PREFIX}
	@${INSTALL_DATA} ${WRKSRC}/sample ${DESTDIR}${PREFIX}/share/html2ps/sample.rc

.include "../../mk/bsd.pkg.mk"
