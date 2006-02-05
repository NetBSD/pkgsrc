# $NetBSD: Makefile,v 1.4 2006/02/05 23:09:11 joerg Exp $

DISTNAME=	un-fonts-core-${UN_CORE_VER}
PKGNAME=	un-core-ttf-${UN_CORE_VER}
PKGREVISION=	2
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

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
