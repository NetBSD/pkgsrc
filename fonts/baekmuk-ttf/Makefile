# $NetBSD: Makefile,v 1.12 2004/08/13 03:22:23 minskim Exp $

DISTNAME=	baekmuk-ttf-2.2
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/download.php/1429/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://kldp.net/projects/baekmuk/
COMMENT=	Baekmuk family Korean TrueType fonts

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/baekmuk-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${WRKSRC}/ttf/*.ttf ${FONTS_TTF_DIRS}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT* ${DOCDIR}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
