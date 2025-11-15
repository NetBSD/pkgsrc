# $NetBSD: Makefile,v 1.2 2025/11/15 11:13:39 vins Exp $

DISTNAME=	${PKGBASE}
PKGNAME=	scientifica-2.3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=oppiliappan/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/oppiliappan/scientifica/
COMMENT=	Tall, condensed bitmap font
LICENSE=	ofl-v1.0

USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS=		scientifica scientificaBold \
		scientificaItalic

AUTO_MKDIRS=	yes

FONTS_DIRS.ttf=		share/fonts/X11/TTF
FONTS_DIRS.x11=		share/fonts/X11/misc

do-install:
	${RUN}for f in ${FONTS}; do			\
	${INSTALL_DATA} ${WRKSRC}/otb/$${f}.otb		\
	  ${DESTDIR}${PREFIX}/share/fonts/X11/misc;	\
	${INSTALL_DATA} ${WRKSRC}/ttf/$${f}.ttf		\
	  ${DESTDIR}${PREFIX}/share/fonts/X11/TTF;	\
	done

.include "../../mk/bsd.pkg.mk"
