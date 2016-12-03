# $NetBSD: Makefile,v 1.7 2016/12/03 02:26:54 khorben Exp $

DISTNAME=	sourcecodepro-fonts-1.050
CATEGORIES=	fonts
MASTER_SITES=	https://github.com/adobe-fonts/source-code-pro/archive/2.030R-ro/
DISTFILES=	1.050R-it.tar.gz
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adobe-fonts.github.io/source-code-pro/
COMMENT=	Set of monospaced OpenType fonts designed for coding environments
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/source-code-pro-2.030R-ro-1.050R-it

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/sourcecodepro
INSTALLATION_DIRS=	share/fonts/sourcecodepro

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
