# $NetBSD: Makefile,v 1.11 2012/10/08 09:21:06 asau Exp $

DISTNAME=	libdvdplay-1.0.1
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/developers/libdvdplay.html
COMMENT=	Simple API library designed for DVD navigation

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
