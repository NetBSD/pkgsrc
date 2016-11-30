# $NetBSD: Makefile,v 1.4 2016/11/30 14:24:47 mef Exp $

DISTNAME=	FiraCode_1.204
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=tonsky/}
GITHUB_RELEASE=	${DISTNAME:S/FiraCode_//}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tonsky/FiraCode/
COMMENT=	Monospaced font with programming ligatures
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/OTF ${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	share/fonts/X11/OTF share/fonts/X11/TTF
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/otf/*.otf  ${DESTDIR}${PREFIX}/share/fonts/X11/OTF
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf  ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
