# $NetBSD: Makefile,v 1.13 2020/05/22 12:43:52 adam Exp $

DISTNAME=	libdvdplay-1.0.1
PKGREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/developers/libdvdplay.html
COMMENT=	Simple API library designed for DVD navigation

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
