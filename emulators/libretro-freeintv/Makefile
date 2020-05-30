# $NetBSD: Makefile,v 1.5 2020/05/30 14:37:33 nia Exp $

DISTNAME=	libretro-freeintv-20200421
CATEGORIES=	emulators
GITHUB_PROJECT=	FreeIntv
GITHUB_TAG=	68322b4ab4a93f82a934fb4f7469247270b4f731

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/freeintv/
COMMENT=	Libretro core for Mattel Intellivision emulation
LICENSE=	gnu-gpl-v3

LIBRETRO_CORE=	freeintv

USE_LANGUAGES=	c c++

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
