# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:45 jlam Exp $

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
USE_BUILDLINK2=	yes

.include "../../multimedia/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
