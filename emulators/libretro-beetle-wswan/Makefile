# $NetBSD: Makefile,v 1.5 2020/05/31 08:17:36 nia Exp $

DISTNAME=	libretro-beetle-wswan-20200518
CATEGORIES=	emulators
GITHUB_PROJECT=	beetle-wswan-libretro
GITHUB_TAG=	29acc9d01bb475479096885afc4e12bb40dda8e4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/beetle_cygne/
COMMENT=	Libretro core based on the Mednafen Wonderswan emulator
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

LIBRETRO_CORE=	mednafen_wswan

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
