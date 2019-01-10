# $NetBSD: Makefile,v 1.1 2019/01/10 14:55:58 tnn Exp $

DISTNAME=	spleen-1.0.3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	1.0.3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/spleen/
COMMENT=	Monospaced bitmap fonts
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	bdftopcf gzip

FONTDIR=		${PREFIX}/share/fonts/X11/spleen
FONTS_DIRS.x11+=	${FONTDIR}
INSTALLATION_DIRS=	${FONTDIR}

do-build:
.for sz in 5x8 8x16 12x24 16x32 32x64
	${TOOLS_PATH.bdftopcf} -t -o ${WRKSRC}/spleen-${sz}.pcf ${WRKSRC}/spleen-${sz}.bdf
.endfor
	${GZIP_CMD} ${WRKSRC}/*.pcf

do-install:
	${INSTALL_DATA}	${WRKSRC}/fonts.alias-spleen	\
	  ${DESTDIR}${FONTDIR}/fonts.alias
	${INSTALL_DATA}	${WRKSRC}/*.pcf.gz ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
