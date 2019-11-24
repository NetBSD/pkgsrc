# $NetBSD: Makefile,v 1.4 2019/11/24 00:35:56 nia Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-alsa/}

COMMENT+=	(ALSA plugin)

CONFIGURE_ARGS=		--enable-alsa
BUILD_DIRS=		src/plugins/alsa
INSTALL_DIRS=		src/plugins/alsa

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
