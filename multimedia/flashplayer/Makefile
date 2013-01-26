# $NetBSD: Makefile,v 1.14 2013/01/26 21:38:24 adam Exp $
#

.include "../../multimedia/libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	7
COMMENT=	Standalone open source Flash(tm) player

BUILD_DIRS=	${WRKSRC}/Player
CPPFLAGS+=	-DDEV_DSP="\"${DEVOSSSOUND}\""

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-3.*)
MAKE_ENV+=	LIBSTDCPP=-lstdc++
.else
MAKE_ENV+=	LIBSTDCPP=
.endif

INSTALLATION_DIRS+=	bin

.include "../../multimedia/libflash/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
