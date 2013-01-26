# $NetBSD: Makefile,v 1.1 2013/01/26 11:15:29 ryoon Exp $
#

VER=		20121116
DISTNAME=	consolamono
PKGNAME=	${DISTNAME}-ttf-${VER}
CATEGORIES=	fonts
MASTER_SITES=	http://openfontlibrary.org/assets/downloads/consolamono/7c6fa601cdc82be054fb2b8fd7e3c8cc/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://openfontlibrary.org/en/font/consolamono
COMMENT=	Monospace font created for programming
LICENSE=	open-font-license

WRKSRC=		${WRKDIR}/Consola\ Mono
USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/X11/fonts/TTF
FONTS_DIRS.ttf=		${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/ConsolaMono-Bold.ttf \
		${DESTDIR}${PREFIX}/lib/X11/fonts/TTF
	${INSTALL_DATA} ${WRKSRC}/ConsolaMono.ttf \
		${DESTDIR}${PREFIX}/lib/X11/fonts/TTF

.include "../../mk/bsd.pkg.mk"
