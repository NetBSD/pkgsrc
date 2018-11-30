# $NetBSD: Makefile,v 1.1 2018/11/30 15:46:48 nia Exp $

PKGNAME=	twemoji-color-font-ttf-11.2.0
DISTNAME=	TwitterColorEmoji-SVGinOT-Linux-${PKGVERSION_NOREV}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=eosrei/}
GITHUB_PROJECT=	twemoji-color-font
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/eosrei/twemoji-color-font
COMMENT=	Twitter color emoji SVGinOT font
LICENSE=	cc-by-v4.0 AND mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/TwitterColorEmoji-SVGinOT.ttf \
	    ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
