# $NetBSD: Makefile,v 1.10 2003/09/28 20:05:20 tron Exp $
#

.include "../libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	2
COMMENT=	Standalone open source Flash(tm) player

USE_BUILDLINK2=	yes
BUILD_DIRS=	${WRKSRC}/Player
CPPFLAGS+=	-DDEV_DSP=\\\"${DEVOSSSOUND}\\\"

.if defined(CC_VERSION) && !empty(CC_VERSION:Mgcc-3.*)
MAKE_ENV+=	LIBSTDCPP=-lstdc++
.else
MAKE_ENV+=	LIBSTDCPP=
.endif

.include "../libflash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
