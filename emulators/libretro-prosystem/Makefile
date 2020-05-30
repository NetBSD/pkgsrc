# $NetBSD: Makefile,v 1.4 2020/05/30 15:22:02 nia Exp $

DISTNAME=	libretro-prosystem-20180812
CATEGORIES=	emulators
GITHUB_PROJECT=	prosystem-libretro
GITHUB_TAG=	463dfff97f2e7d707ee5ae238cb2e8e70beb585a

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/prosystem/
COMMENT=	Libretro core based on the ProSystem Atari 7800 emulator
LICENSE=	gnu-gpl-v2

LIBRETRO_CORE=	prosystem

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
