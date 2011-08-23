# $NetBSD: Makefile,v 1.3 2011/08/23 13:06:46 obache Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-pulse/}
PKGREVISION=	2

COMMENT+=	(pulse plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-pulse/enable-pulse/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/pulse
INSTALL_DIRS=		${WRKSRC}/src/plugins/pulse

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
