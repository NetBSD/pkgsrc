# $NetBSD: Makefile,v 1.48 2017/09/04 09:24:26 wiz Exp $

STELLA_VERSION=	4.7.3
DISTNAME=	stella-${STELLA_VERSION}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=stella-emu/}
GITHUB_TAG=	release-${STELLA_VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://stella-emu.github.io/
COMMENT=	Multi-platform Atari 2600 VCS emulator
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGBASE}-release-${PKGVERSION_NOREV}
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	3.0
.endif

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
