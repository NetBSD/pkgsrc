# $NetBSD: Makefile,v 1.1.1.1 2003/03/22 17:33:29 jmmv Exp $
#

DISTNAME=	latex-ttf-fonts-0.1
CATEGORIES=	fonts
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/contrib/

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.lyx.org/
COMMENT=	TTF versions of some LaTeX fonts

NO_CONFIGURE=	yes
NO_BUILD=	yes

USE_X11BASE=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts
FONTS_TTF_DIRS=	${FONTDIR}/latex-ttf-fonts

post-extract:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	${SED} -e "s,/usr/share/fonts,${FONTDIR},g" \
		${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/latex-ttf-fonts
	${INSTALL_DATA} ${WRKSRC}/BaKoMa-CM.Fonts \
		 ${LOCALBASE}/share/doc/latex-ttf-fonts

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
