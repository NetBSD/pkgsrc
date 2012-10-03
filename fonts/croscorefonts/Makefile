# $NetBSD: Makefile,v 1.3 2012/10/03 18:28:17 asau Exp $
#

DISTNAME=	croscorefonts-1.21.0
CATEGORIES=	fonts
MASTER_SITES=	http://gsdview.appspot.com/chromeos-localmirror/distfiles/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://fedoraproject.org/wiki/Google_Croscore_fonts
COMMENT=	Google Croscore fonts
LICENSE=	open-font-license

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	Arimo-Bold.ttf \
		Arimo-BoldItalic.ttf \
		Arimo-Italic.ttf \
		Arimo-Regular.ttf \
		Cousine-Bold.ttf \
		Cousine-BoldItalic.ttf \
		Cousine-Italic.ttf \
		Cousine-Regular.ttf \
		SymbolNeu.ttf \
		Tinos-Bold.ttf \
		Tinos-BoldItalic.ttf \
		Tinos-Italic.ttf \
		Tinos-Regular.ttf

INSTALL_DOCS=	LICENSE

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
