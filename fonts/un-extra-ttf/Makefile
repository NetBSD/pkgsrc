# $NetBSD: Makefile,v 1.4 2006/02/05 23:09:11 joerg Exp $

DISTNAME=	un-fonts-extra-${UN_EXTRA_VER}
PKGNAME=	un-extra-ttf-${UN_EXTRA_VER}
PKGREVISION=	2
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

FONTS_DIRS.ttf=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
