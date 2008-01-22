# $NetBSD: Makefile,v 1.11 2008/01/22 17:09:55 tnn Exp $

DISTNAME=	kcfonts-1.05
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	kevlo@midassol.com
COMMENT=	Kuo Chauo Chinese Fonts collection

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/local
REQD_DIRS+=	${PREFIX}/lib/X11/fonts/local

USE_TOOLS+=	gzip ucs2any

.include "../../mk/bsd.pkg.mk"
