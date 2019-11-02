# $NetBSD: Makefile,v 1.9 2019/11/02 22:24:43 rillig Exp $

DISTNAME=	sourcecodepro-fonts-1.050
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	https://github.com/adobe-fonts/source-code-pro/archive/2.030R-ro/
DISTFILES=	1.050R-it.tar.gz
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adobe-fonts.github.io/source-code-pro/
COMMENT=	Set of monospaced OpenType fonts designed for coding environments
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/source-code-pro-2.030R-ro-1.050R-it

USE_LANGUAGES=		# none
NO_BUILD=		yes
FONTSDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTSDIR}
INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
