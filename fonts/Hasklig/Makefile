# $NetBSD: Makefile,v 1.1 2016/01/20 11:39:41 wiz Exp $

DISTNAME=	Hasklig-0.9
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=i-tu/}
GITHUB_RELEASE=	${DISTNAME:S/Hasklig-//}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/i-tu/Hasklig/
COMMENT=	Code font with monospaced ligatures
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
WRKSRC=		${WRKDIR}
FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/OTF
INSTALLATION_DIRS=	share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf  ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
