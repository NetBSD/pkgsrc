# $NetBSD: Makefile,v 1.3 2004/03/18 23:29:36 xtraeme Exp $

DISTNAME=	libdvdplay-1.0.1
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://developers.videolan.org/libdvdplay/
COMMENT=	Simple API library designed for DVD navigation

GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
