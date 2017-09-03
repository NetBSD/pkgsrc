# $NetBSD: Makefile,v 1.3 2017/09/03 08:53:08 wiz Exp $

DISTNAME=	inconsolata-g_font
PKGNAME=	inconsolata-g-20090213
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.fantascienza.net/leonardo/ar/inconsolatag/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://leonardo-m.livejournal.com/77079.html
COMMENT=	Modified Inconsolata TrueType font
#LICENSE=	ofl-v1.1

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIRS+=	share/fonts/X11/TTF
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS+=	share/fonts/X11/OTF
FONTS_DIRS.otf=		${PREFIX}/share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/Inconsolata-g.otf ${DESTDIR}${PREFIX}/share/fonts/X11/OTF
	${INSTALL_DATA} ${WRKSRC}/Inconsolata-g.ttf ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
