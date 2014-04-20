# $NetBSD: Makefile,v 1.13 2014/04/20 02:27:50 ryoon Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-pulse/}
PKGREVISION=	2

COMMENT+=	(pulse plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-pulse/enable-pulse/g}
BUILD_DIRS=		src/plugins/pulse
INSTALL_DIRS=		src/plugins/pulse

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
