# $NetBSD: Makefile,v 1.3 2019/11/02 22:24:38 rillig Exp $

DISTNAME=		Merriweather-2.002
PKGNAME=		${DISTNAME:S/her/her-ttf/}
CATEGORIES=		fonts
# does not provide distfile for versions > 1.584; 2.002 is from fontsquirrel
#MASTER_SITES=		${MASTER_SITE_GITHUB:=EbenSorkin/}
#GITHUB_PROJECT=	Merriweather
#GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=		.zip

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
	${INSTALL_DATA} ${WRKSRC}/*.otf ${DESTDIR}${PREFIX}/share/fonts/X11/OTF
#	${INSTALL_DATA} ${WRKSRC}/TTF/*.ttf ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
