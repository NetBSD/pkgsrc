# $NetBSD: Makefile,v 1.22 2013/01/20 09:49:24 ryoon Exp $
#

DISTNAME=	VLGothic-20121230
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=vlgothic/57732/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yamajun@ofug.net
HOMEPAGE=	http://vlgothic.dicey.org/
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'
LICENSE=	modified-bsd AND mplusfont

USE_X11BASE=	YES
NO_BUILD=	YES
NO_CONFIGURE=	YES

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=${FONTDIR}
WRKSRC=		${WRKDIR}/${DISTNAME:C/-[^-]*$//}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA}	${WRKSRC}/VL-Gothic-Regular.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA}	${WRKSRC}/VL-PGothic-Regular.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
