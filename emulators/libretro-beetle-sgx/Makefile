# $NetBSD: Makefile,v 1.4 2020/05/31 08:44:57 nia Exp $

DISTNAME=	libretro-beetle-sgx-20200520
CATEGORIES=	emulators
GITHUB_PROJECT=	beetle-supergrafx-libretro
GITHUB_TAG=	49c87096495438021a32c1bd1abd59b6a8b61ce9

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_sgx/
COMMENT=	Libretro core based on the Mednafen SuperGrafx emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
LIBRETRO_CORE=	mednafen_supergrafx

LDFLAGS+=	-lz -lFLAC

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

.include "../../emulators/retroarch/core.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
