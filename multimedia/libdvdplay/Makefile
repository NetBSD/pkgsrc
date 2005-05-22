# $NetBSD: Makefile,v 1.6 2005/05/22 20:08:20 jlam Exp $

DISTNAME=	libdvdplay-1.0.1
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://developers.videolan.org/libdvdplay/
COMMENT=	Simple API library designed for DVD navigation

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
