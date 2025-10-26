# $NetBSD: Makefile,v 1.24 2025/10/26 12:06:41 ryoon Exp $

DISTNAME=	libshout-2.4.6
PKGREVISION=	2
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

CPPFLAGS.NetBSD+=	-D_NETBSD_SOURCE # for strcasestr(3)

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
