# $NetBSD: Makefile,v 1.6 2014/06/01 16:35:34 wiz Exp $
#

DISTNAME=	Gentium_102_W
PKGNAME=	gentium-ttf-1.02
PKGREVISION=	1
CATEGORIES=	fonts
EXTRACT_SUFX=	.zip

WRKSRC=		${WRKDIR}/Gentium102

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://scripts.sil.org/FontDownloadsGentium
COMMENT=	Free TrueType fonts from Bitstream, useful for web viewing
LICENSE=	ofl-v1.1

MASTER_SITES=	${MASTER_SITE_LOCAL}

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/GenAI102.TTF ${DESTDIR}${FONTS_DIRS.ttf}/genai102.ttf
	${INSTALL_DATA} ${WRKSRC}/GenAR102.TTF ${DESTDIR}${FONTS_DIRS.ttf}/genar102.ttf
	${INSTALL_DATA} ${WRKSRC}/GenI102.TTF ${DESTDIR}${FONTS_DIRS.ttf}/geni102.ttf
	${INSTALL_DATA} ${WRKSRC}/GenR102.TTF ${DESTDIR}${FONTS_DIRS.ttf}/genr102.ttf

.include "../../mk/bsd.pkg.mk"
