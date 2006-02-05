# $NetBSD: Makefile,v 1.7 2006/02/05 23:10:15 joerg Exp $
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
.include "../../mk/bsd.pkg.mk"
