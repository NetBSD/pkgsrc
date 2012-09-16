# $NetBSD: Makefile,v 1.18 2012/09/16 14:36:07 ryoon Exp $
#

DISTNAME=	VLGothic-20120905
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=vlgothic/56782/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yamajun@ofug.net
HOMEPAGE=	http://vlgothic.dicey.org/
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'
LICENSE=	modified-bsd AND mplusfont

USE_X11BASE=	YES
NO_BUILD=	YES
NO_CONFIGURE=	YES

PKG_DESTDIR_SUPPORT=	user-destdir

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=${FONTDIR}
WRKSRC=		${WRKDIR}/${DISTNAME:C/-[^-]*$//}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA}	${WRKSRC}/VL-Gothic-Regular.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA}	${WRKSRC}/VL-PGothic-Regular.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
