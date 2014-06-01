# $NetBSD: Makefile,v 1.14 2014/06/01 16:35:35 wiz Exp $

DISTNAME=	kcfonts-1.05
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	kevlo@midassol.com
COMMENT=	Kuo Chauo Chinese Fonts collection

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
FONTS_DIRS.x11=	${PREFIX}/share/fonts/X11/local
REQD_DIRS+=	${PREFIX}/share/fonts/X11/local

USE_TOOLS+=	gzip ucs2any

.include "../../mk/bsd.pkg.mk"
