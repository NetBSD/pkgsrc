# $NetBSD: Makefile,v 1.14 2013/04/06 15:46:33 rodent Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-esound/}
PKGREVISION=	1

COMMENT+=	(esound plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-esd/enable-esd/g}
BUILD_DIRS=		src/plugins/esd
INSTALL_DIRS=		src/plugins/esd

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
