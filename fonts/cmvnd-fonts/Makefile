# $NetBSD: Makefile,v 1.3 2025/05/05 18:37:14 vins Exp $

DISTNAME=	fonts-20211030
PKGNAME=	${DISTNAME:S/^/cmvnd-/}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=cmvnd/}
GITHUB_PROJECT=	fonts
GITHUB_TAG=	0480a776c8a0b9c05cba4037084f74c5f8c042f6

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cmvnd/fonts/
COMMENT=	Tiny bitmap fonts
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
USE_TOOLS+=	bdftopcf gzip

NO_CONFIGURE=	yes

FONTS=		antidote berry berryBold \
		lemon limey uushi

FONTDIR=		share/fonts/X11/PCF
REQD_DIRS=		${FONTDIR}
FONTS_DIRS.x11=		${FONTDIR}

INSTALLATION_DIRS=	${FONTDIR}

WRKSRC=	${WRKDIR}/fonts-${GITHUB_TAG}

post-extract:
	${RUN}cd ${WRKSRC} &&				\
	for FONT in spectrum-fonts/*.bdf; do		\
	  ${MV} $${FONT} .;				\
	done

do-build:
	${RUN}cd ${WRKSRC} &&				\
	for FONT in ${FONTS}; do			\
	  bdftopcf $${FONT}.bdf |			\
		${GZIP_CMD} -c >$${FONT}.pcf.gz;	\
	done

do-install:
	${RUN}for FONT in ${FONTS}; do			\
	  ${INSTALL_DATA} ${WRKSRC}/$${FONT}.pcf.gz	\
		${DESTDIR}${PREFIX}/${FONTDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
