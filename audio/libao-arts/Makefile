# $NetBSD: Makefile,v 1.12 2005/06/01 18:02:38 jlam Exp $

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-arts/}

COMMENT+=	(arts plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-arts/enable-arts/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/arts
INSTALL_DIRS=		${WRKSRC}/src/plugins/arts

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
