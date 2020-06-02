# $NetBSD: Makefile,v 1.1 2020/06/02 13:26:27 nia Exp $

LIBRETRO_CORE=	gearsystem

.include "../../emulators/gearsystem/Makefile.common"
.include "../../emulators/retroarch/core.mk"

PKGNAME=	libretro-${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/gearsystem/
COMMENT=	Libretro core based on the Gearsystem Master System emlator
LICENSE=	gnu-gpl-v3

BUILD_DIRS=	platforms/libretro

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-version-script=./link.T

.include "../../mk/bsd.pkg.mk"
