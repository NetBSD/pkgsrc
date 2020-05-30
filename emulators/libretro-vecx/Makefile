# $NetBSD: Makefile,v 1.4 2020/05/30 16:07:58 nia Exp $

DISTNAME=	libretro-vecx-20200517
CATEGORIES=	emulators
GITHUB_TAG=	2a2e9291fd3733e714f9f8bf5e624325c7756960

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docs.libretro.com/library/vecx/
COMMENT=	Libretro core for Vectrex emulation
LICENSE=	gnu-gpl-v3

LIBRETRO_CORE=	vecx

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=./link.T

.include "../../emulators/retroarch/core.mk"
.include "../../mk/bsd.pkg.mk"
