# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:41 tv Exp $

DISTNAME=	libdvdplay-1.0.1
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://developers.videolan.org/libdvdplay/
COMMENT=	Simple API library designed for DVD navigation

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
