# $NetBSD: Makefile,v 1.8 2006/02/17 19:34:33 wiz Exp $

DISTNAME=	kcfonts-1.05
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/distfiles/

MAINTAINER=	kevlo@midassol.com
COMMENT=	Kuo Chauo Chinese Fonts collection

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/local
REQD_DIRS+=	${PREFIX}/lib/X11/fonts/local

.include "../../mk/bsd.pkg.mk"
