# $NetBSD: Makefile,v 1.11 2004/11/16 14:49:41 adam Exp $

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-arts/}

COMMENT+=	(arts plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-arts/enable-arts/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/arts
INSTALL_DIRS=		${WRKSRC}/src/plugins/arts
USE_X11=		YES

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
