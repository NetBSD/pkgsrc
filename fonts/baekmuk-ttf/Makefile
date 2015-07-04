# $NetBSD: Makefile,v 1.19 2015/07/04 16:18:30 joerg Exp $

DISTNAME=	baekmuk-ttf-2.2
PKGREVISION=	3
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/download.php/1429/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://kldp.net/projects/baekmuk/
COMMENT=	Baekmuk family Korean TrueType fonts

NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF
DOCDIR=		${PREFIX}/share/doc/baekmuk-ttf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT* ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
