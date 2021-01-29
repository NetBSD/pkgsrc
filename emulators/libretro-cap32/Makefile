# $NetBSD: Makefile,v 1.6 2021/01/29 09:20:23 nia Exp $

DISTNAME=	libretro-cap32-20200508
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_TAG=	2fe00cafcfcd8dd4f0fcdcbd1f5e2cc1c0669e43

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/caprice32/
COMMENT=	Libretro core based on the Caprice32 Amstrad CPC emulator
LICENSE=	gnu-gpl-v2

# error: 'for' loop initial declarations are only allowed in C99 mode
USE_LANGUAGES=	c99

LIBRETRO_CORE=	cap32

LDFLAGS+=	-lz

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

.include "../../emulators/retroarch/core.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
