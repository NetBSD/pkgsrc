# $NetBSD: Makefile,v 1.15 2013/04/06 15:46:37 rodent Exp $
#

.include "../../multimedia/libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	7
COMMENT=	Standalone open source Flash(tm) player

BUILD_DIRS=	Player
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
