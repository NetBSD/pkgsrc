# $NetBSD: Makefile,v 1.1 2021/04/09 11:00:28 nia Exp $

DISTNAME=	kissfft-131.1.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=mborgerding/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mborgerding/kissfft
COMMENT=	Simple mixed-radix Fast Fourier Transform
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DKISSFFT_TEST=OFF

PKGCONFIG_OVERRIDE+=	kissfft.pc.in
PKGCONFIG_OVERRIDE+=	kissfft-float.pc

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
