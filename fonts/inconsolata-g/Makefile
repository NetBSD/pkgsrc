# $NetBSD: Makefile,v 1.1 2014/04/09 17:40:32 wiz Exp $

DISTNAME=	inconsolata-g_font
PKGNAME=	inconsolata-g-20090213
CATEGORIES=	fonts
MASTER_SITES=	http://www.fantascienza.net/leonardo/ar/inconsolatag/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://leonardo-m.livejournal.com/77079.html
COMMENT=	Modified Inconsolata TrueType font
#LICENSE=	ofl-v1.1

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIRS+=	lib/X11/fonts/TTF
FONTS_DIRS.ttf=		${PREFIX}/lib/X11/fonts/TTF
INSTALLATION_DIRS+=	lib/X11/fonts/OTF
FONTS_DIRS.otf=		${PREFIX}/lib/X11/fonts/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/Inconsolata-g.otf ${DESTDIR}${PREFIX}/lib/X11/fonts/OTF
	${INSTALL_DATA} ${WRKSRC}/Inconsolata-g.ttf ${DESTDIR}${PREFIX}/lib/X11/fonts/TTF

.include "../../mk/bsd.pkg.mk"
