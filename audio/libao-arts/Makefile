# $NetBSD: Makefile,v 1.20 2012/01/13 10:54:46 obache Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-arts/}
PKGREVISION=	2

COMMENT+=	(arts plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-arts/enable-arts/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/arts
INSTALL_DIRS=		${WRKSRC}/src/plugins/arts

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
