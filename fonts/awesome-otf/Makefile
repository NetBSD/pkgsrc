# $NetBSD: Makefile,v 1.1 2018/12/10 20:19:07 tm Exp $
#

VERSION=	5.5.0
DISTNAME=	fontawesome-free-${VERSION}-desktop
PKGNAME=	awesome-otf-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	https://use.fontawesome.com/releases/v${VERSION}/
EXTRACT_SUFX=	.zip

MAINTAINER=	tm@core.io
HOMEPAGE=	https://fontawesome.com/
COMMENT=	The iconic font and CSS toolkit
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	share/fonts/X11/OTF

INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/otfs/*.otf ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
