# $NetBSD: Makefile,v 1.10 2007/11/25 11:55:57 wiz Exp $

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

.include "../../mk/bsd.pkg.mk"
