# $NetBSD: Makefile,v 1.9 2003/07/21 16:51:39 martti Exp $
#

.include "../libflash/Makefile.common"

PKGNAME=	${DISTNAME:C/-/player-/}
PKGREVISION=	2
COMMENT=	Standalone open source Flash(tm) player

USE_BUILDLINK2=	yes
BUILD_DIRS=	${WRKSRC}/Player
CPPFLAGS+=	-DDEV_DSP=\\\"${DEVOSSSOUND}\\\"

.include "../libflash/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
