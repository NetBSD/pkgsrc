# $NetBSD: Makefile,v 1.2 2012/10/01 11:16:22 ryoon Exp $
#

DISTNAME=	SourceSansPro_FontsOnly-1.036
PKGNAME=	${DISTNAME:S/SourceSansPro_FontsOnly/sourcesans-fonts/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sourcesans.adobe/}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sourcesans.adobe/
COMMENT=	Set of OpenType fonts designed for user interfaces from Adobe
LICENSE=	open-font-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
NO_BUILD=	yes
FONTS_DIR=	${PREFIX}/share/fonts/sourcesans
INSTALLATION_DIRS=	share/fonts/sourcesans

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf  ${DESTDIR}${FONTS_DIR}

.include "../../mk/bsd.pkg.mk"
