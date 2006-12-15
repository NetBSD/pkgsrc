# $NetBSD: Makefile,v 1.12 2006/12/15 20:33:00 joerg Exp $
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

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
