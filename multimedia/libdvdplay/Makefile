# $NetBSD: Makefile,v 1.10 2011/02/28 14:52:57 wiz Exp $

DISTNAME=	libdvdplay-1.0.1
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvdplay/1.0.1/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/developers/libdvdplay.html
COMMENT=	Simple API library designed for DVD navigation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
