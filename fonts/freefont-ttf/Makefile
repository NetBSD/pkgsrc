# $NetBSD: Makefile,v 1.9 2012/10/03 18:28:23 asau Exp $
#

DISTNAME=		freefont-ttf-20120503
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_GNU:=freefont/}
EXTRACT_SUFX=		.zip

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.gnu.org/software/freefont/
COMMENT=		Free UCS Outline Fonts: FreeMono, FreeSans, and FreeSerif
LICENSE=		gnu-gpl-v3

WRKSRC=			${WRKDIR}/${DISTNAME:S/-ttf//}
NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=		# empty
USE_TOOLS+=		pax
INSTALLATION_DIRS=	share/doc/freefont lib/X11/fonts/TTF

FONTSDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=		${FONTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	${INSTALL_DATA} ${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	${INSTALL_DATA} ${WRKSRC}/CREDITS \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	cd ${WRKSRC} && \
		pax -rw Free*.ttf ${DESTDIR}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
