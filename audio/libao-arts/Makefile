# $NetBSD: Makefile,v 1.16 2006/02/05 23:08:10 joerg Exp $

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
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
