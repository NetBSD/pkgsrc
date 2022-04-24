# $NetBSD: Makefile,v 1.2 2022/04/24 00:45:07 tnn Exp $

DISTNAME=		Raleway-0.0.20161116
PKGNAME=		${DISTNAME:S/Raleway/raleway-ttf/}
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_GITHUB:=impallari/}
GITHUB_PROJECT=		Raleway
GITHUB_TAG=		fa27f47b087fc093c6ae11cfdeb3999ac602929a

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/impallari/Raleway
COMMENT=		Elegant sans-serif typeface family
LICENSE=		ofl-v1.1


EXTRACT_USING=		bsdtar
USE_TOOLS+=		bsdtar

NO_BUILD=		yes
USE_LANGUAGES=		# none

FONTSDIR=		share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/fonts/*/*.ttf ${WRKSRC}/fonts/*/*.otf ${DESTDIR}/${PREFIX}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
