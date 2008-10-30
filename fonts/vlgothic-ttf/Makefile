# $NetBSD: Makefile,v 1.4 2008/10/30 12:43:19 obache Exp $
#

DISTNAME=	VLGothic-20081029
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=vlgothic/33535/} \
		http://vinelinux.org/~daisuke/vlgothic/ \
		http://dicey.org/vlgothic/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	yamajun@ofug.net
HOMEPAGE=	http://dicey.org/vlgothic/
COMMENT=	Free Japanese TrueType fonts named 'VLGothic'

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
