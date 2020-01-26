# $NetBSD: Makefile,v 1.5 2020/01/26 17:31:12 rillig Exp $

DISTNAME=	Noto-hinted
PKGNAME=	noto-ttf-20170410
CATEGORIES=	fonts
MASTER_SITES=	https://noto-website.storage.googleapis.com/pkgs/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.google.com/get/noto/
COMMENT=	Noto fonts for all languages
LICENSE=	ofl-v1.1

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		NotoSansCJKjp-hinted${EXTRACT_SUFX} \
		NotoSansCJKkr-hinted${EXTRACT_SUFX} \
		NotoSansCJKsc-hinted${EXTRACT_SUFX} \
		NotoSansCJKtc-hinted${EXTRACT_SUFX} \
		NotoSerifCJKjp-hinted${EXTRACT_SUFX} \
		NotoSerifCJKkr-hinted${EXTRACT_SUFX} \
		NotoSerifCJKsc-hinted${EXTRACT_SUFX} \
		NotoSerifCJKtc-hinted${EXTRACT_SUFX}

USE_LANGUAGES=	# none
NO_BUILD=	yes
DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
