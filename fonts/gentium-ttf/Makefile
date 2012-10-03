# $NetBSD: Makefile,v 1.4 2012/10/03 18:28:23 asau Exp $
#

DISTNAME=	Gentium_102_W
PKGNAME=	gentium-ttf-1.02
CATEGORIES=	fonts
EXTRACT_SUFX=	.zip

WRKSRC=		${WRKDIR}/Gentium102

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://scripts.sil.org/
COMMENT=	Free TrueType fonts from Bitstream, useful for web viewing

MASTER_SITES=	${MASTER_SITE_LOCAL}

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf+=	${PREFIX}/lib/X11/fonts/TTF

INSTALLATION_DIRS=	lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/GenAI102.TTF ${DESTDIR}${FONTS_DIRS.ttf}/genai102.ttf
	${INSTALL_DATA} ${WRKSRC}/GenAR102.TTF ${DESTDIR}${FONTS_DIRS.ttf}/genar102.ttf
	${INSTALL_DATA} ${WRKSRC}/GenI102.TTF ${DESTDIR}${FONTS_DIRS.ttf}/geni102.ttf
	${INSTALL_DATA} ${WRKSRC}/GenR102.TTF ${DESTDIR}${FONTS_DIRS.ttf}/genr102.ttf

.include "../../mk/bsd.pkg.mk"
