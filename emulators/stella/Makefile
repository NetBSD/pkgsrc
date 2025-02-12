# $NetBSD: Makefile,v 1.67 2025/02/12 06:44:47 ryoon Exp $

PKGREVISION= 7
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/-src//1}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stella-emu.github.io/
COMMENT=	Multi-platform Atari 2600 VCS emulator

USE_TOOLS+=	gmake

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
