# $NetBSD: Makefile,v 1.22 2023/11/17 17:40:37 fcambus Exp $

DISTNAME=	spleen-2.0.1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcambus/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fcambus/spleen/
COMMENT=	Monospaced bitmap fonts
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	gzip

FONTDIR=		${PREFIX}/share/fonts/X11/spleen
CONSOLEFONTSDIR=	${PREFIX}/share/fonts/consolefonts
FONTS_DIRS.x11+=	${FONTDIR}
INSTALLATION_DIRS=	${FONTDIR} ${CONSOLEFONTSDIR}

do-build:
	${GZIP_CMD} ${WRKSRC}/*.pcf
	${GZIP_CMD} ${WRKSRC}/*.psfu

do-install:
	${INSTALL_DATA}	${WRKSRC}/fonts.alias-spleen	\
	  ${DESTDIR}${FONTDIR}/fonts.alias
	${INSTALL_DATA}	${WRKSRC}/*.pcf.gz ${DESTDIR}${FONTDIR}
	${INSTALL_DATA}	${WRKSRC}/*.otf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA}	${WRKSRC}/*.psfu.gz ${DESTDIR}${CONSOLEFONTSDIR}

.include "../../mk/bsd.pkg.mk"
