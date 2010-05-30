# $NetBSD: Makefile,v 1.2 2010/05/30 11:25:44 joerg Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-alsa/}

COMMENT+=	(OSS plugin)

CONFIGURE_ARGS=		--enable-alsa
BUILD_DIRS=		${WRKSRC}/src/plugins/alsa
INSTALL_DIRS=		${WRKSRC}/src/plugins/alsa

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
