# $NetBSD: Makefile,v 1.32 2023/05/06 19:09:00 ryoon Exp $

PKGREVISION= 11
.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-pulse/}

COMMENT+=	(PulseAudio plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-pulse/enable-pulse/g}
BUILD_DIRS=		src/plugins/pulse
INSTALL_DIRS=		src/plugins/pulse

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
