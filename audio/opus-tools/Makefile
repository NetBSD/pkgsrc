# $NetBSD: Makefile,v 1.9 2020/04/20 17:39:13 nia Exp $

DISTNAME=	opus-tools-0.2
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	Opus encode, inspect, and decode command-line tools
LICENSE=	2-clause-bsd AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf pkg-config

.include "../../mk/oss.buildlink3.mk"
.if exists(/usr/include/sys/audioio.h) || ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=	ac_cv_header_soundcard_h=no
CONFIGURE_ENV+=	ac_cv_header_sys_soundcard_h=no
CONFIGURE_ENV+=	ac_cv_header_machine_soundcard_h=no
.elif ${OSS_TYPE} != "none"
LDFLAGS+=	${LIBOSSAUDIO}
.endif

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libopusenc/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
