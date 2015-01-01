# $NetBSD: Makefile,v 1.9 2015/01/01 08:15:51 dholland Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-sun/}

COMMENT+=	(Sun audio plugin)

# no support for the sun audio interface
NOT_FOR_PLATFORM+=	DragonFly-*-* FreeBSD-*-* Linux-*-*

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/ENABLE_SUN_AUDIO=no/ENABLE_SUN_AUDIO=yes/g}
BUILD_DIRS=		src/plugins/sun
INSTALL_DIRS=		src/plugins/sun

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
