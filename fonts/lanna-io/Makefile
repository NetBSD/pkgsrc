# $NetBSD: Makefile,v 1.1 2017/11/03 19:40:54 scole Exp $
#

DISTNAME=	lanna-io-20170628

CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=lannainnovation/}
GITHUB_PROJECT=	thai-font-collection
GITHUB_TAG=	c4752b17ec622a3f3430a815847596bf8fb0d60f

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
