# $NetBSD: Makefile,v 1.2 2003/06/02 01:21:37 jschauma Exp $
#

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-esound/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT+=	(esound plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-esd/enable-esd/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/esd
INSTALL_DIRS=		${WRKSRC}/src/plugins/esd

.include "../../audio/esound/buildlink2.mk"
.include "../../audio/libao/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
