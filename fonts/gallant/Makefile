# $NetBSD: Makefile,v 1.1 2025/11/15 10:35:14 vins Exp $

DISTNAME=	gallant-0.1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=NanoBillion/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/NanoBillion/gallant/
COMMENT=	Sun Gallant font with >4500 Unicode glyphs
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	share/fonts/X11/TTF
FONTS_DIRS.x11=	share/fonts/X11/misc

AUTO_MKDIRS=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.pcf.gz	\
	  ${DESTDIR}${PREFIX}/share/fonts/X11/misc
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.ttf	\
	  ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
