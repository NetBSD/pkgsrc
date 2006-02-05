# $NetBSD: Makefile,v 1.15 2006/02/05 23:09:08 joerg Exp $

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
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${FONTS_DIRS.ttf}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT* ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
