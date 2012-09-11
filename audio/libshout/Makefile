# $NetBSD: Makefile,v 1.11 2012/09/12 00:24:44 asau Exp $
#

DISTNAME=	libshout-2.2.2
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://directory.fsf.org/audio/ogg/libshout.html
COMMENT=	Connects and sends data to icecast servers

USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require
USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		YES

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
