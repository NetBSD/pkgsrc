# $NetBSD: Makefile,v 1.4 2020/05/31 08:29:17 nia Exp $

DISTNAME=	libretro-beetle-vb-20200518
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	beetle-vb-libretro
GITHUB_TAG=	005c4c8b5dbecc2dfecf81b61ecb497ee05c52cf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_vb/
COMMENT=	Libretro core based on the Mednafen VirtualBoy emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

LIBRETRO_CORE=	mednafen_vb

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
