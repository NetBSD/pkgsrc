# $NetBSD: Makefile,v 1.5 2013/04/08 01:42:41 rodent Exp $
#

DISTNAME=	SourceSansPro_FontsOnly-1.038
PKGNAME=	${DISTNAME:S/SourceSansPro_FontsOnly/sourcesans-fonts/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sourcesans.adobe/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sourcesans.adobe/
COMMENT=	Set of OpenType fonts designed for user interfaces from Adobe
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/sourcesans
INSTALLATION_DIRS=	share/fonts/sourcesans

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
