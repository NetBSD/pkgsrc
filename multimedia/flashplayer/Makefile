# $NetBSD: Makefile,v 1.2 2004/02/18 13:33:41 jlam Exp $
#

.include "../../multimedia/libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	2
COMMENT=	Standalone open source Flash(tm) player

USE_BUILDLINK2=	yes
BUILD_DIRS=	${WRKSRC}/Player
CPPFLAGS+=	-DDEV_DSP=\\\"${DEVOSSSOUND}\\\"

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
MAKE_ENV+=	LIBSTDCPP=-lstdc++
.else
MAKE_ENV+=	LIBSTDCPP=
.endif

.include "../../multimedia/libflash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
