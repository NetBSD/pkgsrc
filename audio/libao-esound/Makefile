# $NetBSD: Makefile,v 1.6 2004/04/22 12:29:35 wiz Exp $
#

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-esound/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT+=	(esound plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-esd/enable-esd/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/esd
INSTALL_DIRS=		${WRKSRC}/src/plugins/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
