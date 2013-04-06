# $NetBSD: Makefile,v 1.9 2013/04/06 15:46:34 rodent Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-pulse/}
PKGREVISION=	7

COMMENT+=	(pulse plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-pulse/enable-pulse/g}
BUILD_DIRS=		src/plugins/pulse
INSTALL_DIRS=		src/plugins/pulse

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
