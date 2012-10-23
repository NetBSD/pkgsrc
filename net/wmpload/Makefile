# $NetBSD: Makefile,v 1.16 2012/10/23 17:19:20 asau Exp $
#

DISTNAME=	wmpload-0.9.5
PKGREVISION=	1
CATEGORIES=	net x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=system/network/serial/ppp/}

MAINTAINER=	abs@NetBSD.org
#HOMEPAGE=	http://www.engr.utk.edu/~mdsmith/pload/
COMMENT=	PPP monitor for X11, totals and current in/out rates in 64x64 cube

HAS_CONFIGURE=	YES
USE_IMAKE=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
