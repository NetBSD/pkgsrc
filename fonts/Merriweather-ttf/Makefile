# $NetBSD: Makefile,v 1.1 2016/11/15 16:05:42 wiz Exp $

DISTNAME=	Merriweather-1.584
PKGNAME=	${DISTNAME:S/her/her-ttf/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=EbenSorkin/}
GITHUB_PROJECT=	Merriweather
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ebensorkin.wordpress.com/
COMMENT=	Eben Sorkin's Merriweather font
LICENSE=	ofl-v1.1

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

INSTALLATION_DIRS+=	share/fonts/X11/OTF
INSTALLATION_DIRS+=	share/fonts/X11/TTF
FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/OTF
FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf ${DESTDIR}${PREFIX}/share/fonts/X11/OTF
	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
