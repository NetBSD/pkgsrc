# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:28 asau Exp $
#

DISTNAME=	Mothanna-0.02
PKGNAME=	${DISTNAME:S/M/m/:S/-0.02//}-ttf-0.02
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.arabeyes.org/project.php?proj=Khotot
COMMENT=	Mothanna is a sans-serif like Arabic OpenType font

USE_LANGUAGES=	# none

NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=	# none

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS+=	share/doc/mothanna-ttf ${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README 		 \
		 ${DESTDIR}${PREFIX}/share/doc/mothanna-ttf
	${INSTALL_DATA} ${WRKSRC}/Mothanna.ttf		 \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Mothanna-Bold.ttf	  \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Mothanna-Oblique.ttf      \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Mothanna-Bold-Oblique.ttf \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
