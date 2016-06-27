# $NetBSD: Makefile,v 1.6 2016/06/27 15:41:29 wiz Exp $

DISTNAME=	SourceSansPro_FontsOnly-1.038
PKGNAME=	${DISTNAME:S/SourceSansPro_FontsOnly/sourcesans-fonts/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sourcesans.adobe/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adobe-fonts.github.io/source-sans-pro/
COMMENT=	Set of OpenType fonts designed for user interfaces from Adobe
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/sourcesans
INSTALLATION_DIRS=	share/fonts/sourcesans

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
