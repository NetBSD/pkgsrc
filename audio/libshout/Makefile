# $NetBSD: Makefile,v 1.4 2004/10/03 00:13:07 tv Exp $
#

DISTNAME=	libshout-2.0
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://icecast.org/files/libshout/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.gnu.org/directory/audio/ogg/libshout.html
COMMENT=	Connects and sends data to icecast servers

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-pkgconfig

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
