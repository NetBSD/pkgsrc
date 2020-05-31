# $NetBSD: Makefile,v 1.3 2020/05/31 16:33:06 nia Exp $

DISTNAME=	libretro-2048-20181229
CATEGORIES=	games
GITHUB_PROJECT=	libretro-2048
GITHUB_TAG=	bc05dc6e504e78fd4eaf7bf91f5b3f84a93c2962

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/2048/
COMMENT=	Libretro core based on the 2048 puzzle game
LICENSE=	unlicense

MAKE_FILE=	Makefile.libretro

LIBRETRO_CORE=	2048

CHECK_PORTABILITY_SKIP+=	pixman/configure

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
