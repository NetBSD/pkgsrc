# $NetBSD: Makefile,v 1.5 2009/01/08 09:12:00 wiz Exp $
#

DISTNAME=		freefont-ttf-20090104
CATEGORIES=		fonts
MASTER_SITES=		http://savannah.nongnu.org/download/freefont/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.nongnu.org/freefont/
COMMENT=		Free UCS Outline Fonts: FreeMono, FreeSans, and FreeSerif

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${DISTNAME:S/-ttf//}
NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=		# empty
USE_TOOLS+=		pax
INSTALLATION_DIRS=	share/doc/freefont ${FONTS_DIRS.ttf}

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	${INSTALL_DATA} ${WRKSRC}/AUTHORS \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	${INSTALL_DATA} ${WRKSRC}/CREDITS \
		${DESTDIR}${PREFIX}/share/doc/freefont/
	cd ${WRKSRC} && \
		pax -rw Free*.ttf ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
