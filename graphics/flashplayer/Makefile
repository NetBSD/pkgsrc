# $NetBSD: Makefile,v 1.8 2003/01/30 12:22:45 jlam Exp $
#

.include "../libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	2
COMMENT=	standalone open source Flash(tm) player

USE_BUILDLINK2=	yes
BUILD_DIRS=	${WRKSRC}/Player
CPPFLAGS+=	-DDEV_DSP=\\\"${DEVOSSSOUND}\\\"

.include "../libflash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
