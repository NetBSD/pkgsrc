# $NetBSD: Makefile,v 1.28 2015/07/04 16:18:34 joerg Exp $
#

DISTNAME=	VLGothic-20141206
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_OSDN:=vlgothic/62375/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yamajun@ofug.net
HOMEPAGE=	http://vlgothic.dicey.org/
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'
LICENSE=	modified-bsd AND mplusfont

NO_BUILD=	YES
NO_CONFIGURE=	YES

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf+=${FONTDIR}
WRKSRC=		${WRKDIR}/${DISTNAME:C/-[^-]*$//}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA}	${WRKSRC}/VL-Gothic-Regular.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA}	${WRKSRC}/VL-PGothic-Regular.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
