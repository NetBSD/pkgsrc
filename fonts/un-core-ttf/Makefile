# $NetBSD: Makefile,v 1.1.1.1 2004/08/16 06:13:59 minskim Exp $

DISTNAME=	un-fonts-core-${UN_CORE_VER}
PKGNAME=	un-core-ttf-${UN_CORE_VER}
CATEGORIES=	fonts korean
MASTER_SITES=	http://kldp.net/download.php/1425/

MAINTAINER=	yui@yui.pe.kr
HOMEPAGE=	http://kldp.net/projects/unfonts/
COMMENT=	Core set of Un Korean TrueType fonts

CONFLICTS+=	un-ttf-[0-9]*

UN_CORE_VER=	1.0

WRKSRC=		${WRKDIR}/un-fonts
USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTS_TTF_DIRS}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
