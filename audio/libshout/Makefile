# $NetBSD: Makefile,v 1.15 2019/06/11 08:49:28 wiz Exp $

DISTNAME=	libshout-2.4.3
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://directory.fsf.org/audio/ogg/libshout.html
COMMENT=	Connects and sends data to icecast servers
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		YES
PTHREAD_OPTS+=		require
USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE=	shout.pc.in

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
