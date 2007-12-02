# $NetBSD: Makefile,v 1.9 2007/12/02 13:04:12 wiz Exp $

DISTNAME=	libdvdplay-1.0.1
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.videolan.org/developers/libdvdplay.html
COMMENT=	Simple API library designed for DVD navigation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
