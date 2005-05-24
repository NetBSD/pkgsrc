# $NetBSD: Makefile,v 1.2 2005/05/24 15:57:19 jmmv Exp $

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-sun/}

COMMENT+=	(Sun audio plugin)

ONLY_FOR_PLATFORM+=	NetBSD-*-* SunOS-*-*

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/ENABLE_SUN_AUDIO=no/ENABLE_SUN_AUDIO=yes/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/sun
INSTALL_DIRS=		${WRKSRC}/src/plugins/sun

BUILDLINK_DEPENDS.libao+=	libao>=0.8.6nb1

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
