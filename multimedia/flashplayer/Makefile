# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 13:36:18 jmmv Exp $
#

.include "../../multimedia/libflash/Makefile.common"

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

.include "../../multimedia/libflash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
