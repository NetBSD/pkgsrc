# $NetBSD: Makefile,v 1.5 2005/02/22 20:16:50 abs Exp $
#

.include "../../multimedia/libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	3
COMMENT=	Standalone open source Flash(tm) player

USE_BUILDLINK3=	yes
BUILD_DIRS=	${WRKSRC}/Player
CPPFLAGS+=	-DDEV_DSP="\"${DEVOSSSOUND}\""

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
MAKE_ENV+=	LIBSTDCPP=-lstdc++
.else
MAKE_ENV+=	LIBSTDCPP=
.endif

.include "../../multimedia/libflash/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
