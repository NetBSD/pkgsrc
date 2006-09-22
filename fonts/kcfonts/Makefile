# $NetBSD: Makefile,v 1.9 2006/09/22 21:53:57 joerg Exp $

DISTNAME=	kcfonts-1.05
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/distfiles/

MAINTAINER=	kevlo@midassol.com
COMMENT=	Kuo Chauo Chinese Fonts collection

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/local
REQD_DIRS+=	${PREFIX}/lib/X11/fonts/local

.include "../../mk/bsd.pkg.mk"
