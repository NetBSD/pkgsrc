# $NetBSD: Makefile,v 1.2 2020/04/14 21:38:32 scole Exp $
#

GITHUB_PROJECT=	thai-font-collection
GITHUB_TAG=	ee660780065cc2bfff502e426d609b482464bf5c
DISTNAME=	lanna-io-20200318
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=lannainnovation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lannainnovation/thai-font-collection/
COMMENT=	Lanna Innovation collection of Thai fonts
LICENSE=	apache-2.0 AND ofl-v1.1 AND gnu-gpl-v2 AND \
		dip-sipa-license AND tepc-license

USE_TOOLS+=	bsdtar
EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

OTFPATH=	share/fonts/X11/OTF
TTFPATH=	share/fonts/X11/TTF

FONTS_DIRS.ttf=		${PREFIX}/${OTFPATH} ${PREFIX}/${TTFPATH}
INSTALLATION_DIRS+=	${OTFPATH} ${TTFPATH} share/lanna-io

do-install:
	${INSTALL_DATA} ${WRKSRC}/*/*/*.otf  ${DESTDIR}${PREFIX}/${OTFPATH}
	${INSTALL_DATA} ${WRKSRC}/*/*/*.ttf  ${DESTDIR}${PREFIX}/${TTFPATH}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/lanna-io

.include "../../mk/bsd.pkg.mk"
