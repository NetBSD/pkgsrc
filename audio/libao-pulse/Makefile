# $NetBSD: Makefile,v 1.1.1.1 2008/12/18 16:36:52 jmcneill Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-pulse/}

COMMENT+=	(pulse plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-pulse/enable-pulse/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/pulse
INSTALL_DIRS=		${WRKSRC}/src/plugins/pulse

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
