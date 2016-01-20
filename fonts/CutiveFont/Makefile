# $NetBSD: Makefile,v 1.1 2016/01/20 11:40:13 wiz Exp $

DISTNAME=	CutiveFont-0.0.20121026
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=vernnobile/}
GITHUB_TAG=	afb4dad38280ad7a63764b2b4a5795224cbcfbe2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.google.com/fonts/specimen/Cutive%20Mono
COMMENT=	Classic typewriter typeface
LICENSE=	ofl-v1.1

USE_TOOLS+=	bsdtar
EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none
NO_BUILD=	yes
#WRKSRC=		${WRKDIR}
FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/OTF
INSTALLATION_DIRS=	share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*/*/*.otf  ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*/*/*/*.otf  ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
