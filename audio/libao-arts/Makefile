# $NetBSD: Makefile,v 1.4 2003/06/02 01:21:37 jschauma Exp $
#

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-arts/}
PKGREVISION=	1

MAINTAINER=	tech-pkg@netbsd.org
COMMENT+=	(arts plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-arts/enable-arts/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/arts
INSTALL_DIRS=		${WRKSRC}/src/plugins/arts
USE_X11=		YES

.include "../../audio/arts/buildlink2.mk"
.include "../../audio/libao/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
