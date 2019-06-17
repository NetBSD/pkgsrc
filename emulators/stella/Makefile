# $NetBSD: Makefile,v 1.49 2019/06/17 13:51:08 nia Exp $

STELLA_VERSION=	6.0.1
PKGNAME=	stella-${STELLA_VERSION}
DISTNAME=	stella-${STELLA_VERSION}-src
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=stella-emu/}
GITHUB_RELEASE=	${STELLA_VERSION}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stella-emu.github.io/
COMMENT=	Multi-platform Atari 2600 VCS emulator
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++14
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}

# c++14
GCC_REQD+=	5

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
