# $NetBSD: Makefile,v 1.20 2021/01/04 11:09:33 wiz Exp $

DISTNAME=	libshout-2.4.5
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
