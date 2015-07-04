# $NetBSD: Makefile,v 1.15 2015/07/04 16:18:32 joerg Exp $

DISTNAME=	kcfonts-1.05
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	kevlo@midassol.com
COMMENT=	Kuo Chauo Chinese Fonts collection

WRKSRC=		${WRKDIR}
FONTS_DIRS.x11=	${PREFIX}/share/fonts/X11/local
REQD_DIRS+=	${PREFIX}/share/fonts/X11/local

USE_TOOLS+=	gzip ucs2any

.include "../../mk/bsd.pkg.mk"
