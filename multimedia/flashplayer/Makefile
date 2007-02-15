# $NetBSD: Makefile,v 1.8 2007/02/15 14:50:29 joerg Exp $
#

.include "../../multimedia/libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	4
COMMENT=	Standalone open source Flash(tm) player

BUILD_DIRS=	${WRKSRC}/Player
CPPFLAGS+=	-DDEV_DSP="\"${DEVOSSSOUND}\""

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
MAKE_ENV+=	LIBSTDCPP=-lstdc++
.else
MAKE_ENV+=	LIBSTDCPP=
.endif

.include "../../multimedia/libflash/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
