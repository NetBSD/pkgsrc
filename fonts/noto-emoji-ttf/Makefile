# $NetBSD: Makefile,v 1.1 2016/07/09 06:22:47 ryoon Exp $

DISTNAME=		NotoEmoji-Regular
PKGNAME=		noto-emoji-1.05
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_GITHUB:=googlei18n/}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.google.com/get/noto/
COMMENT=		Noto Emoji Font from Google
LICENSE=		apache-2.0

GITHUB_PROJECT=		noto-emoji
GITHUB_TAG=		2f1ffdd6fbbd05d6f382138a3d3adcd89c5ce800

DIST_SUBDIR=		${PKGNAME_NOREV}

NO_BUILD=		yes
USE_LANGUAGES=		# none

FONTSDIR=		share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/fonts/NotoEmoji-Regular.ttf \
		${DESTDIR}/${PREFIX}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
