# $NetBSD: Makefile,v 1.4 2021/11/05 21:00:35 rhialto Exp $
#

VER=		20130127
DISTNAME=	consolamono
PKGNAME=	${DISTNAME}-ttf-${VER}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	https://fontlibrary.org/assets/downloads/consolamono/61cc2afcc4eca96efe7c6ebf178d39df/
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
