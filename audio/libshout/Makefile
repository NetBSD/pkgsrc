# $NetBSD: Makefile,v 1.8 2008/07/14 12:55:57 joerg Exp $
#

DISTNAME=	libshout-2.1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://directory.fsf.org/audio/ogg/libshout.html
COMMENT=	Connects and sends data to icecast servers

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-pkgconfig

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
