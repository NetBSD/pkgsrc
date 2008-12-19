# $NetBSD: Makefile,v 1.1.1.1 2008/12/19 04:27:42 jmcneill Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-alsa/}

COMMENT+=	(OSS plugin)

CONFIGURE_ARGS=		--enable-alsa09
BUILD_DIRS=		${WRKSRC}/src/plugins/alsa09
INSTALL_DIRS=		${WRKSRC}/src/plugins/alsa09

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
