# $NetBSD: Makefile,v 1.1.1.1 2003/04/11 19:14:26 jmmv Exp $
#

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-arts/}

MAINTAINER=	packages@netbsd.org
COMMENT+=	(arts plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-arts/enable-arts/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/arts
INSTALL_DIRS=		${WRKSRC}/src/plugins/arts

.include "../../audio/arts/buildlink2.mk"
.include "../../audio/libao/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
