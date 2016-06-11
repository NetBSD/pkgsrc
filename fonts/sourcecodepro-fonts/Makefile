# $NetBSD: Makefile,v 1.6 2016/06/11 18:55:07 wiz Exp $

DISTNAME=	sourcecodepro-fonts-1.030
CATEGORIES=	fonts
MASTER_SITES=	https://github.com/adobe-fonts/source-code-pro/archive/2.010R-ro/
DISTFILES=	1.030R-it.tar.gz
DIST_SUBDIR=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adobe-fonts.github.io/source-code-pro/
COMMENT=	Set of monospaced OpenType fonts designed for coding environments
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/source-code-pro-2.010R-ro-1.030R-it

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/sourcecodepro
INSTALLATION_DIRS=	share/fonts/sourcecodepro

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
