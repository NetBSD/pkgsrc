# $NetBSD: Makefile,v 1.17 2012/10/03 18:28:17 asau Exp $

DISTNAME=	baekmuk-ttf-2.2
PKGREVISION=	2
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/download.php/1429/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://kldp.net/projects/baekmuk/
COMMENT=	Baekmuk family Korean TrueType fonts

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/baekmuk-ttf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
