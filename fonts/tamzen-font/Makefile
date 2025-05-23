# $NetBSD: Makefile,v 1.2 2025/05/23 19:38:04 vins Exp $

DISTNAME=	Tamzen-1.11.6
PKGNAME=	${DISTNAME:tl:S/tamzen-/tamzen-font-/1}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=sunaku/}
GITHUB_PROJECT=	tamzen-font
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/sunaku/tamzen-font
COMMENT=	Bitmapped programming font, based on Tamsyn
LICENSE=	isc # ish

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTS_DIRS.x11+=	share/fonts/X11/BDF
FONTS_DIRS.x11+=	share/fonts/X11/PCF

INSTALLATION_DIRS+=	share/fonts/X11/BDF
INSTALLATION_DIRS+=	share/fonts/X11/PCF

do-install:
	${INSTALL_DATA} ${WRKSRC}/bdf/* \
	    ${DESTDIR}${PREFIX}/share/fonts/X11/BDF
	${INSTALL_DATA} ${WRKSRC}/pcf/* \
	    ${DESTDIR}${PREFIX}/share/fonts/X11/PCF

.include "../../mk/bsd.pkg.mk"
