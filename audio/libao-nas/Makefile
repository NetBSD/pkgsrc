# $NetBSD: Makefile,v 1.2 2012/02/15 21:50:17 hans Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-nas/}

COMMENT+=	(nas plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-nas/enable-nas/g}
BUILD_DIRS=		src/plugins/nas
INSTALL_DIRS=		src/plugins/nas

LIBS.SunOS+=	-lm

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../x11/libXau/buildlink3.mk"
.include "../../audio/nas/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
