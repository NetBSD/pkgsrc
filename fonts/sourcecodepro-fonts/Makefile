# $NetBSD: Makefile,v 1.5 2016/01/18 23:07:24 wiz Exp $

DISTNAME=	SourceCodePro_FontsOnly-1.017
PKGNAME=	${DISTNAME:S/SourceCodePro_FontsOnly/sourcecodepro-fonts/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sourcecodepro.adobe/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://adobe-fonts.github.io/source-code-pro/
COMMENT=	Set of monospaced OpenType fonts designed for coding environments
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/sourcecodepro
INSTALLATION_DIRS=	share/fonts/sourcecodepro

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
