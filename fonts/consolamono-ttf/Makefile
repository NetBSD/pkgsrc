# $NetBSD: Makefile,v 1.3 2014/06/01 16:35:32 wiz Exp $
#

VER=		20121116
DISTNAME=	consolamono
PKGNAME=	${DISTNAME}-ttf-${VER}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/consolamono/7c6fa601cdc82be054fb2b8fd7e3c8cc/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://openfontlibrary.org/en/font/consolamono
COMMENT=	Monospace font created for programming
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/Consola\ Mono
USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/fonts/X11/TTF
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/ConsolaMono-Bold.ttf \
		${DESTDIR}${PREFIX}/share/fonts/X11/TTF
	${INSTALL_DATA} ${WRKSRC}/ConsolaMono.ttf \
		${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
