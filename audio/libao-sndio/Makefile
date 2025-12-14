# $NetBSD: Makefile,v 1.1 2025/12/14 12:56:26 vins Exp $

.include "../../audio/libao/Makefile.common"

PKGNAME=	${DISTNAME:S/libao/libao-sndio/}

COMMENT+=	(Sndio plugin)

CONFIGURE_ENV:=		${CONFIGURE_ENV:S/ac_cv_header_sndio_h=no//1}
BUILD_DIRS=		src/plugins/sndio
INSTALL_DIRS=		src/plugins/sndio

_LIBAO_BUILDING_PLUGIN=	yes

.include "../../audio/sndio/buildlink3.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
