# $NetBSD: Makefile,v 1.5 2026/08/04 20:28:54 wiz Exp $

DISTNAME=	libretro-snes9x2005-20180626
CATEGORIES=	emulators
GITHUB_PROJECT=	snes9x2005
GITHUB_TAG=	4423de5973de2e1a243031ee59d997f5e6220a6c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/snes9x_2005/
COMMENT=	Libretro core based on the snes9x Super Nintendo emulator
LICENSE=	snes9x-license

LIBRETRO_CORE=	snes9x2005

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
