# $NetBSD: Makefile,v 1.7 2017/01/14 11:47:11 ryoon Exp $

DISTNAME=	source-sans-pro-2.020R-ro-1.075R-it
PKGNAME=	sourcesans-fonts-2.020
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=adobe-fonts/}
GITHUB_PROJECT=	source-sans-pro
GITHUB_TAG=	2.020R-ro/1.075R-it
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adobe-fonts.github.io/source-sans-pro/
COMMENT=	Set of OpenType fonts designed for user interfaces from Adobe
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/${DISTNAME:S|/|-|}

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/sourcesans
INSTALLATION_DIRS=	share/fonts/sourcesans

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
