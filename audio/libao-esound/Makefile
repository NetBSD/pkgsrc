# $NetBSD: Makefile,v 1.8 2004/11/16 14:49:52 adam Exp $

.include "../libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-esound/}

COMMENT+=	(esound plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-esd/enable-esd/g}
BUILD_DIRS=		${WRKSRC}/src/plugins/esd
INSTALL_DIRS=		${WRKSRC}/src/plugins/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
