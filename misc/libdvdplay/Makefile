# $NetBSD: Makefile,v 1.1.1.1 2003/08/05 03:34:27 wulf Exp $

DISTNAME=	libdvdplay-1.0.1
CATEGORIES=	misc
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://developers.videolan.org/libdvdplay/
COMMENT=	simple API library designed for DVD navigation

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK2=	yes

.include "../../misc/libdvdread/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
