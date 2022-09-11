# $NetBSD: Makefile,v 1.62 2022/09/11 12:51:35 wiz Exp $

PKGREVISION= 2
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
