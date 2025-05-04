# $NetBSD: Makefile,v 1.1 2025/05/04 16:30:38 vins Exp $

DISTNAME=	${PKGNAME:S/cozette/CozetteFonts-v/:S/./-/g}
PKGNAME=	cozette-1.28.0
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=slavfox/}
GITHUB_RELEASE=	v.${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/slavfox/Cozette/
COMMENT=	Bitmap programming font optimized for coziness
LICENSE=	mit

WRKSRC=		${WRKDIR}/CozetteFonts

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS=		cozette cozettecrossedseven \
		cozette_hidpi cozettecrossedseven_hidpi
FONTS_TTF=	CozetteVector CozetteCrossedSevenVector \
		CozetteVectorBold CozetteCrossedSevenVectorBold

FONTS_DIRS.ttf=		share/fonts/X11/TTF
FONTS_DIRS.x11=		share/fonts/X11/misc

INSTALLATION_DIRS+=	${FONTS_DIRS.ttf} ${FONTS_DIRS.x11}

do-install:
	${RUN}for f in ${FONTS}; do			\
	${INSTALL_DATA} ${WRKSRC}/$${f}.otb		\
	  ${DESTDIR}${PREFIX}/share/fonts/X11/misc;	\
	done
	${RUN}for f in ${FONTS_TTF}; do 		\
	${INSTALL_DATA} ${WRKSRC}/$${f}.ttf		\
	  ${DESTDIR}${PREFIX}/share/fonts/X11/TTF;	\
	done

.include "../../mk/bsd.pkg.mk"
