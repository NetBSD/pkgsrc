# $NetBSD: Makefile,v 1.7 2023/08/02 19:21:51 nia Exp $

DISTNAME=	libretro-vba-next-20200106
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=libretro/}
GITHUB_PROJECT=	vba-next
GITHUB_TAG=	019132daf41e33a9529036b8728891a221a8ce2e

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/vba_next/
COMMENT=	Libretro core based on the VBA Next Game Boy Advance emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

LIBRETRO_CORE=	vba_next

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=./libretro/link.T
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-no-undefined

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
