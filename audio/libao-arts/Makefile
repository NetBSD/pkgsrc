# $NetBSD: Makefile,v 1.2 2003/04/22 19:23:55 jmc Exp $
#

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-arts/}

MAINTAINER=	packages@netbsd.org
COMMENT+=	(arts plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-arts/enable-arts/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/arts
INSTALL_DIRS=		${WRKSRC}/src/plugins/arts
USE_X11=		YES

.include "../../audio/arts/buildlink2.mk"
.include "../../audio/libao/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
