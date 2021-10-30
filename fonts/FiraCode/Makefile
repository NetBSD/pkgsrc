# $NetBSD: Makefile,v 1.7 2021/10/30 14:50:50 rhialto Exp $

DISTNAME=	FiraCode-5.2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=tonsky/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tonsky/FiraCode/
COMMENT=	Monospaced font with programming ligatures
LICENSE=	ofl-v1.1

USE_LANGUAGES=		# none
NO_BUILD=		yes
FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/distr/ttf/*.ttf  ${DESTDIR}${PREFIX}/share/fonts/X11/TTF
	${INSTALL_DATA} ${WRKSRC}/distr/variable_ttf/*.ttf  ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
