# $NetBSD: Makefile,v 1.5 2005/02/28 02:21:20 kim Exp $
#

DISTNAME=	libshout-2.1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.gnu.org/directory/audio/ogg/libshout.html
COMMENT=	Connects and sends data to icecast servers

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-pkgconfig

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
