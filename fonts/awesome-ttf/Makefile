# $NetBSD: Makefile,v 1.6 2021/11/05 20:45:06 rhialto Exp $
#

VERSION=	5.15.0
DISTNAME=	fontawesome-free-${VERSION}-web
PKGNAME=	awesome-ttf-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	https://use.fontawesome.com/releases/v${VERSION}/
EXTRACT_SUFX=	.zip

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://fontawesome.com/
COMMENT=	The iconic font and CSS toolkit
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/webfonts/*.ttf ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
