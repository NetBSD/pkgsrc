# $NetBSD: Makefile,v 1.9 2022/06/28 11:33:55 wiz Exp $

DISTNAME=	unscii-2.1-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://viznut.fi/unscii/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	http://viznut.fi/unscii/
COMMENT=	Bitmapped character-art friendly Unicode fonts
LICENSE=	gnu-gpl-v2

UNLIMIT_RESOURCES=	datasize virtualsize

USE_TOOLS+=	perl:build
BUILD_DEPENDS+=	bdftopcf-[0-9]*:../../fonts/bdftopcf
BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge
BUILD_DEPENDS+=	p5-Text-CharWidth-[0-9]*:../../textproc/p5-Text-CharWidth

REPLACE_PERL+=	*.pl

INSTALLATION_DIRS=	share/fonts/X11/TTF share/fonts/X11/OTF
INSTALLATION_DIRS+=	share/fonts/X11/svg share/fonts/X11/web

FONTDIR=	${PREFIX}/share/fonts/X11
FONTS_DIR.ttf=	${FONTDIR}/TTF
FONTS_DIR.otf=	${FONTDIR}/OTF
FONTS_DIR.svg=	${FONTDIR}/svg
FONTS_DIR.web=	${FONTDIR}/web

do-install:
	cd ${WRKSRC} && for i in *.hex; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTDIR} ; done
	cd ${WRKSRC} && for i in *.pcf; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTDIR} ; done
	cd ${WRKSRC} && for i in *.ttf; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIR.ttf} ; done
	cd ${WRKSRC} && for i in *.otf; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIR.otf} ; done
	cd ${WRKSRC} && for i in *.svg; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIR.svg} ; done
	cd ${WRKSRC} && for i in *.woff; do \
		${INSTALL_DATA} $$i ${DESTDIR}${FONTS_DIR.web} ; done

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
