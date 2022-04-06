# $NetBSD: Makefile,v 1.3 2022/04/06 22:46:13 wiz Exp $

DISTNAME=		noto-emoji-2.034
PKGNAME=		${DISTNAME:S/emoji/emoji-ttf/}
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_GITHUB:=googlei18n/}
GITHUB_PROJECT=		noto-emoji
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.google.com/get/noto/
COMMENT=		Noto Emoji Font from Google
LICENSE=		apache-2.0

NO_BUILD=		yes
USE_LANGUAGES=		# none

FONTSDIR=		share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/fonts/*.ttf \
		${DESTDIR}/${PREFIX}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
