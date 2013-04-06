# $NetBSD: Makefile,v 1.25 2013/04/06 15:46:33 rodent Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-arts/}
PKGREVISION=	6

COMMENT+=	(arts plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-arts/enable-arts/g}
BUILD_DIRS=		src/plugins/arts
INSTALL_DIRS=		src/plugins/arts

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
