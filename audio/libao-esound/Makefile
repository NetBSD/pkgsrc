# $NetBSD: Makefile,v 1.16 2019/11/24 00:35:56 nia Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-esound/}

COMMENT+=	(ESD plugin)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/disable-esd/enable-esd/g}
BUILD_DIRS=		src/plugins/esd
INSTALL_DIRS=		src/plugins/esd

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
