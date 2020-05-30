# $NetBSD: Makefile,v 1.5 2020/05/30 14:43:10 nia Exp $

DISTNAME=	libretro-o2em-20200522
CATEGORIES=	emulators
GITHUB_TAG=	31a60bb551e9d72b66dab0c373a61e185cd25459

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/o2em/
COMMENT=	Libretro core for Magnavox Odyssey 2 and VideoPac emulation
LICENSE=	artistic

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

LIBRETRO_CORE=	o2em

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
