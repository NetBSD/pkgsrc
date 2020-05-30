# $NetBSD: Makefile,v 1.4 2020/05/30 15:56:22 nia Exp $

DISTNAME=	libretro-fuse-20200506
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	fuse-libretro
GITHUB_TAG=	c2f03e6f08f3e2a03d7888fe756e0beb7979f983

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/fuse/
COMMENT=	Libretro core based on the FUSE ZX Spectrum emulator
LICENSE=	gnu-gpl-v3

LIBRETRO_CORE=	fuse

LDFLAGS+=	-lz

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=build/link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

# Not used by the libretro build system
CHECK_PORTABILITY_SKIP+=	fuse/configure

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
