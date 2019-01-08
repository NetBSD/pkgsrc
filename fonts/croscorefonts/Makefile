# $NetBSD: Makefile,v 1.8 2019/01/08 19:25:57 bsiegert Exp $
#

DISTNAME=	croscorefonts-1.31.0
CATEGORIES=	fonts
MASTER_SITES=	http://gsdview.appspot.com/chromeos-localmirror/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://fedoraproject.org/wiki/Google_Croscore_fonts
COMMENT=	Google Croscore fonts
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	Arimo-Bold.ttf \
		Arimo-BoldItalic.ttf \
		Arimo-Italic.ttf \
		Arimo-Regular.ttf \
		Cousine-Bold.ttf \
		Cousine-BoldItalic.ttf \
		Cousine-Italic.ttf \
		Cousine-Regular.ttf \
		Tinos-Bold.ttf \
		Tinos-BoldItalic.ttf \
		Tinos-Italic.ttf \
		Tinos-Regular.ttf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
