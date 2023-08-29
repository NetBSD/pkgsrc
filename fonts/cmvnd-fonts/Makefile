# $NetBSD: Makefile,v 1.1 2023/08/29 06:27:08 vins Exp $

DISTNAME=	fonts
PKGVER=		20211030
PKGNAME=	${DISTNAME:S/^/cmvnd-/}-${PKGVER}
CATEGORIES=	fonts
DIST_SUBDIR=	${PKGNAME_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=cmvnd/}
GITHUB_PROJECT=	fonts
GITHUB_TAG=	0480a776c8a0b9c05cba4037084f74c5f8c042f6


MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/cmvnd/fonts/
COMMENT=	Tiny bitmap fonts
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
USE_TOOLS+=	bdftopcf gzip

NO_CONFIGURE=	yes

FONTS=		antidote berry berryBold \
		lemon limey uushi

FONTDIR=		share/fonts/X11/cmvnd
REQD_DIRS=		${FONTDIR}
FONTS_DIRS.x11=		${FONTDIR}
INSTALLATION_DIRS=	${FONTDIR}
MESSAGE_SUBST+=		FONTDIR=${FONTDIR:Q}

WRKSRC=	${WRKDIR}/fonts-${GITHUB_TAG}

post-extract:
	${RUN}cd ${WRKSRC} &&				\
	for FONT in spectrum-fonts/*.bdf; do		\
	  ${MV} $${FONT} .;				\
	done

do-build:
	${RUN}cd ${WRKSRC} &&				\
	for FONT in ${FONTS}; do			\
	  ${ECHO_N} "Compiling font $${FONT} ... ";	\
	  bdftopcf $${FONT}.bdf |			\
		${GZIP_CMD} -c >$${FONT}.pcf.gz;	\
	  ${ECHO} "done";				\
	done

do-install:
	${RUN}for FONT in ${FONTS}; do			\
	  ${ECHO_N} "Installing font $${FONT} ... ";	\
	  ${INSTALL_DATA} ${WRKSRC}/$${FONT}.pcf.gz	\
		${DESTDIR}${PREFIX}/${FONTDIR};		\
	  ${ECHO} "done";				\
	done

.include "../../mk/bsd.pkg.mk"
