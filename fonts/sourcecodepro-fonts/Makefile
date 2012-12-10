# $NetBSD: Makefile,v 1.2 2012/12/10 09:17:24 ryoon Exp $
#

DISTNAME=	SourceCodePro_FontsOnly-1.013
PKGNAME=	${DISTNAME:S/SourceCodePro_FontsOnly/sourcecodepro-fonts/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sourcecodepro.adobe/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sourcecodepro.adobe/
COMMENT=	Set of monospaced OpenType fonts designed for coding environments
LICENSE=	open-font-license

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/sourcecodepro
INSTALLATION_DIRS=	share/fonts/sourcecodepro

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
