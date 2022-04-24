# $NetBSD: Makefile,v 1.10 2022/04/24 15:30:43 tnn Exp $

DISTNAME=	OTF-source-sans-3.046R
PKGNAME=	${DISTNAME:S/OTF-source-sans/sourcesans-fonts/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=adobe-fonts/}
GITHUB_PROJECT=	source-sans
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/adobe-fonts/source-sans
COMMENT=	Set of OpenType fonts designed for user interfaces from Adobe
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}

USE_LANGUAGES=		# none
NO_BUILD=		yes
FONTSDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTSDIR}
INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/OTF/*.otf  ${DESTDIR}${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
