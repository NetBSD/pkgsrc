# $NetBSD: Makefile,v 1.13 2020/06/05 10:08:36 nia Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-sun/}
PKGREVISION=	2

COMMENT+=	(Sun audio plugin)

# no support for the sun audio interface
NOT_FOR_PLATFORM+=	Darwin-*-* DragonFly-*-* FreeBSD-*-* Linux-*-*

CONFIGURE_ENV:=		${CONFIGURE_ENV:S/ac_cv_header_sys_audioio_h=no//1}
BUILD_DIRS=		src/plugins/sun
INSTALL_DIRS=		src/plugins/sun

BUILDLINK_API_DEPENDS.libao+=	libao>=0.8.6nb1

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
