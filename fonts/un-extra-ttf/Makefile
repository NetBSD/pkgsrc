# $NetBSD: Makefile,v 1.2 2004/12/28 14:38:03 wiz Exp $

DISTNAME=	un-fonts-extra-${UN_EXTRA_VER}
PKGNAME=	un-extra-ttf-${UN_EXTRA_VER}
PKGREVISION=	1
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/download.php/1435/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://kldp.net/projects/unfonts/
COMMENT=	Extra set of Un Korean TrueType fonts

CONFLICTS+=	un-ttf-[0-9]*

UN_EXTRA_VER=	1.0.1

WRKSRC=		${WRKDIR}/un-fonts
USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTS_TTF_DIRS}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
