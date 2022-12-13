# $NetBSD: Makefile,v 1.5 2022/12/13 10:48:27 jperkin Exp $

DISTNAME=	libretro-virtualjaguar-20200521
CATEGORIES=	emulators
GITHUB_PROJECT=	virtualjaguar-libretro
GITHUB_TAG=	5a293de747823dc0a9ceba0dd878ef75e9a9d920

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/virtual_jaguar/
COMMENT=	Libretro core based on the Virtual Jaguar emulator
LICENSE=	gnu-gpl-v3

LIBRETRO_CORE=	virtualjaguar

# We can't remove the arg as it is space-separated ("-z .."), so instead
# rewrite it to something that is already used.
BUILDLINK_TRANSFORM.SunOS+=	opt:gnu-version-script-compat:defs

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
